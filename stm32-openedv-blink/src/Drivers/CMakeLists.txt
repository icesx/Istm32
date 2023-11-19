set(DRIVERS_ROOT ${CMAKE_CURRENT_LIST_DIR})
set(subs 
    SYSTEM
    BSP
    )
foreach(sub IN LISTS subs)
    set(parent "${sub}")
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
endforeach (sub)