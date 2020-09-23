#include <stdio.h>

/*
 * 4) Haga un programa que tenga dos procedimientos de intercambio de variables. Uno por
 * valor y el otro por referencia. Para el intercambio de valores por referencia debe
 * utilizarse punteros.
 */
void intercambioPorValor(){
    int x = 1;
    int y = 2;
    printf("Intercambio por valor\n");
    printf("1. Los valores son x: %i, y: %i\n", x, y);

    int z = x;
    x = y;
    y = z;
    printf("2. Los valores son x: %i, y: %i\n", x, y);
}

void intercambioPorReferencia() {
    int x = 3;
    int y = 4;
    int *p1 = &x;
    int *p2 = &y;
    int z = x;

    printf("\nIntercambio por referencia\n");
    printf("1. Los valores son x: %i, y: %i\n", x, y);

    *p1 = y;
    *p2 = z;
    printf("2. Los valores son x: %i, y: %i\n", x, y);
}

int main() {
    intercambioPorValor();
    intercambioPorReferencia();
    return 0;
}