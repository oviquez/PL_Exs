#include <stdio.h>
#include "list/list.h"
#include <stdlib.h>
#include <conio.h>
#include <mem.h>

/**
 * Cmaker: 3.17
 * Lenguaje: C
 * Estandar: C99
 * Estudiante: Daniel Rojas Rodriguez
 */

struct list * persons = NULL;

/**
 * Crea nuevas estructuras de personas
 * @param name  Nombre de la persona
 * @param money Dinero de la cuenta
 * @return la estructura con los valores
 */
struct person *newPerson(char *name,int money){
    struct person* person;
    person = (struct person*) malloc(sizeof(struct person));
    person->name = name;
    person->value = money;
    person->subList=NULL;
    return person;
}

/**
 * Crear nuevas estructuras de transacciones
 * @param isDeposit 1 si es un deposito o 0 si es un retiro
 * @param value monto de la transaccion
 * @param day día del mes
 * @param month mes del año
 * @param year año de la transaccion
 * @return la estructura con los valores
 */
struct transaction *newTransaction( int isDeposit,int value, int day, int month, int year){
    struct transaction* transaction;
    transaction = (struct transaction*) malloc(sizeof(struct transaction));
    transaction->isDeposit = isDeposit;
    transaction->value = value;
    transaction->month = month;
    transaction->year = year;
    transaction->day = day;
    return transaction;
}

/**
 * Filtro para identificar si es un deposito
 * @param node estructura de la transaccion
 * @return 1 si es una transaccion o 0 si es un retiro
 */
int isDeposit(void * node){
    return ((struct transaction*)node)->isDeposit == 1 ? 1: 0;
}

/**
 * Filtro para identificar si es un retiro
 * @param node estructura de la transaccion
 * @return 1 si es una retiro o 0 si es un transaccion
 */
int isRetirement(void * node){
    return ((struct transaction*)node)->isDeposit == 0 ? 1: 0;
}

/**
 * Filtra la cantidad que posee las cuentas
 * @param node estrucutra de la persona
 * @param money monto a superar
 * @return 1 si supera el monto o 0 si no lo supera
 */
int isOver(void * node,int money){
    return ((struct person*)node)->value > money? 1: 0;
}

/**
 * Imprime la estructua person
 * @param node estrucutra person
 */
void printPerson(void * node){
    struct person *temp =   ((struct person*)node);
    printf("Nombre: %s Dinero: %i\n",temp->name,temp->value);
}

/**
 * Imprime la estructua transacction
 * @param node estrucutra transacction
 */
void printTransaction(void * node){
    struct transaction *temp =   ((struct transaction*)node);
    printf("Deposito: %i monto: %i fecha:%i/%i/%i \n",temp->isDeposit,temp->value,temp->day,temp->month,temp->year);
}

/**
 * Convierte los nombres de las personas en mayuscula
 * @param string texto para convertir a mayusculas
 * @return
 */
char* upcase(char* string){
    char* newString = (char*) malloc(64);
    strcpy(newString,string);
    newString = strupr(newString);
    return newString;
}


int main() {
    printf("Insertando Personas\n");
    struct person *temp = newPerson("daniel",500);
    temp->subList = insertNode(temp->subList,newTransaction(1,500,01,8,2020));
    temp->subList = insertNode(temp->subList,newTransaction(1,500,01,8,2020));
    persons = insertNode(persons,temp);

    struct person *temp2 = newPerson("Pablo",1000);
    temp2->subList = insertNode(temp2->subList,newTransaction(0,500,8,2,2019));
    temp2->subList = insertNode(temp2->subList,newTransaction(0,1000,6,9,2020));
    temp2->subList = insertNode(temp2->subList,newTransaction(1,250,22,6,2018));
    persons = insertNode(persons,temp2);

    struct person *temp3 = newPerson("Steve",1000);
    temp3->subList = insertNode(temp3->subList,newTransaction(0,500,8,2,2019));
    temp3->subList = insertNode(temp3->subList,newTransaction(0,1000,6,9,2020));
    temp3->subList = insertNode(temp3->subList,newTransaction(1,250,22,6,2018));
    temp3->subList = insertNode(temp3->subList,newTransaction(1,250,22,6,2018));
    persons = insertNode(persons,temp3);

    struct person *temp4 = newPerson("Michael",1000);
    temp4->subList = insertNode(temp4->subList,newTransaction(0,50120,9,7,2017));
    persons = insertNode(persons,temp4);

    struct person *temp5 = newPerson("Manuel",100);
    temp5->subList = insertNode(temp4->subList,newTransaction(0,8000,8,2,2016));
    temp5->subList = insertNode(temp4->subList,newTransaction(1,5200,22,6,2018));
    persons = insertNode(persons,temp5);

    struct person *temp6 = newPerson("Ricardo",100000);
    persons = insertNode(persons, temp6);


    printf("\nTamano de la lista: %i\n\nLista inicial\n", getSize(persons));
    printList(persons,printPerson);


    struct  person *tempPerson = get(persons,4);
    printf("\nNueva lista con los retiros de %s\n",tempPerson->name);
    struct list* newListFilter=NULL;
    newListFilter =  map(filter(tempPerson->subList,isRetirement),NULL);
    printList(newListFilter,printTransaction);

    tempPerson = get(persons,3);
    printf("\nNueva lista con los depositos de %s\n",tempPerson->name);
    newListFilter=NULL;
    newListFilter =  map(filter(tempPerson->subList,isDeposit),NULL);
    printList(newListFilter,printTransaction);

    printf("\nLista de personas en mayuscula con un monto mayor a 500\n");
    newListFilter=NULL;
    newListFilter =  map(filter2(persons,isOver,500),upcase);
    printList(newListFilter,printPerson);

    return 0;
}
