set(Boost_INCLUDE_DIR /opt/homebrew/Cellar/boost/1.75.0_1/include)
set(Boost_LIBRARY_DIR /opt/homebrew/Cellar/boost/1.75.0_1/lib)
find_package(Boost 1.75.0)
include_directories(${Boost_INCLUDE_DIR})

if (NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif ()