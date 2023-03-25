cmake_minimum_required(VERSION 3.24)
project(new_language)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

aux_source_directory(src SRCs)

add_executable(new_language ${SRCs})

add_subdirectory(Google_tests)