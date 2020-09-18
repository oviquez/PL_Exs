#include <stdio.h>
#include <string.h>
#include <ctype.h>

char verificarLetra(char * letra){
    if(*letra == toupper(*letra)){
        *letra = tolower(*letra);
        return *letra;
    }
    if(*letra == tolower(*letra)){
        *letra = toupper(*letra);
        return *letra;
    }
}
int main() {
    char str[20];

    printf("Enter a string : ");
    scanf("%s", str);
    for (int i = 0; i < 20; i++) {
        verificarLetra(&str[i]);
    }
    printf("You entered: %s", str);

    return 0;
}
