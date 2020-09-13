#include "dsa/lib/lists/list.h"

#ifndef LIB_LISTS_ARRAYLIST_H
#define LIB_LISTS_ARRAYLIST_H

namespace dsa
{
    namespace lib
    {
        class ArrayList : List
        {
        private:
            static const int DEFAULT_LENGTH = 10;
            const int *lst;

        public:
            ArrayList();
            ArrayList(int ary[]);
            ~ArrayList();

            int size();
        };

    } // namespace lib
} // namespace dsa

#endif