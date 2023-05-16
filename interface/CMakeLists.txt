
add_library(sk_data_interface INTERFACE)
add_library(opensk::data ALIAS sk_data_interface)

set(sk_data_interface_sources "")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sk_data_interface_sources})
target_sources(sk_data_interface INTERFACE ${sk_data_interface_sources})

target_link_libraries(sk_data_interface INTERFACE opensk::data::driver)
target_link_libraries(sk_data_interface INTERFACE Boost::boost)

target_include_directories(
        sk_data_interface
        INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_compile_features(sk_data_interface INTERFACE cxx_std_20)

set_target_properties(
        sk_data_interface PROPERTIES
        PUBLIC_HEADER "${sk_data_interface_sources}"
        SOVERSION ${PROJECT_VERSION_MAJOR}
        VERSION ${PROJECT_VERSION}
)