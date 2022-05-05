cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(hello VERSION 1.0)


add_subdirectory(blah)
add_executable(hello main.cpp ${SRC_FILES})
 
target_link_libraries(hello PUBLIC blah)
