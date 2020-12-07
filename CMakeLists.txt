cmake_minimum_required(VERSION 3.15)
project(copterfix_sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(copterfix_sort
        main.cpp
        include/SortAlgo.h
        src/SortAlgo.cpp
        src/BubbleSort.cpp
        include/BubbleSort.h
        src/MergeSort.cpp
        include/MergeSort.h
        src/QuickSort.cpp
        include/QuickSort.h)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})