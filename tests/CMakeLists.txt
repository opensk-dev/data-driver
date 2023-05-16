
add_executable(smoke_test smoke.cxx)
target_link_libraries(smoke_test PRIVATE opensk::data)