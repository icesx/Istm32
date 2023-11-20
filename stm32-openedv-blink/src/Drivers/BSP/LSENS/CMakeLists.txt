message("work dir :${CMAKE_CURRENT_SOURCE_DIR}")

SET(SRC
    lsens.c
    )
set(so lsens)
message("add_library ${so}")
add_library(${so} ${SRC})
include(${DRIVERS_ROOT}/drivers-lib.cmake)