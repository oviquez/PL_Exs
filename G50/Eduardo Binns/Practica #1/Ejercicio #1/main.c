#include <conio.h>
#include <stdio.h>


int main() {
    char arreglo[20] ;
    for (int i = 0; i < 20; i++) {
        arreglo[i] = getch();
    }
    printf("Su palabra o oracion final es %s \n", arreglo);
    int contador = 0;
    for (int i=0; i<20; i++){
        if(arreglo[i] != ' ' && arreglo[i] != -52){
            contador += 1;
        }
    }
    printf("Hay un total de %i de letras  en el arreglo\n", contador);
    return 0;
}
//cmake-build-debug\Ejercicio__1.exe