# Add libraries
set(CMSIS_SRC
  Device/ST/STM32F1xx/Source/Templates/system_stm32f1xx.c
)
message("add library cmsis")
add_library(cmsis ${CMSIS_SRC})
target_compile_definitions(cmsis PUBLIC -D${MCU_FAMILY})
target_include_directories(cmsis PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Device/ST/STM32F1xx/Include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Core/Include>
  )
target_include_directories(cmsis INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Core/Include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Device/ST/STM32F1xx/Include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Device/ST/STM32F4xx/Include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Device/ST/STM32F7xx/Include>)
