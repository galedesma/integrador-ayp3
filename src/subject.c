#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <intrin.h>
#include <string.h>

#define maxChar 60
#define DIRECTORIO "../archivos/materias/"
#define EXTENSION ".csv"

typedef struct subject{
    char nombre[maxChar];
    int id;
    int score;
    bool approved;
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

//Quizás sea necesario refactorizar funciones para desacoplar la creación de la Materia
//De los printf y scanf
void darDeAltaMateriaAlt(Materia **lista, const char* nombre) {
    Materia *nuevaMateria  = malloc(sizeof(Materia));

    strncpy(nuevaMateria->nombre, nombre, sizeof(nuevaMateria->nombre) -1);

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
}


void listarMaterias(Materia *lista){
    if(lista == NULL){
        printf("La lista esta vacia!\n\n");
    }else{
        while(lista != NULL) {
            printf("ID: %d, Materia: %s\n", lista->id, lista->nombre);
            lista = lista->sig;
        } printf("\n");
    }
}

void modificarMateria(Materia **lista){
    Materia *actual = *lista;
    int ID;

    if(actual== NULL){
        printf("La lista esta vacia!");
    }

    printf("Ingrese id de la materia a modificar:\n");
    scanf("%d",&ID);

    while(actual !=NULL){
        if (actual->id == ID){
            printf("Inserte el nuevo nombre:\n");
            scanf("%s",actual->nombre);
            printf("Cambio realizado\n\n");
        }
        actual = actual->sig;
    }
}

void eliminarMateria(Materia **lista){
    int ID;
    printf("Ingrese id de la materia a eliminar:\n");
    scanf("%d",&ID);
    Materia *actual = *lista;
    Materia *anterior = NULL;
    while((actual != NULL)&&(actual->id != ID)){
        anterior = actual;
        actual = actual->sig;
    }
    if(actual == NULL){
        printf("No se encontro la materia o la Lista esta Vacia!\n\n");
    }else{
        if (*lista == actual) // el primer elemento
            *lista = actual->sig;
        else
            anterior->sig = actual->sig;
        free(actual);

        printf("Materia ELIMINADO!\n\n");
    }
}

bool aprobado(int nota){
    return nota >=4;
}

void ordenarMaterias(Materia **lista){
    //Ordenar lista alfabeticamente?
}

void cargarMateriasDesdeCsv(Materia **lista, char *nombreArchivo) {
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

            // Columna 2, Nombre de materia
            darDeAltaMateriaAlt(lista, valor);
            valor = strtok(NULL, ",");
            columna++;
        }
    }
    fclose(archivo);
};

void guardarMateriasEnCsv(Materia **lista, char *nombreArchivo) {

    Materia *actual = *lista;

    if(actual == NULL) {
        printf("No hay materias para guardar!\n\n");
        return;
    }

    const int longNombreArchivo = snprintf(NULL, 0, "%s%s%s", DIRECTORIO, nombreArchivo, EXTENSION);
    char* rutaAlArchivo = malloc(longNombreArchivo + 1);
    snprintf(rutaAlArchivo, longNombreArchivo + 1, "%s%s%s", DIRECTORIO, nombreArchivo, EXTENSION);
    FILE *archivo = fopen(rutaAlArchivo, "w+");

    fprintf(archivo, "Id,Nombre\n");


    while(actual != NULL) {
        fprintf(archivo,"%d,%s", actual->id, actual->nombre);
        actual = actual->sig;
    }

    fclose(archivo);
}