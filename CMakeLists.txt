cmake_minimum_required(VERSION 3.23)
project(untitled5)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled5 CPP/main.cpp CPP/Spisok.cpp Headers/Spisok.h CPP/Node.cpp Headers/Node.h Headers/main.h CPP/Stack.cpp Headers/Stack.h CPP/Calculator.cpp Headers/Calculator.h CPP/InfixCalc.cpp Headers/InfixCalc.h CPP/Queue.cpp Headers/Queue.h)
