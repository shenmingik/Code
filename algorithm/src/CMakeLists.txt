aux_source_directory(. SRC_LIST)

add_executable(test1 ${SRC_LIST})

target_link_libraries(test1)
