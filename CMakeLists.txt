cmake_minimum_required(VERSION 3.16)
project(MonteCarloSimulator LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MonteCarlosimulator
src/statistics.cpp
src/simulation.cpp
src/brownian.cpp
src/csv_parser.cpp
)

target_include_directories(MonteCarlosimulator
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(UnitTests
tests/tests.cpp
src/brownian.cpp
src/statistics.cpp
)

target_include_directories(UnitTests PRIVATE  
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)