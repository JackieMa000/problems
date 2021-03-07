#ifndef LIB_TREES_TREE_H
#define LIB_TREES_TREE_H

#include <dsa/lib/libdef.h>
#include <dsa/nodes/nodes.h>

namespace dsa::lib::trees {

class Tree {
 public:
    virtual array_s toArray() = 0;
    virtual depth_t depth() = 0;
    virtual dsa::nodes::TreeNode *getNodeByIndex(pos_t idx) = 0;
    virtual dsa::nodes::TreeNode *getNodeByValue(int val) = 0;
};

}  // namespace dsa

#endif