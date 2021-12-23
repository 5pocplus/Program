cmake_minimum_required(VERSION 3.5)

set(gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll" FORCE)

project(math)
add_subdirectory(gt)

add_library(math STATIC det.cpp transp.cpp)


add_executable(TestMath ./mainTest.cpp ../dopF.cpp)
target_link_libraries(TestMath math)
target_link_libraries(TestMath gtest)