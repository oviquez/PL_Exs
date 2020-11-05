#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

struct player{
    char name;
    int number;
};

struct nodeList{
    struct player player;
    struct nodeList *next;
};

struct nodeList *initial = NULL;

void insertPlayer( char name,int number ){
    struct nodeList * pNewNode = NULL;

    pNewNode = (struct nodeList *) malloc(sizeof(struct nodeList));
    pNewNode->player.name = name;
    pNewNode->player.number = number;
    pNewNode->next = NULL;

    if(initial == NULL)
        initial = pNewNode;
    else{
        pNewNode->next=initial;
        initial = pNewNode;

    }
}

void print(){
    struct nodeList * aux = initial;
    while (aux != NULL){
        printf("Nombre: %c Numero: %i\n",aux->player.name,aux->player.number);
        aux = aux->next;
    }
}


void executeClass3(){
    printf("\nClase 4\n");
    insertPlayer('j',10);
    insertPlayer('D',5);
    print();
}
