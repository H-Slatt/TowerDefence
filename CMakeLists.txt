cmake_minimum_required(VERSION 3.28)
project(TowerDefence LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)

set(SFML_BUILD_NETWORK OFF)
FetchContent_MakeAvailable(SFML)

add_executable(main
    src/main.cpp
    src/App.cpp
    src/Enemy.cpp
    src/Grid.cpp
    src/PlayState.cpp
    src/StateManager.cpp
    src/Tower.cpp
    src/World.cpp    
		include/App.h
    include/Enemy.h
    include/Grid.h
    include/PlayState.h
    include/State.h
    include/StateManager.h
    include/Tower.h
    include/World.h)

target_compile_features(main PRIVATE cxx_std_23)
target_include_directories(main PRIVATE include)
target_link_libraries(main PRIVATE SFML::Graphics)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)