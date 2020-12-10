set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

include(FetchContent)

FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/globberwops/doctest.git
  GIT_TAG 2.4.1)
set(DOCTEST_NO_INSTALL ON)
set(DOCTEST_USE_STD_HEADERS ON)
FetchContent_MakeAvailable(doctest)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/globberwops/json.git
  GIT_TAG develop)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 7.1.2)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.8.1)
set(SPDLOG_FMT_EXTERNAL_HO ON)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
  units
  GIT_REPOSITORY https://github.com/globberwops/units.git
  GIT_TAG master)
FetchContent_MakeAvailable(units)

FetchContent_Declare(
  entt
  GIT_REPOSITORY https://github.com/globberwops/entt.git
  GIT_TAG master)
FetchContent_MakeAvailable(entt)

FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG master)
FetchContent_MakeAvailable(pybind11)
