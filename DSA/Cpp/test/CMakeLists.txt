add_subdirectory(lib)
add_subdirectory(testing)

# Add cTest
add_test(NAME utils_test COMMAND utils_test)
add_test(NAME arrays_test COMMAND arrays_test)

