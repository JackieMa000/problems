#ifndef LIB_TREES_TREE_H
#define LIB_TREES_TREE_H

#include <dsa/dsadef.h>

namespace dsa::lib::trees {

class Tree {
 public:
    virtual std::tuple<length_t, int *> toArray() = 0;
    virtual depth_t depth() = 0;
};

}  // namespace dsa

#endif