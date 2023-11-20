message("work dir :${CMAKE_CURRENT_SOURCE_DIR}")

SET(SRC
    adc.c
    adc3.c
    )
set(so adc)
message("add_library ${so}")
add_library(${so} ${SRC})
include(${DRIVERS_ROOT}/drivers-lib.cmake)