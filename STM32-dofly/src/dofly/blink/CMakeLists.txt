cmake_minimum_required(VERSION 3.0.0)
SET(SRC blink.c)
set(so blink)

add_library(${so} ${SRC})
include(${DOFLY_DIR}/dofly-sub.cmake)