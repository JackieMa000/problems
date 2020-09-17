#ifndef LIB_LISTS_LINKEDLISTS_LS_TEST_H
#define LIB_LISTS_LINKEDLISTS_LS_TEST_H

#include <dsa/lib/lists/list_test_fx.hpp>

namespace dsa::lib::lists::linkedlists {

class LinkedListTest : public ListTest {
};

class ToArrayTest : public LinkedListTest {
};

}  // namespace dsa::lib::lists::linkedlists

#endif