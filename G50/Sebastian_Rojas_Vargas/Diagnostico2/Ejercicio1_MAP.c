#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Palabra{
    char *texto;
};
struct nodoLista{
    struct Palabra palabra;
    struct nodoLista *sig;
};

struct nodoLista *cabeza =NULL;
void insertarPalabra(char *texto){
    struct nodoLista * nn=NULL;
    nn = (struct nodoLista*) malloc(sizeof(struct nodoLista));
    nn->palabra.texto = (char*) malloc(1);
    strcpy(nn->palabra.texto, texto);
    nn->sig = NULL;
    if (cabeza == NULL)
        cabeza = nn;
    else {
        nn->sig =cabeza;
        cabeza = nn;
    }
}

char* minuscula(char *antes){
    char *despues= strlwr(antes);
    return despues;
}

struct nodoLista* map (struct nodoLista *lista, char* (*compara)(char*)){

    struct nodoLista * cabeza1 = NULL;
    struct nodoLista * temp = lista;

    while(temp != NULL){
        char *texto = compara(temp->palabra.texto);
        struct nodoLista * nn=NULL;
        nn = (struct nodoLista*) malloc(sizeof(struct nodoLista));
        nn->palabra.texto = (char*) malloc(1);
        strcpy(nn->palabra.texto, texto);
        nn->sig = NULL;
        if (cabeza1 == NULL) {
            cabeza1 = nn;
        }
        else {
            nn->sig = cabeza1;
            cabeza1 = nn;
        }
        temp = temp->sig;
    }
    return cabeza1;
}

char* mayuscula(char *antes){
    char *despues= strupr(antes);
    return despues;
}

void imprimir(struct nodoLista* nodo){
    struct nodoLista *temp = nodo;
    while (temp != NULL){
        printf("%s \n", temp->palabra.texto);
        temp = temp->sig;
    }
}

int main() {
    insertarPalabra("Hola");
    insertarPalabra("Mundo");
    insertarPalabra("xD");

    printf("Lista original\n");
    imprimir(cabeza);

    printf("Lista mayuscula\n");
    struct nodoLista *temp = map(cabeza, mayuscula);
    imprimir(temp);

    printf("Lista minuscula\n");
    imprimir(map(cabeza, minuscula));
    return 0;
}
