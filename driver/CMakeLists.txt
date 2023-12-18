
add_library(sk_data_driver STATIC)
add_library(opensk::data ALIAS sk_data_driver)

include(GenerateExportHeader)

set(sk_data_driver_include_prefix "include/opensk/data")
set(sk_data_driver_include_dir "${sk_data_source_dir}/${sk_data_driver_include_prefix}")
set(sk_data_driver_gen_include_dir "${CMAKE_CURRENT_BINARY_DIR}/${sk_data_driver_include_prefix}")
set(sk_data_driver_source_dir "${sk_data_source_dir}/src")

generate_export_header(sk_data_driver EXPORT_FILE_NAME "${sk_data_driver_gen_include_dir}/export_shared.hpp")
configure_file("${sk_data_driver_source_dir}/config.hpp.in" "${sk_data_driver_gen_include_dir}/config.hpp")

set(
    sk_data_driver_gen_headers
    "${sk_data_driver_gen_include_dir}/export_shared.hpp"
    "${sk_data_driver_gen_include_dir}/config.hpp"
)

set(
    sk_data_driver_public_headers
    "${sk_data_driver_include_dir}/export.hpp"
    "${sk_data_driver_include_dir}/driver.hpp"
    "${sk_data_driver_include_dir}/plugin.hpp"
    "${sk_data_driver_include_dir}/plugin_source.hpp"
)

set(
    sk_data_driver_sources
    "${sk_data_driver_public_headers}"
    "${sk_data_driver_source_dir}/driver.cpp"
    "${sk_data_driver_source_dir}/plugin.cpp"
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${sk_data_driver_sources})

list(APPEND sk_data_driver_public_headers ${sk_data_driver_gen_headers})
list(APPEND sk_data_driver_sources ${sk_data_driver_gen_headers})

target_sources(sk_data_driver PRIVATE ${sk_data_driver_sources})

include(GNUInstallDirs)

target_include_directories(
    sk_data_driver
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_compile_features(sk_data_driver PUBLIC cxx_std_23)

set_target_properties(
    sk_data_driver PROPERTIES
    PUBLIC_HEADER "${sk_data_driver_public_headers}"
    SOVERSION ${PROJECT_VERSION_MAJOR}
    VERSION ${PROJECT_VERSION}
)

find_package(Boost 1.82 REQUIRED)
target_link_libraries(sk_data_driver INTERFACE Boost::boost)

install(
    TARGETS sk_data_driver
    RUNTIME COMPONENT sk_data_driver
    LIBRARY COMPONENT sk_data_driver NAMELINK_COMPONENT sk_data_driver_dev
    ARCHIVE COMPONENT sk_data_driver_dev
    PUBLIC_HEADER COMPONENT sk_data_driver_dev
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/opensk/data/"
)
