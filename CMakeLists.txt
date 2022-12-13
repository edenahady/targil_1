cmake_minimum_required(VERSION 3.0.0)
project(targil_2 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(targil_2 project/KNN.cpp project/knnClass.cpp project/pair.cpp project/distances.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
