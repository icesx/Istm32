cmake_minimum_required(VERSION 3.0.0)
add_definitions(
    -DFLASH_ACR_LATENCY
)
SET(SRC thesys.c)
set(so thesys)
message("do ${so}")
add_library(${so} ${SRC})
message("include ${DRIVERS_ROOT}/drivers-sub.cmake")
include(${DRIVERS_ROOT}/drivers-lib.cmake)