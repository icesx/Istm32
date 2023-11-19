SET(core_list 
    Src
    )
set(link_list
    led
    delay
    thesys
    )
foreach(sub IN LISTS core_list)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
    link_directories(${PROJECT_BINARY_DIR}/${parent}/${sub})
    include_directories(${DRIVERS_ROOT}/${parent}/${sub})
    
endforeach (sub)