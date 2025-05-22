
include_directories(include)

file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
    *.cpp
)

list(FILTER SOURCES EXCLUDE REGEX "main.cpp$")

add_executable(UnitTests ${TEST_SOURCES} ${SOURCES})

target_link_libraries(UnitTests PRIVATE gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(UnitTests)
