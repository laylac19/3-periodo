
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fila.h"



typedef struct filaN{
    void * elem;
    struct filaN * next;
}FilaN;

typedef struct fila{
    FilaN * q;
    FilaN * u;
    int n;
}Fila;

void * takeFirstFila(Fila * t){
    if(t->n>0){
        FilaN * next = t->q->next;
        void * f = t->q->elem;
        t->q = next;
        t->n--;
        return f;
    }
    return NULL;
}
void inserirFila(Fila * t, void * elem){
    FilaN * new = (FilaN *) malloc(sizeof(FilaN));
    new->elem = elem;
    new->next = NULL;
    if(t->n==0){
        t->q = t->u = new;
    }else{
        t->u->next = new;
        t->u = new;
    }
    t->n++;
    return;
}

Fila * criarFila(){
    Fila * new = (Fila *) malloc(sizeof(Fila));
    new->q = new->u = NULL;
    new->n = 0;
    return new;
}

void deletarFila(Fila * t){
    if(!t) return;
        
    FilaN * a = t->q;
    FilaN * next;
    while(a){
        next = a->next;
        free(a);
        a = next;
    }
    free(t);
    return;
}


