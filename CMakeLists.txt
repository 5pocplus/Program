cmake_minimum_required(VERSION 3.5)


project(detTransp_progect)
add_subdirectory(math)


add_executable(detTransp main.cpp dopF.cpp)
target_link_libraries(detTransp math)
target_include_directories(detTransp PUBLIC "../boost_1_77_0" )
target_link_directories(detTransp PUBLIC "../boost_1_77_0/stage/lib")


