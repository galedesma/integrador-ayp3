#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define maxChar 30

typedef struct subject{
    char nombre[maxChar];
    int id;
    int score;
    //bool approved;
    struct subject *sig;
} Materia;

void darDeAltaMateria (Materia **lista){
    int id;
    Materia *nuevaMateria  = malloc(sizeof(Materia));

    printf("Ingrese el nombre:\n");
    scanf("%s",nuevaMateria->nombre);

    printf("Materia agregada\n");

    nuevaMateria->sig = NULL;
    if(*lista == NULL){
        nuevaMateria->id = 1;
        *lista = nuevaMateria;
    } else {
        Materia *cursor = *lista;
        while(cursor->sig != NULL){
            cursor = cursor->sig;
        }
        nuevaMateria->id = cursor->id + 1;
        cursor->sig = nuevaMateria;
    }
    printf("el id de la Materia es: %d\n\n",nuevaMateria->id);
}

void buscarMateria(Materia **lista){
   //Buscar por nombre
}

void listarMaterias(Materia *lista){
    if(lista == NULL){
        printf("La lista esta vacia!\n\n");
    }else{
        while(lista != NULL) {
            printf("ID: %d, Materia: %s\n", lista->id, lista->nombre);
            lista = lista->sig;
        }
    }
}

void modificarMateria(Materia **lista){
   //Modificar atributos como en Estudiante
}

void eliminarMateria(Materia **lista){
    //Eliminar como en Estudiante
}

void ordenarMaterias(Materia **lista){
    //Ordenar lista alfabeticamente?
}
