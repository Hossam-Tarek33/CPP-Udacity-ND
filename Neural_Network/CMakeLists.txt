cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 14)

project(Neural_Network)

add_executable(Neural src/main.cpp src/Neuron.cpp src/Matrix.cpp src/Layer.cpp src/Network.cpp src/Multiply_Matrix.cpp)




