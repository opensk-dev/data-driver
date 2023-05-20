
add_library(sk_data_driver STATIC)
add_library(opensk::data ALIAS sk_data_driver)

set(sk_data_driver_include_dir "include/opensk/data")

include(GenerateExportHeader)

generate_export_header(sk_data_driver EXPORT_FILE_NAME "${sk_data_driver_include_dir}/export_shared.hpp")
configure_file("src/config.hpp.in" "${sk_data_driver_include_dir}/config.hpp")

set(sk_data_driver_gen_headers
        "${CMAKE_CURRENT_BINARY_DIR}/${sk_data_driver_include_dir}/export_shared.hpp"
        "${CMAKE_CURRENT_BINARY_DIR}/${sk_data_driver_include_dir}/config.hpp"
        )

set(sk_data_driver_public_headers
        "${sk_data_driver_include_dir}/export.hpp"
        "${sk_data_driver_include_dir}/driver.hpp"
        "${sk_data_driver_include_dir}/driver_api.hpp"
        )

set(sk_data_driver_sources
        "${sk_data_driver_public_headers}"
        "src/driver.cpp"
        )

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${sk_data_driver_sources})

list(APPEND sk_data_driver_public_headers ${sk_data_driver_gen_headers})
list(APPEND sk_data_driver_sources ${sk_data_driver_gen_headers})

target_sources(sk_data_driver PRIVATE ${sk_data_driver_sources})

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

# Boost REQUIRED COMPONENTS:
# - iostreams: for Driver files input-output
# - dll (header-only): for Driver load
find_package(Boost 1.82 REQUIRED COMPONENTS iostreams)
target_link_libraries(sk_data_driver INTERFACE Boost::boost)
