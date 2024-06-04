
#ifndef INTEGRADOR_AYP3_MATERIAS_H
#define INTEGRADOR_AYP3_MATERIAS_H
#define maxChar 30
#endif //INTEGRADOR_AYP3_MATERIAS_H

typedef struct subject{
    char nombre[maxChar];
    int id;
    struct subject *sig;
} Materia;

void darDeAltaMateria (Materia **lista);

void buscarMateria(Materia **lista);

void listarMaterias(Materia *lista);

void modificarMateria(Materia **lista);

void eliminarMateria(Materia **lista);

void ordenarMaterias(Materia **lista);