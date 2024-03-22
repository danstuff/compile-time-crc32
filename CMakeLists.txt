cmake_minimum_required(VERSION 3.8)
include(ExternalProject)

project(compile_time_crc32_test VERSION 0.0)

# config
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(PROJECT_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_BUILD ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_executable(compile_time_crc32_test)
set_target_properties(compile_time_crc32_test PROPERTIES LINKER_LANGUAGE CXX)

# add source files
set(PROJECT_SRC_FILES 
  main.c
)
list(TRANSFORM PROJECT_SRC_FILES PREPEND ${PROJECT_SRC}/)

target_include_directories(compile_time_crc32_test PRIVATE ${PROJECT_SRC})
target_sources(compile_time_crc32_test PRIVATE ${PROJECT_SRC_FILES})
