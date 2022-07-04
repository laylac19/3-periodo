
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef FILA_H
#define FILA_H


typedef struct filaN FilaN;

typedef struct fila Fila;

void * takeFirstFila(Fila * q);
void inserirFila(Fila * q, void * elem);

Fila * criarFila();
void deletarFila(Fila * t);


#endif
