cmake_minimum_required(VERSION 3.24)
project(PIA-ESTD)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(PIA-ESTD
        main.cpp
        src/alta.cpp
        src/baja.cpp
        src/listas.cpp
        src/modificacion.cpp
        src/pilas.cpp
        src/validaciones.cpp
        include/recuperar.h
        src/recuperar.cpp
        src/reportes.cpp
        include/reportes.h
)
