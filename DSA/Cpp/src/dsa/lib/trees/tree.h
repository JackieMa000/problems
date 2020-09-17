#ifndef LIB_TREES_TREE_H
#define LIB_TREES_TREE_H

namespace dsa::lib::trees {

class Tree {
 public:
    virtual std::tuple<unsigned int, int *> toArray() = 0;
    virtual int depth() = 0;
};

}  // namespace dsa

#endif