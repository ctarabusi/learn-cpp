cmake_minimum_required(VERSION 3.28)
project(learn_with_clion)

set(CMAKE_CXX_STANDARD 14)

project(learn_with_clion)

# Locate SFML
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

file(GLOB SOURCES "src/*.cpp")

# Set the source directory of your MP3 file
set(MP3_SOURCE resources/theme.mp3)

# Set the destination directory in the build directory
set(MP3_DEST ${CMAKE_BINARY_DIR}/theme.mp3)

# Copy the MP3 file to the build directory
configure_file(${MP3_SOURCE} ${MP3_DEST} COPYONLY)

set(TEXTURE_SOURCE resources/texture.png)
set(SKY_SOURCE resources/sky.png)
# Set the destination directory in the build directory
set(TEXTURE_DEST ${CMAKE_BINARY_DIR}/texture.png)
set(SKY_DEST ${CMAKE_BINARY_DIR}/sky.png)

configure_file(${TEXTURE_SOURCE} ${TEXTURE_DEST} COPYONLY)
configure_file(${SKY_SOURCE} ${SKY_DEST} COPYONLY)

add_executable(learn_with_clion ${SOURCES}
        src/world.h
        src/world.h
        src/world.cpp
        src/raycast.h
        src/raycast.cpp
        src/key_handler.h
        src/key_handler.cpp)


# Link against SFML libraries
target_link_libraries(learn_with_clion sfml-graphics)
target_link_libraries(learn_with_clion sfml-audio)

