cmake_minimum_required(VERSION 2.8)
project( CaptureVideo )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( capture-video capture_video.cpp )
target_link_libraries( capture-video ${OpenCV_LIBS} )
