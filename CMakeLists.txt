cmake_minimum_required(VERSION 3.16)

# the following sfml w/ cmake blog inspired this cmake file--> https://dane-bulat.medium.com/cmake-building-sfml-and-game-projects-on-linux-3947b3ba6e8

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug
            CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif ()

# set the project name
project(chess)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(SFML 2.5
        COMPONENTS
        system window graphics network audio REQUIRED)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
        src/main.cpp
        src/game_loop.cpp
        src/board.cpp
        src/pieces.cpp
        src/board_view
        )

# Add an executable with the above sources
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(chess
        PRIVATE "${PROJECT_BINARY_DIR}")

target_link_libraries(chess sfml-graphics)

# specify that the chess executable is copied to /usr/local/bin after invoking a sudo make install command
install(TARGETS chess DESTINATION bin)

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )
