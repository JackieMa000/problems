#ifndef DSA_CONTAINER_LISTS_LIST_H
#define DSA_CONTAINER_LISTS_LIST_H

#include <dsa/dsadef.h>
namespace dsa::lib::lists {

class List {
 public:
    virtual length_t length() = 0;
};

}  // namespace dsa::lib::lists

#endif