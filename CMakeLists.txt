cmake_minimum_required(VERSION 3.17)
project(matrix_cpp_examplebot)

set(CMAKE_CXX_STANDARD 14)

add_executable(matrix_cpp_examplebot main.cpp)
add_subdirectory(external/matrix-cpp-sdk)

target_link_libraries(matrix_cpp_examplebot matrix-cpp-sdk)
target_include_directories(matrix_cpp_examplebot PRIVATE external/matrix-cpp-sdk/src)
target_link_libraries(matrix_cpp_examplebot jsoncpp_lib)
include_directories(${Jsoncpp_INCLUDE_DIR})
include_directories(${MATRIX_CPP_INCLUDE_DIR})