add_subdirectory(arrays)
add_subdirectory(linkedlists)
add_subdirectory(arraylist)

add_custom_target(lists)
add_dependencies(lists 
arrays
linkedlists
arraylist
)