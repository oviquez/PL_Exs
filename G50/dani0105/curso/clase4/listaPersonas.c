//
// Created by Daniel on 23/9/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaPersonas.h"

void insert(struct person *person){
    struct ListNode* newPerson = NULL;

    newPerson = (struct ListNode*) malloc(sizeof(struct ListNode));

    newPerson->next = NULL;
    newPerson->person = person;

    if (header == NULL)
        header=newPerson;
    else{
        newPerson->next = header;
        header = newPerson;
    }
}

struct person* like(char id[8]){
    struct person *moreSimilar = malloc(sizeof(struct person));
    short moreSimilarPoints=0;
    for(struct ListNode *aux = header; aux != NULL; aux = aux->next){
        short similarPoints=0;
        for(short i = 0; i < 8; i++){
            if(id[i] == aux->person->id[i]){
                ++similarPoints;
            }
        }
        if(similarPoints > moreSimilarPoints){
            moreSimilar = aux->person;
            moreSimilarPoints = similarPoints;
        }
    }
    return moreSimilar;
}



struct person *newPerson(char id[8], short age, char name[20]){
    struct person* person;
    person = (struct person*) malloc(sizeof(struct person));

    person->name = name;
    person->id = id;
    person->age=age;

    return person;
}

void printL(){
    printf("Printing List\n");
    for(struct ListNode *aux = header; aux != NULL; aux = aux->next){
        struct person *p = aux->person;
        printf("Name: %s age: %i id: %s\n",p->name,p->age,p->id);
    }
}
