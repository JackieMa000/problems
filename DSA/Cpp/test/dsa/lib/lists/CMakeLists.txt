add_executable(arrays_test arrays_test.cpp)
target_link_libraries(arrays_test
nodes
arrays 
linkedlists
test_main)

add_executable(linkedlists_test linkedlists_test.cpp)
target_link_libraries(linkedlists_test
nodes
linkedlists
arrays
test_main)