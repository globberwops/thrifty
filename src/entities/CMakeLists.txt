add_library(EntityController EntityController.cpp ZeroDynamics.cpp)
add_library(Thrifty::EntityController ALIAS EntityController)

target_include_directories(EntityController
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>)

target_link_libraries(EntityController PUBLIC EnTT::EnTT units::units
                                              spdlog::spdlog_header_only)

target_compile_definitions(EntityController
                           PUBLIC $<$<CONFIG:Debug>:SPDLOG_ACTIVE_LEVEL=0>)

target_precompile_headers(EntityController PUBLIC entities_pch.h)
