
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef PILHA_H
#define PILHA_H

typedef struct pilhaN{
    void * elem;
    struct pilhaN * next;
}PilhaN;

typedef struct pilha{
    PilhaN * s;
    int n;
}Pilha;

void * pop(Pilha * t);
void push(Pilha * t, void * elem);

Pilha * criarPilha();
void deletarPilha(Pilha * t);


#endif
