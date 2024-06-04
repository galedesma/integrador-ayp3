cmake_minimum_required(VERSION 3.28)
project(integrador-ayp3 C)

set(CMAKE_C_STANDARD 11)

add_executable(integrador-ayp3 src/main.c
        src/student.c
        src/subject.c
        src/materias.c)
