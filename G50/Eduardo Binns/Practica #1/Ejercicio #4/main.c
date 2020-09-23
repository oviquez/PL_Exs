#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intercambiar_punteros(int a, int b){
    int temp = a;
    int *x = &a;
    int *y = &b;
    int *temporal = &temp;
    *x = *y;
    *y = *temporal;

    printf("El segundo fue %i y el primero %i \n", *x,*y);
}

void intercambiar(int a, int b){
    int temporal = a;
    a = b;
    b = temporal;
    printf("El segundo fue %i y el primero %i  \n", a,b);
}
int main() {
    int a = 20;
    int b = 10;
    intercambiar_punteros( a, b);
    intercambiar(a,b);
    return 0;
}

