#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct calzado{
    char * marca;
    int precio;
    int talla;
};

struct nodoLista{
    struct calzado calzado;
    struct nodoLista *sig;
};


struct nodoLista *cabeza = NULL;

void insertarCalzado(char * marca, int precio, int talla){
    if(talla >= 34 && talla<=44){
        struct nodoLista *nuevoNodo = NULL;
        nuevoNodo = (struct nodoLista *) malloc(sizeof(struct nodoLista));
        nuevoNodo->calzado.marca = (char *)malloc(1);
        strcpy(nuevoNodo->calzado.marca, marca);
        nuevoNodo->calzado.precio = precio;
        nuevoNodo->calzado.talla = talla;
        nuevoNodo->sig = NULL;
        if (cabeza == NULL){
            cabeza = nuevoNodo;
        }else{
            nuevoNodo->sig = cabeza;
            cabeza = nuevoNodo;
        }
    }else{
        printf("No se pudo agregar el calzado con marca %s, debido a que la talla %i no esta permitida\n",marca, talla );
    }

}

void imprimirLista(){

}

int main() {

    insertarCalzado("Nike",15000,35);
    insertarCalzado("Adidas",20000,33);
    insertarCalzado("Le coq sportif",10000,40);
    insertarCalzado("New Balance",25000,37);
    insertarCalzado("Converse",22500,44);
    insertarCalzado("Adidas",17500,34);
    insertarCalzado("Le coq sportif",18000,38);
    insertarCalzado("New Balance",30000,36);
    insertarCalzado("Converse",27500,43);
    insertarCalzado("Nike",23000,41);
    insertarCalzado("Adidas",16000,39);

    struct nodoLista *temp = cabeza;
    while (temp != NULL){
        printf("Marca: %s precio: %i talla: %i\n", temp->calzado.marca,temp->calzado.precio, temp->calzado.talla);
        temp = temp->sig;
    }
    return 0;
}
