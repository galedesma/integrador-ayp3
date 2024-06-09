#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#define DIRECTORIO "../files/"
#define EXTENSION ".csv"

void menuEstudiantes(Estudiante **listaEst, Materia **listaMat){
    int opcion = 8;
    while(opcion !=0){
        printf("---------MENU DE ESTUDIANTES----------\n\n");
        printf("[1] Dar de Alta Estudiante\n");
        printf("[2] Buscar Estudiante\n");
        printf("[3] Listar Estudiantes\n");
        printf("[4] Modificar Datos\n");
        printf("[5] Eliminar\n");
        printf("[6] Incribir estudiante a materia\n");
        printf("[7] Rendir materia\n");
        printf("[0] Volver al Menu Principal\n");
        scanf("%d",&opcion);

        switch (opcion) {
            case 1: {
                darDeAltaEstudiante(listaEst);
                break;
            }
            case 2: {
                buscarEstudiante(listaEst);
                break;
            }
            case 3: {
                listarEstudiantes(*listaEst);
                break;
            }
            case 4: {
                modificarEstudiante(listaEst);
                break;
            }
            case 5: {
                eliminarEstudiante(listaEst);
                break;
            }
            case 6: {
                incribirAMateria(listaEst, listaMat);
                break;
            }
            case 7: {
                rendirMateria(listaEst);
                break;
            }
            default:
                printf("Por favor, elija una opción válida.\n");
        }
    }
}

void menuMaterias(Materia **lista){
    int opcion = 6;
    while(opcion !=0){
        printf("---------MENU DE MATERIAS----------\n\n");
        printf("[1] Dar de Alta Materia\n");
        printf("[2] Listar Materias\n");
        printf("[3] Modificar Datos\n");
        printf("[4] Eliminar\n");
        printf("[5] Cargar Materias desde .csv\n");
        printf("[0] Volver al Menu principal\n");
        scanf("%d",&opcion);

        switch (opcion) {
            case 1: {
                darDeAltaMateria(lista);
                break;
            }
            case 2: {
                listarMaterias(*lista);
                break;
            }
            case 3: {
                modificarMateria(lista);
                break;
            }
            case 4: {
                eliminarMateria(lista);
                break;
            }
            case 5: {
                char nombreArchivo[30];
                printf("Ingrese el nombre del archivo:\n");
                scanf("%s",nombreArchivo);
                int longNombreArchivo = snprintf(NULL, 0, "%s%s%s", DIRECTORIO, nombreArchivo, EXTENSION);
                char* rutaAlArchivo = malloc(longNombreArchivo + 1);
                snprintf(rutaAlArchivo, longNombreArchivo + 1, "%s%s%s", DIRECTORIO, nombreArchivo, EXTENSION);
                printf("Ruta Completa al archivo: %s\n", rutaAlArchivo);
                cargarMateriasDesdeCsv(lista, rutaAlArchivo, 100);
                break;
            }
            default:
                printf("Por favor, elija una opción válida.\n");
        }
    }
}

int main(void) {
    Materia *listaDeMaterias = NULL;
    Estudiante *listaDeEstudiantes = NULL;

    int opcion = 3;
    while(opcion !=0){
        printf("---------MENU PRINCIPAL----------\n\n");
        printf("[1] Menu de Estudiantes\n");
        printf("[2] Menu de Materias\n");
        printf("[0] Salir del programa\n");
        scanf("%d",&opcion);

        switch (opcion) {
            case 1: {
                menuEstudiantes(&listaDeEstudiantes, &listaDeMaterias);
                break;
            }
            case 2: {
                menuMaterias(&listaDeMaterias);
                break;
            }
            default:
                printf("Por favor, elija una opción válida.\n");
        }
    }
    return 0;
}
