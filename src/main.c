#include <stdio.h>
#include "student.h"
#include "materias.h"

void menuEstudiantes(Estudiante **lista){
    int opcion = 7;
    while(opcion !=0){
        printf("---------MENU DE ESTUDIANTES----------\n\n");
        printf("[1] Dar de Alta Estudiante\n");
        printf("[2] Buscar Estudiante\n");
        printf("[3] Listar Estudiantes\n");
        printf("[4] Modificar Datos\n");
        printf("[5] Eliminar\n");
        printf("[6] Incribir estudiante a materia\n");
        printf("[0] Volver al Menu Principal\n");
        scanf("%d",&opcion);

        switch (opcion) {
            case 1: {
                darDeAltaEstudiante(lista);
                break;
            }
            case 2: {
                buscarEstudiante(lista);
                break;
            }
            case 3: {
                listarEstudiantes(*lista);
                break;
            }
            case 4: {
                modificarEstudiante(lista);
                break;
            }
            case 5: {
                eliminarEstudiante(lista);
                break;
            }
            case 6: {
                incribirAMateria(lista);
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
        printf("[2] Buscar Materia\n");
        printf("[3] Listar Materias\n");
        printf("[4] Modificar Datos\n");
        printf("[5] Eliminar\n");
        printf("[0] Volver al Menu principal\n");
        scanf("%d",&opcion);

        switch (opcion) {
            case 1: {
                darDeAltaMateria(lista);
                break;
            }
            case 2: {
                buscarMateria(lista);
                break;
            }
            case 3: {
                listarMaterias(*lista);
                break;
            }
            case 4: {
                modificarMateria(lista);
                break;
            }
            case 5: {
                eliminarMateria(lista);
                break;
            }
        }
    }
}

int main(void) {
    Estudiante *lista = NULL;
    int opcion = 3;
    while(opcion !=0){
        printf("---------MENU PRINCIPAL----------\n\n");
        printf("[1] Menu de Estudiantes\n");
        printf("[2] Menu de Materias\n");
        printf("[0] Salir del programa\n");
        scanf("%d",&opcion);

        switch (opcion) {
            case 1: {
                menuEstudiantes(&lista);
                break;
            }
            case 2: {
                menuMaterias(&lista);
                break;
            }
        }
    }
    return 0;
}
