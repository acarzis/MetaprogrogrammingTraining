﻿# CMakeList.txt : CMake project for Metaprogramming, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Metaprogramming "Metaprogramming.cpp" "Metaprogramming.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Metaprogramming PROPERTY CXX_STANDARD 20)
endif()
