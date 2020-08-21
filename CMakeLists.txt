# The minimum version of CMake required
cmake_minimum_required(VERSION 3.15)
# The project name
project(SFMLRPG)
# The C++ standard version. Can be 98 11 14 or 17
set(CMAKE_CXX_STANDARD 17)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "Dependencies/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML COMPONENTS window graphics audio system REQUIRED)

add_executable(SFMLRPG main.cpp Game.cpp Game.h States/State.cpp States/State.h States/GameState.cpp States/GameState.h Entities/Entity.cpp Entities/Entity.h States/MainMenuState.cpp States/MainMenuState.h UI/Button.cpp UI/Button.h Entities/Player.cpp Entities/Player.h Components/MovementComponent.cpp Components/MovementComponent.h)

target_link_libraries(SFMLRPG sfml-window sfml-graphics sfml-audio sfml-system)
