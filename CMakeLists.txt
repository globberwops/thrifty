cmake_minimum_required(VERSION 3.18.0...3.19.1)

project(Thrifty CXX)

add_subdirectory(third_party)

option(BUILD_SHARED_LIBS "Build libraries as shared.")
option(BUILD_TESTING "Build the testing tree.")
option(BUILD_DOC "Build the documentation tree.")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)

if(BUILD_TESTING)
  include(CTest)
  add_subdirectory(test)
endif()

if(BUILD_DOC)
  add_subdirectory(doc)
endif()
