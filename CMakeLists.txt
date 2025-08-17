cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    perceptron
    VERSION 0.1.0
    DESCRIPTION "a perceptron"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    perceptron_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    perceptron_lib ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(perceptron_lib PUBLIC cxx_std_17)

# ---- Declare executable ----

add_executable(perceptron_exe source/main.cpp)
add_executable(perceptron::exe ALIAS perceptron_exe)

set_property(TARGET perceptron_exe PROPERTY OUTPUT_NAME perceptron)

target_compile_features(perceptron_exe PRIVATE cxx_std_17)

target_link_libraries(perceptron_exe PRIVATE perceptron_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT perceptron_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of perceptron"
  )
endif()

include(cmake/dev-mode.cmake)
