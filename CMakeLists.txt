# The minimum version of CMake required
cmake_minimum_required(VERSION 3.15)
# The project name
project(TestProject)
# The C++ standard version. Can be 98 11 14 or 17
set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "E:/Libraries/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML COMPONENTS window system graphics network audio)

add_executable(TestProject main.cpp)
target_link_libraries(TestProject sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
