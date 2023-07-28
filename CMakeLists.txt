cmake_minimum_required(VERSION 3.21)
project(
    opensk_data
    VERSION 0.1
    DESCRIPTION "parser and loader for elder scrolls data files"
    LANGUAGES CXX
)

option(sk_data_generate_docs "Generate documentation for opensk data" ${PROJECT_IS_TOP_LEVEL})
option(sk_data_build_tests "Build tests for opensk_data_driver" ${PROJECT_IS_TOP_LEVEL})
option(sk_data_build_examples "Build examples for opensk_data_driver" ${PROJECT_IS_TOP_LEVEL})
option(sk_data_install_test_data "Download test data files" ${SK_DATA_BUILD_EXAMPLES})

# Do not export all functions (for GCC and Clang)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

set(sk_data_source_dir ${CMAKE_CURRENT_SOURCE_DIR}/driver)
set(sk_data_output_dir "${CMAKE_CURRENT_BINARY_DIR}/out")

# Setup binary folder
if(${PROJECT_IS_TOP_LEVEL})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${SK_DATA_OUTPUT_DIRECTORY}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SK_DATA_OUTPUT_DIRECTORY})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SK_DATA_OUTPUT_DIRECTORY})
endif()

add_subdirectory(driver)

if(sk_data_generate_docs)
    add_subdirectory(docs)
endif()

if(sk_data_build_tests)
    add_subdirectory(tests)
endif()

if(sk_data_build_examples)
    add_subdirectory(examples)
endif()

if(sk_data_install_test_data)
    message(WARNING "Skyrim data files not available yet")
endif()