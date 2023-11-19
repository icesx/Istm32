message("work dir :${CMAKE_CURRENT_SOURCE_DIR}")
foreach(sub IN LISTS bsp_dir_list)
    message("add include_directories: ${DRIVERS_ROOT}/${parent}/${sub}")
    include_directories(${DRIVERS_ROOT}/${parent}/${sub})
    message("and subdirectory: ${sub}")
    add_subdirectory("${sub}")
    link_directories(${PROJECT_BINARY_DIR}/${parent}/${sub})
    target_include_directories(${ELF_TARGET} PUBLIC
        $<BUILD_INTERFACE:${DRIVERS_ROOT}/${parent}/${sub}>
    )
endforeach (sub)