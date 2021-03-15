cd /Users/Jackie/Dev/DSA/problems/DSA/Cpp/cmake-build-debug

#### Build All Targets ###
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build /Users/jackie/Dev/DSA/problems/DSA/Cpp/cmake-build-debug --target all -- -j 8

###### Run CTest   #####
/opt/homebrew/bin/ctest -j8 -C Debug -T test --output-on-failure
