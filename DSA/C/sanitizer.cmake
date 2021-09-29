# Address Sanitizers
# The ASan tool identifies potential memory-related corruption issues.
# Overlaps with Valgrind
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")

# Undefined Behaviour Sanitizer
# Valgrind doesn't support it.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=undefined")

# Thread Sanitizer
# The TSan tool detects race conditions between threads.
# Conflicts with address sanitizer
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=thread")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-omit-frame-pointer -g -O1")
