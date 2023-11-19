cmake_minimum_required(VERSION 3.0.0)

SET(SRC led.c)
set(so led)
message("do ${so}")
add_library(${so} ${SRC})
include(${DRIVERS_ROOT}/drivers-lib.cmake)