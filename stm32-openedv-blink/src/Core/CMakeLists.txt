message("work dir :${CMAKE_CURRENT_SOURCE_DIR}")
SET(core_list 
    Src
    )
foreach(sub IN LISTS core_list)
    message("add subdirectory ${sub}")
    add_subdirectory("${sub}")
    link_directories(${PROJECT_BINARY_DIR}/${parent}/${sub})
    include_directories(${DRIVERS_ROOT}/${parent}/${sub})
endforeach (sub)