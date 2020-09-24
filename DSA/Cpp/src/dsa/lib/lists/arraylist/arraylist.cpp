#include "arraylist.h"

namespace dsa {
namespace lib {
namespace lists {

ArrayList::ArrayList()
{
    int array[DEFAULT_LENGTH];
    this->lst = array;
};
ArrayList::ArrayList(int ary[])
{
    this->lst = ary;
};
ArrayList::~ArrayList() {
    delete[] lst;
}
length_t ArrayList::length() {
//    ToDo
    return 0;
}

}  // namespace lists
}  // namespace lib
}  // namespace dsa