cmake_minimum_required(VERSION 2.8)
PROJECT(INJECTOR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${INJECTOR_SOURCE_DIR}/cmake")

find_package(SDL2   REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

file(GLOB source "src/*.cpp")
add_executable(injector ${source})

target_link_libraries(
          injector
          ${SDL2_LIBRARY}
          )