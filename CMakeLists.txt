cmake_minimum_required(VERSION 2.8)
PROJECT(INJECTOR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${INJECTOR_SOURCE_DIR}/cmake")

find_package(SDL2   REQUIRED)
find_package(SDL2_ttf   REQUIRED)
find_package(SDL2_image   REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})
include_directories(${SDL2IMAGE_INCLUDE_DIR})
include_directories(include)

file(GLOB source "src/*.cpp")
add_executable(injector ${source})

target_link_libraries(
          injector
          ${SDL2_LIBRARY}
          ${SDL2_TTF_LIBRARY}
          ${SDL2IMAGE_LIBRARY}
          )