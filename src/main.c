#include <stdio.h>

#include "student.h"

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
                cargarMateriasDesdeCsv(lista, nombreArchivo);
                break;
            }
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
        }
    }
    return 0;
}
