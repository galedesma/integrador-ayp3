
#ifndef INTEGRADOR_AYP3_MATERIAS_H
#define INTEGRADOR_AYP3_MATERIAS_H

#endif //INTEGRADOR_AYP3_MATERIAS_H

typedef struct materia{
    char* nombre;
    int id;
    struct materia *sig;
} Materia;

void darDeAltaMateria (Materia **lista);

void buscarMateria(Materia **lista);

void listarMaterias(Materia *lista);

void modificarMateria (Materia **lista);

void eliminarMateria(Materia **lista);

void ordenarMaterias(Materia **lista);