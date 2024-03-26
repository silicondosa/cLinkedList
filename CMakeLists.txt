## BASIC PROJECT INITIALIZATION

# Set minimum required cmake version and update cmake policy versions depending on cmake version
cmake_minimum_required(VERSION 3.28)
if(${CMAKE_VERSION} VERSION_LESS 3.28)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.28)
endif()

# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# In a top level CMakeList, create a project target with options as needed
project(cLinkedList_project	VERSION 1.0
							DESCRIPTION "A simple linked list manager for C/C++"
							LANGUAGES C CXX)

## SET UP INTERNAL LIBRARY REQUIREMENTS - MOVE TO APPS FOLDER IF THIS ISN'T A SIMPLE PROJECT
# Compile the project library with correct include directory targets and any library dependencies, compiler features
add_library(cLinkedList SHARED cLinkedList.cpp cLinkedList.h macrodef.h)
target_include_directories(cLinkedList PUBLIC include)
# target_link_libraries(cLinkedList PUBLIC ...) to include any library dependencies for this library
target_compile_features(cLinkedList PUBLIC c_std_99)

## SET UP EXECUATBLE COMPILE/BUILD - MOVE TO APPS FOLDER IF THIS ISN'T A SIMPLE PROJECT
# Build executable if you want to create 
add_executable(cLinkedList_example cLinkedList_example.cpp cLinkedList_example.h cLinkedList.h macrodef.h)
target_link_libraries(cLinkedList_example PUBLIC cLinkedList)

## TOP LEVEL PROJECT SPECIFIC CONFIGURATIONS
# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Testing only available if this is the main app
  # Note this needs to be done in the main CMakeLists
  # since it calls enable_testing, which must be in the
  # main CMakeLists.
  # include(CTest)

  # Docs only available if this is the main app
  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
# FetchContent_MakeAvailable was added in CMake 3.14; simpler usage
#include(FetchContent)

# Accumulator library
# This is header only, so could be replaced with git submodules or FetchContent
#find_package(Boost REQUIRED)
# Adds Boost::boost

# Formatting library
#FetchContent_Declare(
#  fmtlib
#  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#  GIT_TAG 5.3.0)
#FetchContent_MakeAvailable(fmtlib)
# Adds fmt::fmt

# The compiled library code is here
add_subdirectory(source)

# The executable code is here
add_subdirectory(apps)

## TESTING SPECIFIC STUFF
# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
#if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
#   AND BUILD_TESTING)
#  add_subdirectory(tests)
#endif()
