#include "dsa/lib/lists/list.h"

#ifndef LIB_LISTS_ARRAYLIST_H
#define LIB_LISTS_ARRAYLIST_H

namespace dsa::lib::lists {

class ArrayList : List {
 private:
    static const int DEFAULT_LENGTH = 10;
    const int *lst;

 public:
    ArrayList();
    explicit ArrayList(int ary[]);
    ~ArrayList();

    length_t length() override;
};

}  // namespace dsa

#endif