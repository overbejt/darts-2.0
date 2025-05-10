cmake_minimum_required(VERSION 3.31.3)

project(darts LANGUAGES CXX)

set(SOURCE_FILES src/main.cpp)

# Find SFML package
# find_package(SFML REQUIRED)  # couldn't find it

# Plan B worked! 
# Template can be found at https://github.com/SFML/cmake-sfml-project/blob/master/CMakeLists.txt
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(darts ${SOURCE_FILES})

target_compile_features(darts PRIVATE cxx_std_17)

# Link against SFML
target_link_libraries(darts PRIVATE SFML::Graphics)

