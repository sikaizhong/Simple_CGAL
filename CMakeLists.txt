################################################################################
cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(SCGAL LANGUAGES CXX)


include_directories(${CMAKE_SOURCE_DIR}/SCGAL/convexhull)
include_directories(${CMAKE_SOURCE_DIR}/SCGAL/core)
include_directories(${CMAKE_SOURCE_DIR}/SCGAL/Cartesian_kernel)
include_directories(${CMAKE_SOURCE_DIR}/SCGAL/Kernel_23)
include_directories(${CMAKE_SOURCE_DIR}/SCGAL/Filtered_kernel)




SOURCE_GROUP (convexhull REGULAR_EXPRESSION SCGAL/ConvexHull/.*) 
SOURCE_GROUP (core REGULAR_EXPRESSION SCGAL/core/.*) 

SOURCE_GROUP (Cartesian_kernel REGULAR_EXPRESSION SCGAL/Cartesian_kernel/.*) 
SOURCE_GROUP (Kernel_23 REGULAR_EXPRESSION SCGAL/Kernel_23/.*) 
SOURCE_GROUP (Filtered_kernel REGULAR_EXPRESSION SCGAL/Filtered_kernel/.*) 




file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/SCGAL/*.cpp ${CMAKE_SOURCE_DIR}/SCGAL/*.h)

add_library(SCGAL  ${SRC_FILES})

add_subdirectory(example/ch_graham_anderson)



