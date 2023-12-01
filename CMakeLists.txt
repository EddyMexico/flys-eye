cmake_minimum_required(VERSION 3.26)
project(flyeye)

set(CMAKE_CXX_STANDARD 17)

add_executable(flyeye main.cpp)

set(SFML_DIR "D:\\SFML\\SFML-2.6.0\\lib\\cmake\\SFML")
find_package(SFML 2.6 COMPONENTS graphics window system audio REQUIRED)
include_directories(D:\\SFML\\SFML-2.6.0\\include)
target_link_libraries(flyeye sfml-graphics sfml-window sfml-system sfml-audio)
