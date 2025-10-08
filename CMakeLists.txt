cmake_minimum_required(VERSION 3.10)
project(TicTacToe VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  
add_executable(TicTacToe
  src/main.cpp
  src/globals.cpp
)
target_include_directories(TicTacToe PRIVATE include)
