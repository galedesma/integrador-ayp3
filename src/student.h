
#ifndef INTEGRADOR_AYP3_STUDENT_H
#define INTEGRADOR_AYP3_STUDENT_H
#define maxChar 30
#endif //INTEGRADOR_AYP3_STUDENT_H

typedef struct student{
    char nombre[maxChar];
    char apellido[maxChar];
    int edad;
    int id;
    struct student *sig;
} Estudiante;

void darDeAltaEstudiante(Estudiante **lista);

void buscarEstudiante(Estudiante **lista);

void listarEstudiantes(Estudiante *lista);

void modificarEstudiante(Estudiante **lista);

void eliminarEstudiante(Estudiante **lista);

void incribirAMateria(Estudiante **lista);

void ordenar(Estudiante **lista);

