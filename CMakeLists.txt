cmake_minimum_required(VERSION 3.8)

project(luna)
file(GLOB_RECURSE LunaFiles ${CMAKE_CURRENT_SOURCE_DIR}/luna/src/**.c)
add_library(${PROJECT_NAME} SHARED ${LunaFiles})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/luna/src)

project(game)
file(GLOB_RECURSE GameFiles ${CMAKE_CURRENT_SOURCE_DIR}/game/src/**.c)
add_executable(${PROJECT_NAME} ${GameFiles})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/game/src)

target_compile_definitions(luna PRIVATE LEXPORT)

target_link_libraries(game PUBLIC luna)

if (WIN32)
    target_compile_definitions(luna PUBLIC LUNA_PLATFORM_WINDOWS)
    endif ()
    
if (UNIX AND NOT APPLE)
    target_compile_definitions(luna PUBLIC LUNA_PLATFORM_LINUX)
endif ()

if (APPLE)
    target_compile_definitions(luna PUBLIC LUNA_PLATFORM_MAC)
endif ()

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(luna PUBLIC LUNA_BUILD_MODE_DEBUG)
endif()

if(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_definitions(luna PUBLIC LUNA_BUILD_MODE_RELEASE)
endif()