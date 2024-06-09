
#ifndef INTEGRADOR_AYP3_STUDENT_H
#define INTEGRADOR_AYP3_STUDENT_H
#define maxChar 30
#include "subject.h"
#endif //INTEGRADOR_AYP3_STUDENT_H

typedef struct student{
    char nombre[maxChar];
    char apellido[maxChar];
    int edad;
    int id;
    struct subject *anotadas;
    struct student *sig;
} Estudiante;

void darDeAltaEstudiante(Estudiante **lista);

void buscarEstudiante(Estudiante **lista);

void listarEstudiantes(Estudiante *lista);

void modificarEstudiante(Estudiante **lista);

void eliminarEstudiante(Estudiante **lista);

void incribirAMateria(Estudiante **listaEst, Materia **listaMat);

void rendirMateria(Estudiante **listaEst);

void ordenar(Estudiante **lista);

void cargarEstudiantesDesdeCsv(Estudiante **lista, char *nombreArchivo);

void guardarEstudiantesEnCsv(Estudiante **lista, char *nombreArchivo);