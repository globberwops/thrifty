add_library(Entities EntityController.cpp)
add_library(Thrifty::Entities ALIAS Entities)

target_include_directories(Entities
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>)

target_link_libraries(
  Entities PUBLIC EnTT::EnTT units::units spdlog::spdlog_header_only
                  Thrifty::Components)

target_compile_definitions(Entities
                           PUBLIC $<$<CONFIG:Debug>:SPDLOG_ACTIVE_LEVEL=0>)

target_precompile_headers(
  Entities PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/thrifty_pch.h>)
