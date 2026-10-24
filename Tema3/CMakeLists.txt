cmake_minimum_required(VERSION 3.10)
project(Tema3)
include_directories(include)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    include/Playlist.hpp
    # src/Playlist_broken.cpp
    src/Playlist.cpp
    src/main.cpp
)