#include <stdio.h>

/*
 * 5) Haga un programa que inicialice un arreglo de enteros y que recorra dicho arreglo
 * para calcular con sus elementos, la suma, media, mínimo y máximo utilizando punteros
 * para realizar estas búsquedas y cálculos.
 */
int main() {


    int arreglo[] = {1,2,3,4,5,6,7,8,9};
    int suma = 0;
    int media = 0;
    int minimo = 9999999;
    int maximo = 0;

    int i = 0;
    int *p = &i;
    for (*p; *p<(sizeof(arreglo) / sizeof(arreglo[0])); *p++){
        if (maximo < arreglo[*p]){
            maximo = arreglo[*p];
        }
        if (minimo > arreglo[*p]){
            minimo = arreglo[*p];
        }
        suma += arreglo[*p];
    }
    media = suma / (sizeof(arreglo) / sizeof(arreglo[0]) );

    printf("Suma: %i, media: %i, minimo: %i, maximo: %i\n", suma, media, minimo, maximo);
    return 0;
}
