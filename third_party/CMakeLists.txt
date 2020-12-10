set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

include(FetchContent)

FetchContent_Declare(
  onqtam_doctest
  GIT_REPOSITORY https://github.com/globberwops/doctest.git
  GIT_TAG 2.4.1)
set(DOCTEST_NO_INSTALL ON)
set(DOCTEST_USE_STD_HEADERS ON)
FetchContent_MakeAvailable(onqtam_doctest)

FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/globberwops/json.git
  GIT_TAG develop)
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
  fmtlib_fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 7.1.2)
FetchContent_MakeAvailable(fmtlib_fmt)

FetchContent_Declare(
  gabime_spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.8.1)
set(SPDLOG_FMT_EXTERNAL_HO ON)
FetchContent_MakeAvailable(gabime_spdlog)

FetchContent_Declare(
  nholthaus_units
  GIT_REPOSITORY https://github.com/globberwops/units.git
  GIT_TAG master)
FetchContent_MakeAvailable(nholthaus_units)

FetchContent_Declare(
  skypjack_entt
  GIT_REPOSITORY https://github.com/globberwops/entt.git
  GIT_TAG master)
FetchContent_MakeAvailable(skypjack_entt)
