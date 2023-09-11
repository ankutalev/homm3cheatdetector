cmake_minimum_required(VERSION 3.14)

project(plugin LANGUAGES CXX)


include_directories(H3API/include)
add_library(plugin SHARED
  plugin_global.h
  plugin.cpp
  plugin.h
)
set_target_properties(plugin PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

