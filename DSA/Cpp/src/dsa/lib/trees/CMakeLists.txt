add_library(trees
        bt.cpp
        bst.cpp)

pch_for_debug(trees PRIVATE pch.h)