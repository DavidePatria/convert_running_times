cmake_minimum_required(VERSION 3.7)

set (CMAKE_CXX_STANDARD 20)

project(prove_cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(helper
	src/helper.cpp
)
target_include_directories(helper
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# add_executable(main main.cpp)  # be sure there's exactly one main() function in the source files
add_executable(convert convert.cpp)  # be sure there's exactly one main() function in the source files

add_executable(unit_tests src/unit_tests.cpp)  # be sure there's exactly one main() function in the source files

target_link_libraries(convert PRIVATE helper)
target_link_libraries(unit_tests PRIVATE helper)
