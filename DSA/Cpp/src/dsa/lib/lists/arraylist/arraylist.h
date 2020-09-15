#include "dsa/lib/lists/list.h"

#ifndef LIB_LISTS_ARRAYLIST_H
#define LIB_LISTS_ARRAYLIST_H

namespace dsa {
namespace lib {
namespace lists {

class ArrayList : List
{
private:
    static const int DEFAULT_LENGTH = 10;
    const int* lst;

public:
    ArrayList();
    ArrayList(int ary[]);
    ~ArrayList();

    unsigned int
    size();
};

}  // namespace lists
}  // namespace lib
}  // namespace dsa

#endif