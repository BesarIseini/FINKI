cmake_minimum_required(VERSION 4.0)
project(MidTermExercises)

set(CMAKE_CXX_STANDARD 20)

add_executable(MidTermExercises main.cpp
        hexadecimal.cpp)
add_executable(CharacterNumberReader CharacterNumberReader.cpp
        Dates.cpp
        maximumSumOfDivisors.cpp
        SweetNumber.cpp
        totalDifferent.cpp)
add_executable(Compare compare.cpp)
add_executable(Percentage percentage.cpp)
add_executable(Triangle triangle.cpp)
add_executable(SomeRandom someRandom.cpp)
add_executable(WeirdSquare WeirdSquare.cpp)
add_executable(ZigZag zigzag.cpp)
add_executable(ZigZag2 zigzag2.cpp)
