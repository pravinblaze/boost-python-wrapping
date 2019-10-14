project(traffic_manager CXX)
cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_C_COMPILER /usr/bin/clang-7)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-7)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fPIC -O3 -DNDEBUG" CACHE STRING "" FORCE)

find_package(PythonInterp REQUIRED)
find_package(PythonLibs REQUIRED)

set(WORKSPACE /home/praveen/workspace)

include_directories(${WORKSPACE}/boost-python-wrapping/include)
include_directories(${WORKSPACE}/boost-1.69.0-c7-install/include)
include_directories(${PYTHON_INCLUDE_DIRS})

link_directories(${WORKSPACE}/boost-1.69.0-c7-install/lib)

file(GLOB SOURCES ${WORKSPACE}/boost-python-wrapping/source/*.cpp)

add_library(clib ${SOURCES})
add_library(pylib SHARED ${WORKSPACE}/boost-python-wrapping/wrap/wrapper.cpp)

# Linking python wrapper
target_link_libraries(pylib ${PYTHON_LIBRARIES} clib boost_python27)

set_target_properties(pylib PROPERTIES SUFFIX .so)
set_target_properties(pylib PROPERTIES PREFIX "")

file(COPY ${WORKSPACE}/boost-python-wrapping/python/run.py
     DESTINATION ${WORKSPACE}/boost-python-wrapping/build/)
