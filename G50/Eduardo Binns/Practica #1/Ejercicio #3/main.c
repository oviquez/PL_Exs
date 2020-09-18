#include <stdio.h>
#include <conio.h>

int main() {


    char arreglo[] = "Hola Juan \ndon \nbinns \ndhn";

    int lineas = 0;
    int palabras = 0;
    int caracteres = 0;
    for (int i = 0; i < sizeof(arreglo); i++) {

        if(arreglo[i] != ' ' && arreglo[i] != '\0' && arreglo[i] != '\n'){
            caracteres += 1;
        }
        if(arreglo[i] == ' '  || arreglo[i] == '\0'){
            palabras +=1;
        }
        if (arreglo[i] == '\n' || arreglo[i] == '\0') {
            lineas += 1;
        }
    }
    printf("Lineas %i\n", lineas);
    printf("Palabras %i\n", palabras);
    printf("Caracteres %i\n", caracteres);

    while(1){
        if(getch() == '@'){
            printf("a");
            if(getchar() == 10 ){
                printf("aa");
                break;
            }
        }
    }
    return 0;

}
