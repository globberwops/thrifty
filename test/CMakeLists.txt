add_executable(ThriftyTest ThriftyTest.cpp EntityControllerTest.cpp)
# $<$<CONFIG:Debug>:alloc_dbg.cpp>)

target_link_libraries(
  ThriftyTest PRIVATE doctest::doctest spdlog::spdlog_header_only
                      Thrifty::EntityController)

add_test(NAME ThriftyTest COMMAND $<TARGET_FILE:ThriftyTest> --reporters=junit
                                  --out=thrifty_test.xml)
