cmake_minimum_required(VERSION 3.9)
project(Cpp_Game_of_Life)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(Cpp_Game_of_Life main.cpp
  header/Grid.h source/Grid.cpp
  header/Cell.h source/Cell.cpp
)

target_link_libraries(Cpp_Game_of_Life
  sfml-main sfml-system sfml-window sfml-graphics sfml-audio
)