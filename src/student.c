#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include "subject.h"

#define maxChar 30
#define DIRECTORIO "../archivos/estudiantes/"
#define EXTENSION ".csv"

typedef struct student{
    char nombre[maxChar];
    char apellido[maxChar];
    int edad;
    int id;
    struct subject *anotadas;
    struct student *sig;
} Estudiante;


void darDeAltaEstudiante (Estudiante **lista){
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

void darDeAltaEstudianteAlt(Estudiante **lista, const char* nombre, const char* apellido, const int edad) {
    Estudiante *nuevoEstudiante  = malloc(sizeof(Estudiante));

    strncpy(nuevoEstudiante->nombre, nombre, sizeof(nuevoEstudiante->nombre) - 1);
    strncpy(nuevoEstudiante->apellido, apellido, sizeof(nuevoEstudiante->apellido) - 1);
    nuevoEstudiante->edad = edad;

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
        if (*lista == actual) // el primer elemento
            *lista = actual->sig;
        else
            anterior->sig = actual->sig;
            free(actual);

        printf("Estudiante ELIMINADO!\n\n");
    }
}

void incribirAMateria(Estudiante **listaEst, Materia **listaMat){
    int ID;
    char nombreMat[maxChar];
    Estudiante *estudiantes = *listaEst;
    Materia *materias = *listaMat;

    printf("Ingrese id del estudiante:\n");
    scanf("%d",&ID);

    printf("Ingrese el nombre de la materia a la que desea inscribir al estudiante:\n");
    scanf("%s",nombreMat);

    Materia *materiaAInscribir = NULL;
    while(materias != NULL){
        if(strcmp(materias->nombre, nombreMat) == 0){
            materiaAInscribir = materias;
        }
        materias = materias->sig;
    }

    while(estudiantes != NULL){
        if(estudiantes->id == ID){
            estudiantes->anotadas = materiaAInscribir;
        }
        estudiantes = estudiantes->sig;
    }
    printf("Estudiante INSCRIPTO en %s\n\n",nombreMat);
}

void rendirMateria(Estudiante **listaEst){
    int ID;
    int nota;
    char nombreMat[maxChar];
    Estudiante *estudiantes = *listaEst;

    printf("Ingrese id del estudiante:\n");
    scanf("%d",&ID);

    printf("Ingrese el nombre de la materia a rendir:\n");
    scanf("%s",nombreMat);

    printf("Ingrese la nota:\n");
    scanf("%d",&nota);

    while(estudiantes != NULL){
        if(estudiantes->id == ID){
            Materia *materiasInscriptas = estudiantes->anotadas;
            while(materiasInscriptas != NULL){
                if(strcmp(materiasInscriptas->nombre, nombreMat) == 0){
                    materiasInscriptas->score = nota;
                    materiasInscriptas->approved = aprobado(nota);
                    printf("Materia RENDIDA\n");
                    if(materiasInscriptas->approved == true) {
                        printf("Nota: %d, Condicion: APROBADO\n\n", materiasInscriptas->score);
                    }else{
                        printf("Nota: %d, Condicion: DESAPROBADO\n\n", materiasInscriptas->score);
                    }
                }
                materiasInscriptas = materiasInscriptas->sig;
            }
        }
        estudiantes = estudiantes->sig;
    }
}

void cargarEstudiantesDesdeCsv(Estudiante **lista, char *nombreArchivo) {
    const int longNombreArchivo = snprintf(NULL, 0, "%s%s%s", DIRECTORIO, nombreArchivo, EXTENSION);
    char* rutaAlArchivo = malloc(longNombreArchivo + 1);
    snprintf(rutaAlArchivo, longNombreArchivo + 1, "%s%s%s", DIRECTORIO, nombreArchivo, EXTENSION);
    FILE *archivo = fopen(rutaAlArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        printf("Volviendo al menu anterior.\n\n");
        return;
    }

    char buffer[1024];
    int fila = 0;

    while(fgets(buffer, sizeof(buffer), archivo)) {
        int columna = 0;
        fila++;

        // Salteamos primer fila, consiste de encabezados.
        if (fila == 1)
            continue;

        const char* valor = strtok(buffer, ",");

        while (valor) {
            // Columna 1, posiblemente tenga que eliminarla dado que el id es autoincremental
            if (columna == 0) {
                valor = strtok(NULL, ",");
                columna++;
            }

            // Columna 2, nombre
            const char * nombre = valor;
            valor = strtok(NULL, ",");
            columna++;

            // Columna 3, apellido
            const char* apellido = valor;
            valor = strtok(NULL, ",");
            columna++;

            // Columna 4, edad
            const int edad = atoi(valor);
            valor = strtok(NULL, ",");
            columna++;

            darDeAltaEstudianteAlt(lista, nombre, apellido, edad);
        }
    }
}

void guardarEstudiantesEnCsv(Estudiante **lista, char *nombreArchivo) {

    Estudiante *actual = *lista;

    if(actual == NULL) {
        printf("No hay estudiantes para guardar!\n\n");
        return;
    }

    const int longNombreArchivo = snprintf(NULL, 0, "%s%s%s", DIRECTORIO, nombreArchivo, EXTENSION);
    char* rutaAlArchivo = malloc(longNombreArchivo + 1);
    snprintf(rutaAlArchivo, longNombreArchivo + 1, "%s%s%s", DIRECTORIO, nombreArchivo, EXTENSION);
    FILE *archivo = fopen(rutaAlArchivo, "w+");

    fprintf(archivo, "Id,Nombre,Apellido,Edad\n");

    while(actual != NULL) {
        fprintf(archivo,"%d,%s,%s,%d\n", actual->id, actual->nombre, actual->apellido, actual->edad);
        actual = actual->sig;
    }

    fclose(archivo);
}