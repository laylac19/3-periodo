/*
	Modularize as implementa��es de Lista e Pilha em arquivo de cabe�alho e c�digo e 
	construa um Makefile que seja capaz de transform�-los em arquivo objeto.

	O seu arquivo Makefile deve conter as a��es:

		all: respons�vel por realizar todas as transforma��es;
		pilha.o: respons�vel por transformar o arquivo pilha.c/pilha.h em arquivo objeto;
		fila.o: respons�vel por transformar o arquivo fila.c/fila.h em arquivo objeto;
		clean: deve limpar todos os arquivos criados com as opera��es acima.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fila.h"

typedef struct No {
    int dado;
    struct No  *prox;
} No;

typedef struct Fila {
    No *inicio;
    No *fim;
} Fila;

void criarFila (Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileirar (int dado, Fila *f) {
    No *p = (No*)malloc(sizeof(No));
    
    if (p == NULL) {
        printf ("\n\t Erro!\n");
        return;
        
    } else {
        p->dado = dado;
        p->prox = NULL;
        
        if (f->inicio == NULL) {
            f->inicio = p;
            
        } else {
            f->fim->prox = p;
        }
        f->fim = p;
        return;
    }
}

int desenfileirar (Fila *f) {
    No *p = f->inicio;
    int dado;
    
    if (p != NULL) {
        f->inicio = p->prox;
        p->prox = NULL;
        dado = p->dado;
        free(p);
        
        if (f->inicio == NULL) {
            f->fim = NULL;
        }
        return dado;
        
    } else {
        printf ("\n\t ERRO. A fila est� vazia. \n");
    }
}

void imprimirFila (Fila *f) {
    No *p = f->inicio;
    
    if (p != NULL) {
        while (p != NULL) {
            printf ("%d \t", p->dado);
            p = p->prox;
        }
    } else {
        printf ("\n\t Fila vazia.\n");
        return;
    }
}
