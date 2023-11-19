SET(_subs "LED")
foreach(sub IN LISTS _subs)
    message("config subdirectory::: ${sub}")
    message("add include_directories: ${DRIVERS_ROOT}/${parent}/${sub}")
    include_directories(${DRIVERS_ROOT}/${parent}/${sub})
    add_subdirectory("${sub}")
    link_directories(${PROJECT_BINARY_DIR}/${parent}/${sub})
    target_include_directories(${ELF_TARGET} PUBLIC
        $<BUILD_INTERFACE:${DRIVERS_ROOT}/${parent}/${sub}>
    )
endforeach (sub)