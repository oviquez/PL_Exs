#include <stdio.h>
#include <conio.h>
#include <ctype.h>


char verificarLetra( void * letra){
    if(isupper(*(char *)letra)){
        *(char *)letra  = tolower(*(char *)letra );
    }else{
        *(char *)letra  = toupper(*(char *)letra );
    }
}

int main() {
    printf("Ingrese la palabra que desea editar: ");
    char palabra[10];
    scanf("%s",&palabra);
    printf("Ingrese el primer caracter: ");
    char caracter = getch();
    printf("\nIngrese el numero: ");
    int numero;
    scanf("%d",&numero);
    if(numero >= 0 && numero < 10  ){
        if(isalpha(caracter) != 0){
            verificarLetra(&caracter);
            for (int i = 0; i < 10; i++) {
                if(palabra[i] != ' '){
                    verificarLetra(&palabra[i]);
                }
            }
            void * punteroCaracterArreglo = &palabra[numero];
            void *punteroCaracter = &caracter;
            *(char *)punteroCaracterArreglo = *(char *)punteroCaracter;
            printf("%s",palabra);
        }else{
            printf("El caracter ingresado no es validos");
        }
    }else{
        printf("El numero ingresado no es validos");
    }

    return 0;
}


