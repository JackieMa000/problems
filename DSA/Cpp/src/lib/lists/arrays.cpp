#include "nodes.h"
#include "lib/lists/arrays.h"

namespace dsa
{
    namespace lib
    {
        Array::Array(int array[]) { this->array = array; };
        Array::~Array() { delete[] array; }

        ArrayList::ArrayList()
        {
            int array[DEFAULT_LENGTH];
            this->lst = array;
        };
        ArrayList::ArrayList(int array[]) { this->lst = array; };
        ArrayList::~ArrayList() { delete[] lst; }

    } // namespace lib
} // namespace dsa