find_package(Boost REQUIRED COMPONENTS
        thread)
include_directories(${Boost_INCLUDE_DIR})

if (NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif ()