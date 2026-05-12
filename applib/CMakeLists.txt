cmake_minimum_required(VERSION 3.20)
project(applib)

add_library(applib
    ./src/App.cpp
    ./src/Relations/PointBelongsToSegment.cpp
)

target_include_directories(applib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Relations 
    ${CMAKE_CURRENT_SOURCE_DIR}/external/Storages-shapes
    ${CMAKE_CURRENT_SOURCE_DIR}/external/Storages-shapes/Storage
    ${CMAKE_CURRENT_SOURCE_DIR}/external/Storages-shapes/Array
    ${CMAKE_CURRENT_SOURCE_DIR}/external/Storages-shapes/List
    ${CMAKE_CURRENT_SOURCE_DIR}/external/Storages-shapes/BinTree

)

