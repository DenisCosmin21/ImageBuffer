cmake_minimum_required(VERSION 3.2)

project(ImageBufferApp)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

set(myfiles src/main.cpp src/ImageBuffer.cpp include/ImageBuffer.h)

add_executable(${PROJECT_NAME} ${myfiles})