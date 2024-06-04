
#ifndef INTEGRADOR_AYP3_MATERIAS_H
#define INTEGRADOR_AYP3_MATERIAS_H

#endif //INTEGRADOR_AYP3_MATERIAS_H

typedef struct materia{
    char* nombre;
    struct materia *sig;
} Materia;

void darDeAltaMateria (Materia **lista, char *nombre);