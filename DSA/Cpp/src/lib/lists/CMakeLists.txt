add_library(arrays arrays.cpp)
add_library(linkedlist linkedlist.cpp)
add_library(arraylist arraylist.cpp)

add_custom_target(lists)
add_dependencies(lists 
arrays
linkedlist
arraylist
)