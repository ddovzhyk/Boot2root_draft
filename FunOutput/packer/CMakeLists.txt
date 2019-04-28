cmake_minimum_required(VERSION 3.1)

project(packer)
set (CMAKE_CXX_STANDARD 11)

include_directories ("${PROJECT_SOURCE_DIR}/include")

add_executable (packer src/Packer.cpp include/Packer.h)
