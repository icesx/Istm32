message("work dir :${CMAKE_CURRENT_SOURCE_DIR}")
foreach(sub IN LISTS system_dir_list)
    message("add subdirectory: ${sub}")
    message("add include_directories: ${DRIVERS_ROOT}/${parent}/${sub}")
    add_subdirectory("${sub}")
    link_directories(${PROJECT_BINARY_DIR}/${parent}/${sub})
    include_directories(${DRIVERS_ROOT}/${parent}/${sub})
    target_include_directories(${ELF_TARGET} PUBLIC
        $<BUILD_INTERFACE:${DRIVERS_ROOT}/${parent}/${sub}>
    )
    
endforeach (sub)

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message("include is :${dirs}")