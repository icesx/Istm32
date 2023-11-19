cmake_minimum_required(VERSION 3.0.0)
SET(SRC timer.c)
set(so timer)

add_library(${so} ${SRC})
include(${DOFLY_DIR}/dofly-sub.cmake)