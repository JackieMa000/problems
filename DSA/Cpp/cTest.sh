cd /Users/Jackie/Dev/DSA/problems/DSA/Cpp/cmake-build-debug-coverage

#### Build All Targets ###
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build /Users/Jackie/Dev/DSA/problems/DSA/Cpp/cmake-build-debug-coverage --target all


###### Run CTest   #####
/usr/local/bin/ctest -j6 -C Debug -T test --output-on-failure
