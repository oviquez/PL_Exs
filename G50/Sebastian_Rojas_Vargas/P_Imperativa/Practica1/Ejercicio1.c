#include <stdio.h>
#include <conio.h>

/*
 * 1)	Haga un programa de cuente las letras de un texto. Primeramente construya una
 * variable de tipo arreglo de 20 caracteres y cuente los campos que no sean blancos.
 * Luego haremos el programa final utilizando la función getch() que lee un char y lo
 * devuelve. PARA IMPRIMIR EN PANTALLA UTILIZAMOS LA FUNCIÓN printf(“texto”,variable)
 * */
int main() {
    int cont = 0;
    char letras[20] = "Juan Alonso";

    for (int i=0; i<sizeof(letras); i++){
        if (letras[i] && letras[i]!=' ') {
            // printf("En posicion %d el valor es %c   \n", i, letras[i]);
            cont++;
        }
    }
    printf("Cantidad de letras: %i", cont);
    return 0;
}

