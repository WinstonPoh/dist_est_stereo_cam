cmake_minimum_required(VERSION 3.5)
project(dist_est_stereo_cam)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(dist_est_stereo_cam ${SOURCE_FILES})