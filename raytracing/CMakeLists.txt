cmake_minimum_required( VERSION 2.8 )
project(raytracing)

set( CMAKE_BUILD_TYPE Release )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )


add_executable(raytracing main.cpp
                        Image.cpp
                        Vector3.cpp
                        ONB.cpp
)

