#include <stdlib.h>
#include <conio.h>
#include "list.h"

struct list* insertNode(struct list* initial, void* node){
    struct list* newNode = NULL;
    newNode = (struct list*) malloc(sizeof(struct list));
    newNode->node = malloc(sizeof(node));
    newNode->node = node;
    newNode->next = NULL;

    if (initial == NULL)
        initial = newNode;
    else{
        newNode->next = initial;
        initial = newNode;
    }
    return initial;
}

void* get(struct list* initial,int index){

    if(index < 0)
        return NULL;

    struct list *node = initial;

    if(index == 0){
        return node->node;
    }

    for(int i = 0; i < index; ++i){
        if(node == NULL)
            return NULL;
        node = node->next;
    }
    return node->node;

}

int getSize(struct list* initial){
    int i=0;
    struct list *temp = initial;
    if (initial != NULL){
        do {
            i++;
            temp = temp->next;
        }
        while(temp!=NULL);
    }
    return i;
}

void printList(struct list* initial, void (function)(void*)){
    struct list *temp = initial;
    if (initial != NULL){
        do {
            function(temp->node);
            temp = temp->next;
        }
        while(temp!=NULL);
    }
}

struct  list* map( struct list * initial , char*  (function)(char*)){
    struct list *temp = initial;
    struct list * newList = NULL;
    if (initial != NULL){
        do {
            struct person *person = ((struct person*)temp->node);
            if(function != NULL)
                person->name = function(person->name);

            newList = insertNode(newList,person);
            temp = temp->next;
        }
        while(temp!=NULL);
    }
    return newList;
}

struct  list* filter( struct list * initial ,int (function)(void*)){
    struct list *temp = initial;
    struct list * newList = NULL;
    if (initial != NULL){
        do {
            if(function(temp->node) == 1){
                newList = insertNode(newList,temp->node);
            }

            temp = temp->next;
        }
        while(temp!=NULL);
    }
    return newList;
}

struct  list* filter2( struct list * initial ,int (function)(void*, int),int value){
    struct list *temp = initial;
    struct list * newList = NULL;
    if (initial != NULL){
        do {
            if(function(temp->node,value) == 1){
                newList = insertNode(newList,temp->node);
            }

            temp = temp->next;
        }
        while(temp!=NULL);
    }
    return newList;
}


