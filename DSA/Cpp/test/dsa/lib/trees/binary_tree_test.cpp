#include <dsa/lib/trees/bt.h>
#include <dsa/lib/lists/arrays/array.h>
#include "binary_tree_test.h"

namespace dsa::lib::trees {
namespace {

TEST_F(ToArrayTest, case1) {
//    Arrange;
//    int ary[] = {1, 2, 3};
    int ary[] = {3, 1, 5, 0, 2};
//    int ary[] = {5, 1, 4, 0, 6, 3, 6};
//    int len = sizeof(ary) / 4;
    lists::arrays::Array array(ary, sizeof(ary));

    nodes::BinaryTreeNode *root;
    root = array.toBinaryTree();

//    Act;
    BinaryTree bt(root);
    auto[actLen, actAry] = bt.toArray();

//    Assert;
//    EXPECT_ARRAY_EQ(ary, len, actAry, actLen);
}

TEST_F(DepthTest, case1) {
    int ary[] = {1};
    unsigned int actual = getTreeDepth(generateTreeFromArray(ary, sizeof(ary)));
    EXPECT_EQ(1, actual);
}

TEST_F(DepthTest, case2) {
    int ary[] = {1, 2, 3};
    unsigned int actual = getTreeDepth(generateTreeFromArray(ary, sizeof(ary)));
    EXPECT_EQ(2, actual);
}

TEST_F(DepthTest, case3) {
    int ary[] = {5, 1, 4, 0, 0, 3, 6};
    unsigned int actual = getTreeDepth(generateTreeFromArray(ary, sizeof(ary)));
    EXPECT_EQ(3, actual);
}

}
}