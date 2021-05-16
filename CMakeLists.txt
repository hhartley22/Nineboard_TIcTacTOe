cmake_minimum_required(VERSION 3.17)
project(Assignment_1)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_FILES main.cpp NineBoard.cpp TicTacToe.cpp NBGame.cpp RandomPlayer.cpp HumanPlayer.cpp MonteCarloPlayer.cpp)
add_executable(Assignment_1 ${PROJECT_FILES})