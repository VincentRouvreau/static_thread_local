cmake_minimum_required(VERSION 3.15)

project(static_thread_local LANGUAGES CXX)

if (NOT SKBUILD)
  message(ERROR "'scikit-build' is required.")
endif()

# Try to import all Python components potentially needed by nanobind
find_package(Python 3.8
  REQUIRED COMPONENTS Interpreter Development.Module
  OPTIONAL_COMPONENTS Development.SABIModule)

find_package(nanobind CONFIG REQUIRED)

set (CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0167 NEW)

add_library(get_local SHARED src/get_local.cc)
install(TARGETS get_local LIBRARY DESTINATION static_thread_local)

nanobind_add_module(static_thread_local_ext NB_STATIC NOMINSIZE src/static_thread_local_ext.cc)
target_link_libraries(static_thread_local_ext PRIVATE get_local)
add_dependencies(static_thread_local_ext get_local)
set_target_properties(static_thread_local_ext PROPERTIES
  BUILD_RPATH "$ORIGIN"        # look next to the .so at runtime
  INSTALL_RPATH "$ORIGIN"
)
install(TARGETS static_thread_local_ext LIBRARY DESTINATION static_thread_local)

nanobind_add_module(hello_local_ext NB_STATIC NOMINSIZE src/hello_local_ext.cc)
target_link_libraries(hello_local_ext PRIVATE get_local)
add_dependencies(hello_local_ext get_local)
set_target_properties(hello_local_ext PROPERTIES
  BUILD_RPATH "$ORIGIN"        # look next to the .so at runtime
  INSTALL_RPATH "$ORIGIN"
)
install(TARGETS hello_local_ext LIBRARY DESTINATION static_thread_local)
