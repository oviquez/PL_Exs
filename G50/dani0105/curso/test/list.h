#ifndef SEMANA3_LIST_H
#define SEMANA3_LIST_H


struct list{
    void* node;
    struct list* next;
} * first;


int insertNode( void* node);
int removeNode(int index);
void* get(int index);
int getSize();
void printList( void (function)(void*));

#endif //SEMANA3_LIST_H
