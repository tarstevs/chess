cmake_minimum_required(VERSION 3.16)

# the following sfml w/ cmake blog inspired this cmake file--> https://dane-bulat.medium.com/cmake-building-sfml-and-game-projects-on-linux-3947b3ba6e8

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug
            CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif ()

project(chess)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(SFML_DIR "./SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
set(SOURCES
        main.cpp
        src/game_loop.cpp
        src/board.cpp
        src/pieces.cpp
        src/board_view.cpp
        )
add_executable(chess ${SOURCES})
## Set the directories that should be included in the build command for this target
## when running g++ these will be included as -I/directory/path/
#target_include_directories(chess
#        include
#        )
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )