cmake_minimum_required(VERSION 3.22.1)
project(2GISTEST)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(test_app ${SOURCES})

add_subdirectory(contrib/googletest)
enable_testing()

add_subdirectory(tests)
