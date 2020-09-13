#include "arraylist.h"

namespace dsa
{
    namespace lib
    {
        ArrayList::ArrayList()
        {
            int array[DEFAULT_LENGTH];
            this->lst = array;
        };
        ArrayList::ArrayList(int ary[]) { this->lst = ary; };
        ArrayList::~ArrayList() { delete[] lst; }

    } // namespace lib
} // namespace dsa