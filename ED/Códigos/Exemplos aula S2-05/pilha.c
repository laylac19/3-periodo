
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "pilha.h"

/*
 typedef struct pilhaN{
     void * elem;
     struct pilhaN * next;
 }PilhaN;

 typedef struct pilha{
     PilhaN * s;
     int n;
 }Pilha;
*/

void * pop(Pilha * t){
    void * r;
    PilhaN * next;
    next = t->s->next;
    r = t->s->elem;
    t->n--;
    t->s = next;
    return r;
}


void push(Pilha * t, void * elem){
    PilhaN * new = (PilhaN *) malloc(sizeof(PilhaN));
    new->elem = elem;
    new->next = t->s;
    t->s = new;
    t->n++;
    return;
}

Pilha * criarPilha(){
    Pilha * new = (Pilha *) malloc(sizeof(Pilha));
    new->n = 0;
    new->s = NULL;
    return new;
}
void deletarPilha(Pilha * t){
    if(!t) return;
        
    PilhaN * a = t->s;
    PilhaN * next;
    while(a){
        next = a->next;
        free(a);
        a = next;
    }
    free(t);
    return;
}

