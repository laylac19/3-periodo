/*
	Modularize as implementa��es de Lista e Pilha em arquivo de cabe�alho e c�digo e 
	construa um Makefile que seja capaz de transform�-los em arquivo objeto.

	O seu arquivo Makefile deve conter as a��es:

		all: respons�vel por realizar todas as transforma��es;
		pilha.o: respons�vel por transformar o arquivo pilha.c/pilha.h em arquivo objeto;
		fila.o: respons�vel por transformar o arquivo fila.c/fila.h em arquivo objeto;
		clean: deve limpar todos os arquivos criados com as opera��es acima.
*/

#include <stdlib.h>
#include <math.h>

#include "pilha.h"

#define TAM 5

void pilha_I (pilha *p) {
    p->posicao = -1;
}

int estaCheia (pilha *p) {
    if (p->posicao == TAM -1) {
        return 1; 
        
    } else {
        return 0;
    }
}

int estaVazia (pilha *p) {
    if (p->posicao < 0) {
        return 1; 
        
    } else {
        return 0;
    }
}

void empilha (pilha *p, int n) {
    if (estaCheia(p) == 1) {
        printf ("\n\t A��o interrompida");
        
    } else {
        p->posicao++;
        p->vetPilha[p->posicao] = n;
    }
}

int desempilha (pilha *p) {
    int aux;
    
    if (estaVazia(p) == 1) {
        printf ("\n\t A��o interrompida");
        
    } else {
        aux = p->vetPilha[p->posicao];
        p->posicao--;
        
        return aux;
    }
}
