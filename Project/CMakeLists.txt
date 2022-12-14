cmake_minimum_required(VERSION 3.23)
project(first_reach_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(first_reach_game main.cpp FirstReachGame.cpp FirstReachGame.h Player.cpp Player.h Human.cpp Human.h Computer.cpp Computer.h)
