cmake_minimum_required(VERSION 3.8)

project(luna)
file(GLOB_RECURSE LunaFiles ${CMAKE_CURRENT_SOURCE_DIR}/luna/src/**.c)
add_library(${PROJECT_NAME} ${LunaFiles})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/luna/src)

project(game)
file(GLOB_RECURSE GameFiles ${CMAKE_CURRENT_SOURCE_DIR}/game/src/**.c)
add_executable(${PROJECT_NAME} ${GameFiles})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/game/src)

target_link_libraries(game PUBLIC luna)