#ifndef LIB_TREES_TREE_H
#define LIB_TREES_TREE_H

namespace dsa {
namespace lib {
namespace trees {

class Tree
{
public:
    virtual int*
    toArray() = 0;
    virtual int
    depth() = 0;
};

}  // namespace trees
}  // namespace lib
}  // namespace dsa

#endif