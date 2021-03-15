add_library(trees
        bt.cpp
        bst.cpp)

target_precompile_headers(trees PRIVATE pch.h)