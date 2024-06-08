#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <intrin.h>
#include <string.h>

#define maxChar 30

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

void cargarMateriasDesdeCsv(Materia **lista, char *nombreArchivo, size_t maxRegistros) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo.\n");
        exit(EXIT_FAILURE);
    }

    char linea[1024];
    size_t cantRegistros = 0;

    while(fgets(linea, sizeof(linea), archivo) && cantRegistros < maxRegistros) {
        char *token = strtok(linea, ",");
        if (token) {
            strcpy(lista[cantRegistros]->nombre, token);
            token = strtok(NULL, ",");
            lista[cantRegistros]->id = atoi(token);
            ++cantRegistros;
        }
    }
};