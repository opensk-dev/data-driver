cmake_minimum_required(VERSION 3.21)
project(
        opensk_data
        VERSION 0.1
        DESCRIPTION "parser and loader for elder scrolls data files"
        LANGUAGES CXX
)

option(SK_DATA_BUILD_TESTS "Build tests for opensk_data_driver" ${PROJECT_IS_TOP_LEVEL})
option(SK_DATA_BUILD_EXAMPLES "Build examples for opensk_data_driver" ${PROJECT_IS_TOP_LEVEL})
option(SK_DATA_INSTALL_TEST_DATA "Copy data files" ${PROJECT_IS_TOP_LEVEL})

# Do not export all functions (for GCC and Clang)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

# Setup binary folder
if(${PROJECT_IS_TOP_LEVEL})
    set(SK_DATA_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${SK_DATA_OUTPUT_DIRECTORY}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SK_DATA_OUTPUT_DIRECTORY})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SK_DATA_OUTPUT_DIRECTORY})
endif()

# Boost REQUIRED COMPONENTS:
# - iostreams: for driver files input-output
# - dll (header-only): for driver load
find_package(Boost 1.82 REQUIRED COMPONENTS iostreams)

add_subdirectory(driver)
add_subdirectory(interface)

if(SK_DATA_BUILD_TESTS)
    add_subdirectory(tests)
endif()

if(SK_DATA_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(SK_DATA_INSTALL_TEST_DATA)
    file(GLOB SK_DATA_TEST_DATA_FILES ${CMAKE_CURRENT_SOURCE_DIR}/data/*)
    file(COPY ${SK_DATA_TEST_DATA_FILES} DESTINATION ${SK_DATA_OUTPUT_DIRECTORY}/data/)
endif()