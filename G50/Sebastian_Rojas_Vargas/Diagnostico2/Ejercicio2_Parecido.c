#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Crear lista personas
 */
struct Persona{
    char *nombre; // Pedro
    int edad; // 20
    char *id; // ab101010
};
struct nodoLista{
    struct Persona persona;
    struct nodoLista *sig;
};
struct nodoLista *cabeza =NULL;
void insertarPersona(char *nombre, int edad, char* id){
    //crear e inicializar nn
    struct nodoLista * nn=NULL;
    nn = (struct nodoLista*) malloc(sizeof(struct nodoLista));
    nn->persona.nombre = (char*) malloc(1); // para el char *nombre; hay que liberar el malo
    strcpy(nn->persona.nombre,nombre);
    nn->persona.edad = edad;
    nn->persona.id = (char*) malloc(1);
    strcpy(nn->persona.id,id);
    nn->sig = NULL;
    if (cabeza == NULL)
        cabeza = nn;
    else {
        nn->sig =cabeza;  // -> el contenido, . si es struct y no puntero
        cabeza = nn;
    }
}

/*
 * identificar el mas parecido a una muestra
 */
void parecido(char *muestra, int tamannio){
    struct nodoLista * temp = cabeza;

    int coincidenciasAnteriores = 0;
    int coincidenciasActuales = 0;

    int caracteres = 0;
    char *parecido = NULL;
    while(temp != NULL){
        for (int i = 0; i < tamannio; ++i) {
            char *caracter = temp->persona.id;
            if (muestra[i] == caracter[i]){
                coincidenciasActuales++;
            }
        }
        if (coincidenciasActuales > coincidenciasAnteriores){
            coincidenciasAnteriores = coincidenciasActuales;
            parecido = temp->persona.nombre;
            caracteres = coincidenciasActuales;
        }
        coincidenciasActuales = 0;
        temp = temp->sig;
    }
    printf("El mas parecido a la muestra es: %s, con %i caracteres iguales", parecido, caracteres);
}

/*
 * Imprimir lista y el mas parecido
 */
void imprimirLista(){
    printf("La lista es la siguiente \n");
    struct nodoLista * temp = cabeza;
    while(temp != NULL){
        printf("Nombre: %s, edad: %i, id: %s\n", temp->persona.nombre, temp->persona.edad, temp->persona.id);
        temp = temp->sig;
    }
}

int main() {
    insertarPersona("Pedro", 20, "ab1101");
    insertarPersona("Juan", 15, "111a1b");
    imprimirLista();
    parecido("ab0011", 6);
    //printf("Hello, World!\n");
    return 0;
}
