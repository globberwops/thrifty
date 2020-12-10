add_executable(ThriftyTest ThriftyTest.cpp EntityControllerTest.cpp
                           UnitsTest.cpp)
# $<$<CONFIG:Debug>:alloc_dbg.cpp>)

target_link_libraries(
  ThriftyTest PRIVATE doctest::doctest spdlog::spdlog_header_only units::units
                      Thrifty::Entities)

add_test(
  NAME ThriftyTest
  COMMAND ${CMAKE_COMMAND} -E env LLVM_PROFILE_FILE=ThriftyTest.profraw
          $<TARGET_FILE:ThriftyTest> --reporters=junit --out=ThriftyTest.xml)

# ~~~
# llvm-profdata-11 merge -sparse ThriftyTest.profraw -o ThriftyTest.profdata
# llvm-cov-11 show Debug/ThriftyTest -instr-profile=ThriftyTest.profdata -ignore-filename-regex="_deps" -format=html -output-dir=report
# /mnt/c/Program\ Files\ \(x86\)/Google/Chrome/Application/chrome.exe $(wslpath -w $(realpath ./report/index.html))
# ~~~

# llvm-cov-11 show Debug/ThriftyTest -instr-profile=ThriftyTest.profdata
# -show-line-counts-or-regions
