# Copyright 2000-2018 JetBrains s.r.o.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
from __future__ import (absolute_import, division, print_function)

import gdb


from libstdcxx.v6.printers import (Iterator,
                                   strip_versioned_namespace,
                                   is_specialization_of)


class SmartPtrIterator(Iterator):
    "An iterator for smart pointer types with a single 'child' value"

    def __init__(self, val, valtype):
        self.val = val
        self.valtype = valtype

    def __iter__(self):
        return self

    def __next__(self):
        if self.val is None:
            raise StopIteration
        self.val, val = None, self.val
        return ('get()', val.cast(self.valtype.pointer()))

class SharedPointerPrinter:
    "Print a shared_ptr or weak_ptr"

    def __init__ (self, typename, val):
        self.typename = strip_versioned_namespace(typename)
        self.val = val
        self.pointer = val['_M_ptr']

    def children (self):
        return SmartPtrIterator(self.pointer, self.val.type.template_argument(0))

    def to_string (self):
        state = 'empty'
        refcounts = self.val['_M_refcount']['_M_pi']
        if refcounts != 0:
            usecount = refcounts['_M_use_count']
            weakcount = refcounts['_M_weak_count']
            if usecount == 0:
                state = 'expired, weak count %d' % weakcount
            else:
                state = 'use count %d, weak count %d' % (usecount, weakcount - 1)
        return '%s<%s> (%s)' % (self.typename, str(self.val.type.template_argument(0)), state)

class UniquePointerPrinter:
    "Print a unique_ptr"

    def __init__ (self, typename, val):
        self.val = val
        impl_type = val.type.fields()[0].type.strip_typedefs().tag
        # Check for new implementations first:
        if is_specialization_of(impl_type, '__uniq_ptr_data') \
            or is_specialization_of(impl_type, '__uniq_ptr_impl'):
            tuple_member = val['_M_t']['_M_t']
        elif is_specialization_of(impl_type, 'tuple'):
            tuple_member = val['_M_t']
        else:
            raise ValueError("Unsupported implementation for unique_ptr: %s" % impl_type)
        tuple_impl_type = tuple_member.type.fields()[0].type # _Tuple_impl
        tuple_head_type = tuple_impl_type.fields()[1].type   # _Head_base
        head_field = tuple_head_type.fields()[0]
        if head_field.name == '_M_head_impl':
            self.pointer = tuple_member['_M_head_impl']
        elif head_field.is_base_class:
            self.pointer = tuple_member.cast(head_field.type)
        else:
            raise ValueError("Unsupported implementation for tuple in unique_ptr: %s" % impl_type)

    def children (self):
        return SmartPtrIterator(self.pointer, self.val.type.template_argument(0))

    def to_string (self):
        return ('std::unique_ptr<%s>' % (str(self.val.type.template_argument(0))))


# A hack around gcc8 child printing issues on Ubuntu (CPP-18972)
class StdPathPrinter:
    def __init__ (self, typename, val):
        self.val = val
        self.typename = typename
        try:
            impl = self.val['_M_cmpts']['_M_impl']['_M_t']['_M_t']['_M_head_impl']
            self.type = impl.cast(gdb.lookup_type('uintptr_t')) & 3
            if self.type == 0:
                self.impl = impl
            else:
                self.impl = None
        except gdb.error:
            self.gcc8_hack = True

    def to_string (self):
        path = "%s" % self.val ['_M_pathname']
        if not hasattr(self, 'gcc8_hack'):
            if self.type != 0:
                t = self._path_type()
                if t:
                    path = '%s [%s]' % (path, t)
        return "filesystem::path %s" % path

    def __getattribute__ (self, name):
        if name == 'children' and hasattr(self, 'gcc8_hack'):
            raise AttributeError(name)
        else:
            return object.__getattribute__(self, name)


def patch_libstdcxx_printers_module():
    from libstdcxx.v6 import printers

    def patch(target, new):
        target.__init__ = new.__init__
        target.children = new.children
        target.to_string = new.to_string
    patch(printers.SharedPointerPrinter, SharedPointerPrinter)
    patch(printers.UniquePointerPrinter, UniquePointerPrinter)

    printers.SmartPtrIterator.__init__ =  SmartPtrIterator.__init__
    printers.SmartPtrIterator.__iter__ =  SmartPtrIterator.__iter__
    printers.SmartPtrIterator.__next__ =  SmartPtrIterator.__next__

    if hasattr(printers, 'StdPathPrinter'):
        printers.StdPathPrinter.__init__ = StdPathPrinter.__init__
        printers.StdPathPrinter.__getattribute__ = StdPathPrinter.__getattribute__
        printers.StdPathPrinter.to_string = StdPathPrinter.to_string
