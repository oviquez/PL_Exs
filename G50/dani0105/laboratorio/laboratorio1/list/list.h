#ifndef SEMANA3_LIST_H
#define SEMANA3_LIST_H

struct list{
    void* node;
    struct list* next;
};

struct person{
    char *name;
    int value;
    struct list *subList;
};

struct transaction{
    int isDeposit;
    int value;
    int month;
    int day;
    int year;
};

struct list* insertNode( struct list* initial, void* node);
int removeNode(struct list* initial,int index);
void* get(struct list* initial,int index);
int getSize(struct list* initial);
void printList( struct list* initial, void (function)(void*));
struct  list* filter( struct list * initial ,int (function)(void*));
struct  list* filter2( struct list * initial ,int (function)(void*, int),int value);
struct  list* map( struct list * initial , char*  (function)(char*));

#endif
