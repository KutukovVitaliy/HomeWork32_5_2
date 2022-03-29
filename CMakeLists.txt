cmake_minimum_required(VERSION 3.20)
project(HomeWork32_5_2)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(nlohmann_json)
add_executable(HomeWork32_5_2 main.cpp)
target_link_libraries(HomeWork32_5_2 PRIVATE nlohmann_json::nlohmann_json)