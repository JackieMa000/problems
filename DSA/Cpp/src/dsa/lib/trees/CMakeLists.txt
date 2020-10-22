add_library(trees
        bt.cpp
        bst.cpp)
target_link_libraries(trees PRIVATE
        utils)

target_precompile_headers(trees PRIVATE pch.h)