cmake_minimum_required(VERSION 3.22)
project(TP1_2c2023)

set(CMAKE_C_STANDARD 23)

add_compile_options(-Wall -Werror -Wconversion)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")
set(CXXFLAGS "-Wall -Werror -Wconversion")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

include_directories(include)
include_directories(src)

add_executable(TP1_2c2023
        src/Vector.cpp
        src/Item.cpp
        main.cpp
        src/Inventario.cpp
        src/Archivos.cpp
        src/Menu.cpp
        include/Vector.hpp
        include/Item.hpp
        include/Inventario.hpp
        include/Menu.hpp
        include/Archivos.hpp
        src/Logica.cpp
        include/Logica.hpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "programa.exe")