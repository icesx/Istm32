message("work dir :${CMAKE_CURRENT_SOURCE_DIR}")
include(${STM32_CMAKE_DIR}/cmake/stm32-common.cmake)
set(system_dir_list
    delay
    usart
    sys
    )
set(bsp_dir_list
    LED
    )
add_subdirectory(Core)
add_subdirectory(Drivers)
## add post-build targets
include(${STM32_CMAKE_DIR}/cmake/stm32-gcc-jlink.cmake)
