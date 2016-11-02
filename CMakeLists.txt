cmake_minimum_required(VERSION 3.6)
project(stitch)

find_package( OpenCV REQUIRED )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(stitch ${SOURCE_FILES})
target_link_libraries( stitch ${OpenCV_LIBS} )