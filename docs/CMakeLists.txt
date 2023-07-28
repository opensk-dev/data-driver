
set(sk_data_docs_output_dir ${sk_data_output_dir}/docs)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(doxygen_file_template doxyfile.in)
    set(doxygen_file_path ${sk_data_docs_output_dir}/doxyfile)

    configure_file(${doxygen_file_template} ${doxygen_file_path})

    add_custom_target(
        sk_data_docs ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${doxygen_file_path}
        WORKING_DIRECTORY ${sk_data_docs_output_dir}
        COMMENT "Generate API docs for opensk::data"
        VERBATIM
    )
else()
    message(WARNING "Doxygen wasn't found!")
endif()

install(DIRECTORY ${sk_data_docs_output_dir} DESTINATION ${CMAKE_INSTALL_PREFIX})
