#include <stdio.h>
#include <conio.h>
#include <ctype.h>

char verificarLetra(char  letra){
    if(letra == toupper(letra)){
        letra = tolower(letra);
        return letra;
    }
    if(letra == tolower(letra)){
        letra = toupper(letra);
        return letra;
    }
}

void cambiarArreglo(char arreglo[20]) {
    char str[20];
    for (int i = 0; i < 20; i++) {
        str[i] = verificarLetra(arreglo[i]);
    }
    printf("Original %s \n", arreglo);
    printf("Cambiado %s \n", str);
}


int main() {
    char arreglo[20] ;
    for (int i = 0; i < 20; i++) {
        arreglo[i] = getch();
    }
    cambiarArreglo(arreglo);
    return 0;
}
