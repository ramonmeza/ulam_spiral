cmake_minimum_required(VERSION 3.25)

project(
    ulams_spiral
    DESCRIPTION "Trying to implement Ulam's Spiral in C++"
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(app)

