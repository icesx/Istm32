include(${STM32_CMAKE_DIR}/cmake/stm32-common.cmake)


# STM32CubeMX generated source files
set(CUBEMX_SRC
    ${PROJECT_ROOT_DIR}/src/Core/Src/main.c
    ${PROJECT_ROOT_DIR}/src/Core/Src/stm32f1xx_it.c
    ${PROJECT_ROOT_DIR}/src/Core/Src/system_stm32f1xx.c
    ${STM32_CMAKE_DIR}/libraries/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xb.s
)
add_executable(${ELF_TARGET} ${CUBEMX_SRC})
include(dofly/dofly.cmake)
target_compile_definitions(${ELF_TARGET} PUBLIC -D${MCU_FAMILY})
target_link_libraries(${ELF_TARGET} PUBLIC cmsis stm32f1xx_hal -lc -lm -lnosys)
target_link_libraries(${ELF_TARGET} PRIVATE -T${LINKER_SCRIPT} ${EXTRA_LINK_FLAGS})
target_include_directories(${ELF_TARGET} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Core/Inc>)

## add post-build targets
include(${STM32_CMAKE_DIR}/cmake/stm32-gcc-postbuild.cmake)
include(${STM32_CMAKE_DIR}/cmake/stm32-gcc-jlink.cmake)
