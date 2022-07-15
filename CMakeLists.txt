cmake_minimum_required(VERSION 3.0.0)
project(pingpong VERSION 0.1.0 DESCRIPTION "pingpong" LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCE_FILES "src/*.h" "src/*.cpp")

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)
