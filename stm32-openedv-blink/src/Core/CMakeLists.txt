SET(_subs "Src")
foreach(sub IN LISTS _subs)
    message("config subdirectory::: ${sub}")
    add_subdirectory("${sub}")
    link_directories(${PROJECT_BINARY_DIR}/${parent}/${sub})
    include_directories(${DRIVERS_ROOT}/${parent}/${sub})
    
endforeach (sub)