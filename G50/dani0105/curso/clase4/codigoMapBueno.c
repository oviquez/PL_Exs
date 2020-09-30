#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct nodoLista{
    char* dato;
    struct nodoLista* ant;
    struct nodoLista* sig;
};

struct nodoLista* insertarNodo(struct nodoLista* lista, char* cadena){
    struct nodoLista* nn = NULL;
    nn = (struct nodoLista*) malloc(sizeof(struct nodoLista));

    nn->dato= (char*) malloc(1);
    strcpy(nn->dato,cadena);
    nn->ant=NULL;
    nn->sig=NULL;

    if (lista == NULL)
        lista=nn;
    else{
        lista->ant=nn;
        nn->sig = lista;
        lista = nn;
    }

    return lista;
}

int largoLista(struct nodoLista* lista){
    int i=0;
    struct nodoLista* temp=lista;
    if (lista!=NULL){
        do {
            i++;
            temp = temp->sig;
        }
        while(temp!=NULL);
    }
    return i;
}

void freeList(struct nodoLista* lista){
    struct nodoLista* act = lista;
    struct nodoLista* temp=NULL;
    while(act!=NULL){
        temp=act;
        act = act->sig;
        free(temp->dato);
        free(temp);
    }
}

struct nodoLista* map(struct nodoLista * lista, char* (*appliedFunction) (char*)){
    struct nodoLista* act = lista;
    struct nodoLista* nuevaLista = NULL;
    if (act != NULL)
    {
        while (act->sig!=NULL)
            act=act->sig;

        while(act!=NULL) {
            nuevaLista = insertarNodo(nuevaLista, appliedFunction(act->dato));
            act = act->ant;
        }
    }

    return nuevaLista;
}

void imprimirLista(struct nodoLista* lista){
    struct nodoLista* act = lista;
    int i=1;
    while(act!=NULL){
        printf("Cadena #%i: %s\n",i,act->dato);
        act = act->sig;
        i++;
    }
}

char* mayusculas(char* cadena){
    int j=0;
    char* newString = (char*) malloc(1);

    strcpy(newString,cadena);
    newString = strupr(newString);
    return newString;
}

char* minusculas(char* cadena){
    int j=0;
    char* newString = (char*) malloc(1);

    strcpy(newString,cadena);
    newString = strlwr(newString);
    return newString;
}

int main() {
    printf("Lista Original\n");
    struct nodoLista* cabeza=NULL;
    cabeza= insertarNodo(cabeza,"prueBA 123");
    cabeza= insertarNodo(cabeza,"MunDo : ");
    cabeza= insertarNodo(cabeza,"hoLa");
    imprimirLista(cabeza);

    printf("\nNueva Lista Mayusculas\n");
    struct nodoLista* nuevaLista=NULL;
    nuevaLista = map(cabeza,mayusculas);
    imprimirLista(nuevaLista);

    printf("\nNueva Lista Minusculas\n");
    struct nodoLista* nuevaLista2=NULL;
    nuevaLista2 = map(cabeza,minusculas);
    imprimirLista(nuevaLista2);

    printf("\nLista Original\n");
    imprimirLista(cabeza);
    freeList(cabeza);
    freeList(nuevaLista);
    freeList(nuevaLista2);

    return 0;
}

