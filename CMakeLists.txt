cmake_minimum_required(VERSION 3.17)
project(Quera C)

set(CMAKE_C_STANDARD 11)

add_executable(Quera main.c Questions/Q66859.h utility.h Questions/Q66861.h Questions/Q66864.h Questions/Q66863.h Questions/Q66865.h Questions/Q66862.h Questions/Q9773.h Questions/Q649.h Questions/Q655.h Questions/Q303.h Questions/Q651.h Questions/Q592.h Questions/Q283.h Questions/Q597.h)

target_link_libraries(Quera m)