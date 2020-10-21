#include <stdlib.h>
#include <conio.h>
#include "list.h"

int insertNode( void* node){
    struct list* newNode = NULL;
    newNode = (struct list*) malloc(sizeof(struct list));

    newNode->node = node;
    newNode->next = NULL;

    if (first == NULL)
        first = newNode;
    else{
        newNode->next = first;
        first = newNode;
    }
    return 1;
}


int removeNode(int index){


    if(index < 0 || first == NULL)
        return 0;

    struct list *node = first, *ant;

    if(index == 0){
        first = first->next;
        return 1;
    }

    for(int i = 0; i < index; ++i){
        if(node == NULL)
            return 0;
        ant = node;
        node = node->next;
    }
    ant->next = node->next;
    free(node);
    return 1;
}

void* get(int index){

    if(index < 0)
        return NULL;

    struct list *node = first;

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


int getSize(){
    int i=0;
    struct list *temp = first;
    if (first != NULL){
        do {
            i++;
            temp = temp->next;
        }
        while(temp!=NULL);
    }
    return i;
}

void printList( void (function)(void*)){
    struct list *temp = first;
    if (first != NULL){
        do {
            function(temp->node);
            temp = temp->next;
        }
        while(temp!=NULL);
    }
}

