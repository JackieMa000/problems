#!/usr/bin/env zsh

#### Build All Targets ###
/opt/homebrew/bin/cmake \
--build /Users/jackie/Dev/DSA/problems/DSA/Cpp/cmake-build-debug-llvm/ --target all -- -j 8

###### Run CTest   #####
cd /Users/Jackie/Dev/DSA/problems/DSA/Cpp/cmake-build-debug-llvm/
/opt/homebrew/bin/ctest -j8 -C Debug -T test --output-on-failure