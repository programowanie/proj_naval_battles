cmake_minimum_required(VERSION 3.5)
project(proj_naval_battles)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Interface.h Interface.cpp Battle.h Battle.cpp Enemy.h Enemy.cpp Warships.h Warships.cpp)
add_executable(proj_naval_battles ${SOURCE_FILES})