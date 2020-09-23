#include <stdio.h>
#include <conio.h>

/*
 * 3) Haga un programa que cuente e indique el número de caracteres, palabras y líneas
 * de un texto. LA MISMA FORMA DE SALIR QUE EL PROGRAMA ANTERIOR
 */
int main() {

    int caracteres = 0;
    int palabras = 1;
    int lineas = 1;

    char texto[] = "Hola mundo";

    for (int i = 0; i<sizeof(texto)-1; i++){
        if (texto[i]==' '){
            palabras++;
        }
        else if (texto[i]=='\n'){
            lineas++;
        }
        caracteres++;
    }

    while (1){
        printf("\nPrecione F6");
        if(getch() == '@'){
            printf("\nSolo falta un enter\n");
            if (getchar() == 10){
                break;
            }
        }
    }

    printf("Caracteres: %d palabras: %d y lineas: %d", caracteres, palabras, lineas);
    return 0;
}
