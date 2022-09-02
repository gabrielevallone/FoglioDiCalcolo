cmake_minimum_required(VERSION 3.5)
project(FoglioDiCalcolo)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(FoglioDiCalcolo main.cpp Observer.h Subject.h)
target_link_libraries(FoglioDiCalcolo ${wxWidgets_LIBRARIES})