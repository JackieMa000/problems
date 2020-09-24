#ifndef DSA_TEST_DSA_LIB_LISTS_LIST_TEST_FX_H_
#define DSA_TEST_DSA_LIB_LISTS_LIST_TEST_FX_H_

#include <dsa/testing/testing.h>
#include "dsa/lib/lists/arrays/array.h"
#include "dsa/lib/lists/linkedlists/ls.h"

namespace dsa::lib::lists {

class ListTest : public testing::DSATest {
 protected:

    static void destroyLinkedList(nodes::ListNode *head) {
        linkedlists::LinkedList ls(head);
        ls.destroy(nullptr);
    }
};

}

#endif //DSA_TEST_DSA_LIB_LISTS_LIST_TEST_FX_H_
