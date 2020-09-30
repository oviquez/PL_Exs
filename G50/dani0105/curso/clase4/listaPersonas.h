//
// Created by Daniel on 23/9/2020.
//

#ifndef SEMANA3_LISTAPERSONAS_H
#define SEMANA3_LISTAPERSONAS_H


struct person {
    char *id;
    short age;
    char *name;
};

struct ListNode{
    struct person *person;
    struct ListNode* next;
}*header;

void insert(struct person *person);

struct person* like(char id[8]);

struct person *newPerson(char id[8], short age, char name[20]);

void printL();


#endif //SEMANA3_LISTAPERSONAS_H
