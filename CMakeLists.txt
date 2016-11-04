cmake_minimum_required(VERSION 3.6)
project(stitch)

find_package( OpenCV REQUIRED )
include_directories(include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/SiftFeaturesFinder.cpp include/SiftFeaturesFinder.hpp src/Util.cpp include/Util.hpp)
add_executable(stitch ${SOURCE_FILES})
add_definitions(-DENABLE_LOG=1)
target_link_libraries( stitch ${OpenCV_LIBS} )