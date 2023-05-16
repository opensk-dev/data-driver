
add_library(sk_data_driver SHARED)
add_library(opensk::data::driver ALIAS sk_data_driver)

include(GenerateExportHeader)

set(sk_data_export_file_name include/opensk/data/export_shared.h)
generate_export_header(sk_data_driver EXPORT_FILE_NAME ${sk_data_export_file_name})

set(sk_data_driver_public_headers
        include/opensk/data/export.hpp
        include/opensk/data/driver.hpp)

set(sk_data_driver_sources
        ${sk_data_driver_public_headers}
        src/driver.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sk_data_driver_sources})

list(APPEND sk_data_driver_public_headers "${CMAKE_CURRENT_BINARY_DIR}/${sk_data_export_file_name}")
list(APPEND sk_data_driver_sources "${CMAKE_CURRENT_BINARY_DIR}/${sk_data_export_file_name}")

target_sources(sk_data_driver PRIVATE ${sk_data_driver_sources})

target_link_libraries(sk_data_driver INTERFACE Boost::boost)

target_include_directories(
        sk_data_driver
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_compile_features(sk_data_driver PUBLIC cxx_std_20)

set_target_properties(
        sk_data_driver PROPERTIES
        PUBLIC_HEADER "${sk_data_driver_public_headers}"
        SOVERSION ${PROJECT_VERSION_MAJOR}
        VERSION ${PROJECT_VERSION}
)
