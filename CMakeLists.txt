cmake_minimum_required(VERSION 3.5)

project(WFC LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/SFML)

add_executable(WFC src/main.cpp src/Application.cpp src/Cell.cpp src/Grid.cpp  src/Tile.cpp src/TileCollection.cpp)
FILE(COPY res/circuit DESTINATION "${CMAKE_BINARY_DIR}")

target_include_directories(WFC PUBLIC src/SFML/include)

target_link_directories(WFC PRIVATE src/SFML/src)

target_link_libraries(WFC sfml-graphics)