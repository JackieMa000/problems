add_executable(algorithms_test
        strip_test.cpp
        )
target_link_libraries(algorithms_test
        test_main)
target_precompile_headers(algorithms_test PRIVATE pch.h)
