cmake_minimum_required(VERSION 3.10.2)

project(MATRIX_MULT)

add_executable(${PROJECT_NAME} matMul.cpp )

add_subdirectory(Adder)

target_link_libraries(${PROJECT_NAME} adder)
