cmake_minimum_required(VERSION 3.5)
project(FoglioDiCalcolo)

set(CMAKE_CXX_STANDARD 14)

set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(FoglioDiCalcolo main.cpp Observer.h Subject.h FoglioDiCalcolo.cpp FoglioDiCalcolo.h Max.cpp Max.h Min.cpp Min.h Sum.cpp Sum.h Media.cpp Media.h main.h)
target_link_libraries(FoglioDiCalcolo ${wxWidgets_LIBRARIES})