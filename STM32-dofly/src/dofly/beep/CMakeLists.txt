cmake_minimum_required(VERSION 3.0.0)
SET(SRC beep.c)
set(so beep)

add_library(${so} ${SRC})
include(${DOFLY_DIR}/dofly-sub.cmake)
  

