cmake_minimum_required(VERSION 3.16)
project(MonProjetSFML LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)          # SFML 3 exige C++17 minimum
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # pour l'IntelliSense de VS Code

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)

set(SFML_BUILD_NETWORK OFF)   # <-- ajoute cette ligne
set(SFML_BUILD_AUDIO ON)      # garde l'audio, utile pour un jeu
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE SFML::Graphics)