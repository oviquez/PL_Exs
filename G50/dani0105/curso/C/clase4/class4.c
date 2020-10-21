//
// Created by Daniel on 29/9/2020.
//

#include <stdio.h>
#include "listaPersonas.h"
#include "map.h"

void executeClass4(){
    printf("\nClase 3\n");
    /*char *array[] = {"Palabra","ALfiuePA","Prueba"};
    char **array2 = map(array,3,up);*/


    insert(newPerson("10b10ab0",20,"juan"));
    insert(newPerson("01b11ba0",25,"pedro"));
    insert(newPerson("00a0011b",30,"prueba"));

    struct person *p = like("00a10bab");
    printf("Most Similar\nName: %s age: %i id: %s \n",p->name,p->age,p->id);
    printL();
}