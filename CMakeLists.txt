cmake_minimum_required(VERSION 3.18.0...3.19.1)

project(Thrifty CXX)

set(MAIN_PROJECT OFF)
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  set(MAIN_PROJECT ON)
endif()

option(Thrifty_BUILD_TESTING "Build the testing tree." ${MAIN_PROJECT})
option(Thrifty_BUILD_DOC "Build the documentation tree.")

add_subdirectory(third_party)

option(BUILD_SHARED_LIBS "Build libraries as shared." ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_DEBUG_POSTFIX d)

add_subdirectory(src)

if(Thrifty_BUILD_TESTING)
  include(CTest)
  add_subdirectory(test)
endif()

if(Thrifty_BUILD_DOC)
  add_subdirectory(doc)
endif()
