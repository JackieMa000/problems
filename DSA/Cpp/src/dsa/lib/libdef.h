#ifndef DSA_SRC_DSA_LIB_LIBDEF_H_
#define DSA_SRC_DSA_LIB_LIBDEF_H_

#include <dsa/dsadef.h>
#include <dsa/nodes/nodes.h>

// Array Length
#define arylen(ary) sizeof(ary)/sizeof(ary[0])

namespace dsa::lib {

typedef nodes::BinaryTreeNode BinaryTreeNode;
typedef nodes::ListNode ListNode;
}

#endif //DSA_SRC_DSA_LIB_LIBDEF_H_
