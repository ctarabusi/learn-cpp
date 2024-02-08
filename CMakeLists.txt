cmake_minimum_required(VERSION 3.28)
project(learn_with_clion)

set(CMAKE_CXX_STANDARD 14)

project(learn_with_clion)

# Locate SFML
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_executable(learn_with_clion ${SOURCES})

# Link against SFML libraries
target_link_libraries(learn_with_clion sfml-graphics)
