cmake_minimum_required(VERSION 3.5)

project(WFC LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(WFC main.cpp Application.cpp Cell.cpp Grid.cpp  Tile.cpp TileCollection.cpp)

FILE(GLOB_RECURSE LibFiles "*.hpp")
add_custom_target(headers SOURCES ${LibFiles})

target_link_libraries(WFC sfml-graphics)

include_directories(${CMAKE_CURRENT_LIST_DIR}/SFML/include)
target_link_libraries(WFC ${CMAKE_CURRENT_LIST_DIR}/SFML/lib)

find_package(SFML REQUIRED graphics network audio window system)
