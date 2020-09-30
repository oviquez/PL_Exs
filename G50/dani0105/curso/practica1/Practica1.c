#include <stdio.h>
#include <malloc.h>
#include "Practica1.h"
#include "CTYPE.H"

int countWords() {
    char* text = (char*) malloc(10);
    scanf("%[^\n]",text);
    for(char *aux = text;*aux != '\n'; ++aux){
        if(islower(*aux)){
            *aux = toupper(*aux);
            continue;
        }
        *aux = tolower(*aux);
    }
    printf("%s",text);
    return 0;
}

void sumArrays(const int array1[10],const int array2[10]){
    int *array3 = (int*) malloc(10);
    int *aux = array3;
    for (int i = 0; i < 10; ++i) {
        *aux = array1[i] +array2[i];
        printf("%i",*aux);
        ++aux;
        printf(",");
    }
}

struct calzado readShoe(){
    struct calzado shoe;
    shoe.marca = malloc(64);
    printf("\nmarca:");
    scanf("%[^\n]",shoe.marca);
    
    printf("\nPrecio:");
    scanf("%i",&shoe.precio);

    int talla ;
    do {
        printf("\nTalla:");
        scanf("%i",&talla);
    }while ( talla < 34 || talla >44);
    shoe.talla = talla;
    return  shoe;
}

void executePractia1(){
    printf("\nPractica 1\n");
    int array1[10] = {1,2,3,4,5,6,7,8,9,10};
    int array2[10] = {10,9,8,7,6,5,4,3,2,1};
    sumArrays(array1,array2);
    struct calzado arrayShoes[10];
    for(short i = 0; i < 2;++i){
        arrayShoes[i] = readShoe();
    }
}