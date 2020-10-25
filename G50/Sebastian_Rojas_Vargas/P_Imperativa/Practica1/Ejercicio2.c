#include <stdio.h>
#include <conio.h>

/*
 * 2) Haga un programa que cuente la cantidad de LINEAS de un texto a leer. El fin de
 * texto lo podemos evaluar comparando el carácter con la constante EOF existente en C.
 * LA SALIDA EN WINDOWS DE ESTE PROGRAMA SERÁ PRESIONANDO LA TECLA F6 Y LUEGO ENTER
 */
int main() {
    char texto[20]= "Hola\nmundo";
    int cont = 1;

    for (int i = 0; i<sizeof(texto)-1; i++){
        if (texto[i]=='\n'){
            cont++;
        }
    }

    while (1){
	printf("Precione F6");
        if(getch() == '@'){
            printf("Solo falta un enter\n");
            if (getchar() == 10){
                break;
            }
        }
    }
    printf("Hay %d lineas\n", cont);
    return 0;
}
