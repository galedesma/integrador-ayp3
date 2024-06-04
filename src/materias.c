#include <stdio.h>
#include <malloc.h>
#define maxChar 30

typedef struct materia{
    char nombre[maxChar];
    int id;
    struct materia *sig;
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

}

void eliminarMateria(Materia **lista){

}

void ordenarMaterias(Materia **lista){

}
