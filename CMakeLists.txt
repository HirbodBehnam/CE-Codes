cmake_minimum_required(VERSION 3.17)
project(Quera C)

set(CMAKE_C_STANDARD 11)

add_executable(Quera main.c University-Questions/Q66859.h utility.h University-Questions/Q66861.h University-Questions/Q66864.h University-Questions/Q66863.h University-Questions/Q66865.h University-Questions/Q66862.h University-Questions/Q9773.h University-Questions/Q649.h University-Questions/Q655.h University-Questions/Q303.h University-Questions/Q651.h University-Questions/Q592.h University-Questions/Q283.h University-Questions/Q597.h University-Questions/Q66866.h)

target_link_libraries(Quera m)