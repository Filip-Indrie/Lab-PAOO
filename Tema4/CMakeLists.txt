cmake_minimum_required(VERSION 3.10)
project(Tema4)
include_directories(include)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    include/HardwarePort.hpp
    include/Logger.hpp
    include/SensorTypes.hpp
    include/Uncopyable.hpp
    src/HardwarePort.cpp
    src/Logger.cpp
    src/main.cpp
)