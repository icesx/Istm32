set(DOFLY_DIR ${CMAKE_CURRENT_LIST_DIR})
set(subs "blink;beep;common")
foreach(sub IN LISTS subs)
    include_directories(${DOFLY_DIR}/${sub})
    target_link_libraries(${ELF_TARGET} PUBLIC ${sub} -lc -lm -lnosys)
endforeach(sub)

add_subdirectory(dofly)