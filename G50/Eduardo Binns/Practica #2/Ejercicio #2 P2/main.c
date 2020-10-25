#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>



char verificarLetra( void * letra){
    if(isupper(*(char *)letra)){
        *(char *)letra  = tolower(*(char *)letra );
    }else{
        *(char *)letra  = toupper(*(char *)letra );
    }
}
int main() {

    char *str = (char *) malloc(1);
    scanf("%[^\n]",str);
    printf("Original %s\n", str);

    int bandera = 0;
    int contador =0;
    while (bandera == 0){
        if(isalpha(str[contador]) || isspace(str[contador])){
            verificarLetra(&str[contador]);
        }else{
            bandera = 1;
        }
        contador += 1;
    }
    printf("Cambiado %s\n", str);
    return 0;
}
