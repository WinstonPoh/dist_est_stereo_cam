cmake_minimum_required(VERSION 3.5)
project(dist_est_stereo_cam)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package( OpenCV REQUIRED )
set(SOURCE_FILES main.cpp)
add_executable(dist_est_stereo_cam ${SOURCE_FILES})
target_link_libraries( dist_est_stereo_cam ${OpenCV_LIBS} )