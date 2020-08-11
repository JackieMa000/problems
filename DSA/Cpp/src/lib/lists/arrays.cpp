#include "nodes.h"
#include "lib/lists/arrays.h"

lib::Array::Array(int array[]) { this->array = array; };
lib::Array::~Array() { delete[] array; }

lib::ArrayList::ArrayList()
{
    int array[DEFAULT_LENGTH];
    this->lst = array;
};
lib::ArrayList::ArrayList(int array[]) { this->lst = array; };
lib::ArrayList::~ArrayList() { delete[] lst; }