#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "practica1/Practica1.h"
#include "clase4/listaPersonas.h"
#include "clase4//map.h"

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



void print2(char **array,int size){
    for( int i = 0; i< size; i++){
        printf("%s, ",array[i]);
    }
    printf("\n");
}

int main(){
    //countWords();
    /*int array1[10] = {1,2,3,4,5,6,7,8,9,10};
    int array2[10] = {10,9,8,7,6,5,4,3,2,1};
    sumArrays(array1,array2);*/
    /*struct calzado arrayShoes[10];
    for(short i = 0; i < 10;++i){
        arrayShoes[i] = readShoe();
    }*/
/*
    char *array[] = {"Palabra","ALfiuePA","Prueba"};
    char **array2 = map(array,3,up);
    print2(array2,3);
    /*array2 = map(array2,3,low);
    print2(array2,3);*/
    //printf("%s",array);*/

    insert(newPerson("10b10ab0",20,"juan"));
    insert(newPerson("01b11ba0",25,"pedro"));
    insert(newPerson("00a0011b",30,"prueba"));

    struct person *p = like("00a10bab");
    printf("Most Similar\nName: %s age: %i id: %s \n",p->name,p->age,p->id);
    printList();


    return 0;
}



/*
int main() {
    insertPlayer('j',10);
    insertPlayer('D',5);
    print();

    return 0;
}*/

/*
int main() {
    int x = 5;          //Variable
    int *px;            //Puntero
    px = &x;            //Hace que el puntero apunte a la variable
    char letra = 'a';
    printf("Hell %c, world %d\n",letra,*px);
    return 0;
}
*/