include(${STM32_CMAKE_DIR}/cmake/stm32-common.cmake)
add_subdirectory(Core)
add_subdirectory(Drivers)
## add post-build targets

include(${STM32_CMAKE_DIR}/cmake/stm32-gcc-jlink.cmake)
