#ifndef DSA_CONTAINER_LISTS_ARRAYLIST_H
#define DSA_CONTAINER_LISTS_ARRAYLIST_H

#include <dsa/container/lists/list.h>

namespace dsa::lib::lists {

class ArrayList : public List {
 private:
    static const length_t DEFAULT_LENGTH = 10;
    const int *lst;

 public:
    ArrayList();
    ~ArrayList();

    length_t length() override;
};

}  // namespace dsa

#endif