#include "testing.h"
#include "lib/lists/arrays.h"
#include "lib/lists/linkedlists.h"

namespace dsa
{
    namespace lib
    {
        namespace
        {
            class ArrayTest : public testing::DSATest
            {
            };

            class ToSinglyLinkedListTest : public ArrayTest
            {
            protected:
                nodes::ListNode *createSinglyLinkedList(int ary[], int length)
                {
                    Array array(ary, length);
                    return array.toSinglyLinkedList();
                }

                void destroySinglyLinkedList(nodes::ListNode *head)
                {
                    SinglyLinkedList ls(head);
                    ls.destroy();
                }

                void run(int ary[], int length)
                {
                    nodes::ListNode *actual = createSinglyLinkedList(ary, length);
                    EXPECT_ARRAY_EQ_LINKEDLIST(ary, length, actual);
                    destroySinglyLinkedList(actual);
                }
            };

            TEST_F(ArrayTest, case_array_eq)
            {
                int expected[] = {1, 2, 3}, actual[] = {1, 2, 3};
                EXPECT_ARRAY_EQ(expected, sizeof(expected) / 4, actual, sizeof(actual) / 4);
            }

            TEST_F(ToSinglyLinkedListTest, case1)
            {
                int ary[] = {1};
                run(ary, sizeof(ary) / 4);
            }

            TEST_F(ToSinglyLinkedListTest, case2)
            {
                int ary[] = {1, 2, 3};
                run(ary, sizeof(ary) / 4);
            }

        } // namespace
    }     // namespace lib
} // namespace dsa