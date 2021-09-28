# https://developer.apple.com/documentation/xcode/diagnosing-memory-thread-and-crash-issues-early
# Address Sanitizers
# The ASan tool identifies potential memory-related corruption issues.
# Overlaps with Valgrind
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

# Undefined Behaviour Sanitizer
# Valgrind doesn't support it.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=undefined")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")

# Thread Sanitizer
# The TSan tool detects race conditions between threads.
# Conflicts with address sanitizer
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=thread")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-omit-frame-pointer -g -O1")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -g -O1")
