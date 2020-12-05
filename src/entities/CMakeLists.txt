add_library(EntityController EntityController.cpp)
add_library(Thrifty::EntityController ALIAS EntityController)

target_include_directories(EntityController
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>)

target_link_libraries(EntityController PUBLIC units::units
                                              spdlog::spdlog_header_only)

target_compile_definitions(EntityController
                           PUBLIC $<$<CONFIG:Debug>:SPDLOG_ACTIVE_LEVEL=0>)
