cmake_minimum_required(VERSION 3.16)
project(Tatlin.Unified_test)
set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.81.0 REQUIRED)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
    ${Boost_INCLUDE_DIRS})

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/MySort.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Tape.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/main.cpp)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

file(MAKE_DIRECTORY ${directory} "${CMAKE_CURRENT_BINARY_DIR}\\tmp")
