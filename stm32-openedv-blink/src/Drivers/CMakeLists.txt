message("work dir :${CMAKE_CURRENT_SOURCE_DIR}")
set(DRIVERS_ROOT ${CMAKE_CURRENT_LIST_DIR})

foreach(sub IN LISTS drivers_dir_list)
    set(parent "${sub}")
    message("and subdirectory: ${sub}")
    add_subdirectory("${sub}")
endforeach (sub)