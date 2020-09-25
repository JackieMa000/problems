#ifndef LIB_LISTS_ARRAYLIST_H
#define LIB_LISTS_ARRAYLIST_H

#include "dsa/lib/lists/list.h"

namespace dsa::lib::lists {

class ArrayList : List {
 private:
    static const length_t DEFAULT_LENGTH = 10;
    const int *lst;

 public:
    ArrayList();
    explicit ArrayList(const int ary[]);
    ~ArrayList();

    length_t length() override;
};

}  // namespace dsa

#endif