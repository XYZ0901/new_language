project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Google_Tests_run test1.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)