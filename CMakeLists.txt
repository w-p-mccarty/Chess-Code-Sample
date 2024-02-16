cmake_minimum_required(VERSION 3.28)
project(WorkSample_C___)

set(CMAKE_CXX_STANDARD 20)

#file(GLOB SOURCE_FILES *.cpp)
#add_executable(WorkSample_C___ main.cpp)

file(GLOB SOURCE_FILES *.cpp)
add_executable(WorkSample_C___ ${SOURCE_FILES})

