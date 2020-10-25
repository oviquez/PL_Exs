#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>





 void calcularMedia( int arreglo[]){


}



int main() {
    int arreglo[8] = {3,2,3,8,5,1,7,4};


    int sumaTotal = 0;
    int totalElementos = 0;
    int *puntArreglo =  &arreglo[0];
    int *minimo = puntArreglo;
    int *maximo = puntArreglo;

    for (int i=0; i <8; i++){
        sumaTotal += *puntArreglo;
        totalElementos +=1;
        if(*minimo >= *puntArreglo){
            minimo = puntArreglo;
        }
        if(*maximo <= *puntArreglo){
            maximo = puntArreglo;
        }
        puntArreglo = &arreglo[i + 1];
    }

    printf("La suma total es %d \n", sumaTotal);
    printf("La media es %d \n", sumaTotal/totalElementos);
    printf("El minimo  es %d \n", *minimo);
    printf("El maximo  es %d \n", *maximo);

    return 0;
}
