#include <stdio.h>

int main() {

    int arreglo1[5] = {1,5,3,67,5};
    int arreglo2[5] = {5,3,7,1,2};
    int arreglo3[5];


    int contador =0;
    while (contador < 5){
         int *punteroArreglo1 = &arreglo1[contador];
         int  *punteroArreglo2 = &arreglo2[contador];
         arreglo3[contador] = *punteroArreglo1 + *punteroArreglo2;
         contador += 1;
    }
    printf("El arreglo 1 es: ");
    for (int i = 0; i < 5; i++) {
        printf("%i,", arreglo1[i]);
    }
    printf("\nEl arreglo 2 es: ");
    for (int i = 0; i < 5; i++) {
        printf("%i,", arreglo2[i]);
    }
    printf("\nEl arreglo 3 es: ");
    for (int i = 0; i < 5; i++) {
        printf("%i,", arreglo3[i]);
    }
    return 0;
}
