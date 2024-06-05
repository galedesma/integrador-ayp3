#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "subject.h"
#define maxChar 30

typedef struct student{
    char nombre[maxChar];
    char apellido[maxChar];
    int edad;
    int id;
    struct student *sig;
} Estudiante;


void darDeAltaEstudiante (Estudiante **lista){

    int id;
    Estudiante *nuevoEstudiante  = malloc(sizeof(Estudiante));
    printf("Ingrese el nombre:\n");
    scanf("%s",nuevoEstudiante->nombre);
    printf("nombre ingresado\n\n");
    printf("Ingrese el Apellido:\n");
    scanf("%s",nuevoEstudiante->apellido);
    printf("apellido ingresado\n\n");
    printf("Ingrese la edad:\n");
    scanf("%d", &nuevoEstudiante->edad);

    printf("Estudiante agregado\n");

    nuevoEstudiante->sig = NULL;
    if(*lista == NULL){
        nuevoEstudiante->id = 1;
       *lista = nuevoEstudiante;
    } else {
        Estudiante *cursor = *lista;
        while(cursor->sig != NULL){
            cursor = cursor->sig;
        }
        nuevoEstudiante->id = cursor->id + 1;
        cursor->sig = nuevoEstudiante;
    }
    printf("el id del estudiante es: %d\n\n",nuevoEstudiante->id);
}

void buscarEstudiante(Estudiante **lista) {
    int opcion = 4;
    while (opcion != 0) {
        printf("Desea buscar por:\n");
        printf("[1] nombre\n");
        printf("[2] apellido\n");
        printf("[3] edad\n");
        printf("[4] rango de edad\n");
        printf("[0] Volver al menu\n");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1: {
                Estudiante *actual = *lista;
                char nombre[maxChar];
                printf("Inserte el nombre:\n");
                scanf("%30s", nombre);
                while (actual != NULL) {
                    if (strcmp(actual->nombre, nombre) == 0) {
                        printf("ID: %d, Nombre: %s, Apellido: %s, Edad: %d\n", actual->id, actual->nombre,
                               actual->apellido, actual->edad);
                    }
                    actual = actual->sig;
                }printf("\n");
                break;
            }

            case 2: {
                Estudiante *actual = *lista;
                char apellido[maxChar];
                printf("Inserte el apellido:\n");
                scanf("%30s", apellido);
                while (actual != NULL) {
                    if (strcmp(actual->apellido, apellido) == 0) {
                        printf("ID: %d, Nombre: %s, Apellido: %s, Edad: %d\n", actual->id, actual->nombre,actual->apellido, actual->edad);
                    }
                    actual = actual->sig;
                } printf("\n");
                break;
            }
            case 3: {
                Estudiante *actual = *lista;
                int edad;
                printf("Inserte edad:\n");
                scanf("%d", &edad);
                while (actual != NULL) {
                    if (actual->edad == edad) {
                        printf("ID: %d, Nombre: %s, Apellido: %s, Edad: %d\n", actual->id, actual->nombre,actual->apellido, actual->edad);
                    }
                    actual = actual->sig;
                } printf("\n");
                break;
            }
            case 4: {
                Estudiante *actual = *lista;
                int edadMin;
                int edadMax;
                printf("Inserte edad minima:\n");
                scanf("%d", &edadMin);
                printf("Inserte edad maxima:\n");
                scanf("%d", &edadMax);
                while (actual != NULL) {
                    if (actual->edad >= edadMin && actual->edad <= edadMax) {
                        printf("ID: %d, Nombre: %s, Apellido: %s, Edad: %d\n", actual->id, actual->nombre,actual->apellido, actual->edad);
                    }
                    actual = actual->sig;
                }printf("\n");
                break;
            }
        }
    }
}

void listarEstudiantes (Estudiante *lista){
    if(lista == NULL){
        printf("La lista esta vacia!\n\n");
    }else{
        while(lista != NULL) {
        printf("ID: %d, Nombre: %s, Apellido: %s, Edad: %d\n", lista->id, lista->nombre, lista->apellido, lista->edad);
        lista = lista->sig;
        }
    }
}

void modificarEstudiante (Estudiante **lista){
    int ID;
    int opcion = 4;

    printf("Ingrese id del estudiante a modificar:\n");
    scanf("%d",&ID);
    while(opcion != 0){
        printf("Que desea cambiar:\n");
        printf("[1] nombre\n");
        printf("[2] apellido\n");
        printf("[3] edad\n");
        printf("[0] Volver al menu\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:{
                Estudiante *actual = *lista;
                while(actual !=NULL){
                    if (actual->id == ID){
                        printf("Inserte el nombre:\n");
                        scanf("%s",actual->nombre);
                        printf("Cambio realizado\n\n");
                    }
                    actual = actual->sig;
                }

            }break;

            case 2:{
                Estudiante *actual = *lista;
                while(actual !=NULL){
                    if (actual->id == ID){
                        printf("Inserte el apellido:\n");
                        scanf("%s",actual->apellido);
                        printf("Cambio realizado\n\n");
                    }
                    actual = actual->sig;
                }

            }break;
            case 3:{
                Estudiante *actual = *lista;
                while(actual !=NULL){
                    if (actual->id == ID){
                        printf("Inserte edad:\n");
                        scanf("%d",&actual->edad);
                        printf("Cambio realizado\n\n");
                    }
                    actual = actual->sig;
                }

            }break;
        }
    }
}

void eliminarEstudiante (Estudiante **lista){
    int ID;
    printf("Ingrese id del estudiante a eliminar:\n");
    scanf("%d",&ID);
    Estudiante *actual = *lista;
    Estudiante *anterior = NULL;
    while((actual != NULL)&&(actual->id != ID)){
        anterior = actual;
        actual = actual->sig;
    }
    if(actual == NULL){
        printf("No se encontro el Estudiante o la Lista esta Vacia!\n\n");
    }else{
        if (*lista == actual) //el el primer elemento
            *lista = actual->sig;
        else
            anterior->sig = actual->sig;
            free(actual);

        printf("Estudiante ELIMINADO!\n\n");
    }
}

void incribirAMateria(Estudiante **listaEst, Materia **listaMat){
    //?????
}

void rendirMateria(Estudiante **listaEst, Materia **listaMat){
    //?????
}

void ordenar(Estudiante **lista){
    //???????????????
}


