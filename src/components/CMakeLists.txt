add_library(Components ZeroDynamics.cpp)
add_library(Thrifty::Components ALIAS Components)

target_include_directories(Components
                           PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>)

target_link_libraries(Components PUBLIC EnTT::EnTT units::units
                                        spdlog::spdlog_header_only)

target_compile_definitions(Components
                           PUBLIC $<$<CONFIG:Debug>:SPDLOG_ACTIVE_LEVEL=0>)

target_precompile_headers(
  Components PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/thrifty_pch.h>)
