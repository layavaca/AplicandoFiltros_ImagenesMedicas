cmake_minimum_required(VERSION 3.10)
project(ProyectoVision)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} include)

file(GLOB SOURCES "src/*.cpp")

add_executable(vision_app ${SOURCES})

target_link_libraries(vision_app ${OpenCV_LIBS})
