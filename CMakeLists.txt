cmake_minimum_required(VERSION 3.5)
project(FoglioDiCalcolo)

set(CMAKE_CXX_STANDARD 14)

set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

#add_executable(FoglioDiCalcolo main.cpp Observer.h Subject.h FoglioDiCalcolo.cpp FoglioDiCalcolo.h Max.cpp Max.h Min.cpp Min.h Sum.cpp Sum.h Media.cpp Media.h main.h test/TestFoglioDiCalcolo.cpp test/runAllTests.cpp test/TestCalculate.cpp)
#target_link_libraries(FoglioDiCalcolo ${wxWidgets_LIBRARIES})

add_subdirectory(test)
set(SOURCE_FILES Subject.h Observer.h FoglioDiCalcolo.cpp FoglioDiCalcolo.h Sum.cpp Sum.h Media.cpp Media.h Max.cpp Max.h Min.cpp Min.h)
add_executable(FoglioDiCalcolo main.cpp main.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(FoglioDiCalcolo ${wxWidgets_LIBRARIES} core)