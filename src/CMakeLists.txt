add_subdirectory(entities)

add_executable(Thrifty main.cpp)

target_link_libraries(Thrifty PRIVATE units::units)
