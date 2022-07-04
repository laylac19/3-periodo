/*
	Modularize as implementações de Lista e Pilha em arquivo de cabeçalho e código e 
	construa um Makefile que seja capaz de transformá-los em arquivo objeto.

	O seu arquivo Makefile deve conter as ações:

		all: responsável por realizar todas as transformações;
		pilha.o: responsável por transformar o arquivo pilha.c/pilha.h em arquivo objeto;
		fila.o: responsável por transformar o arquivo fila.c/fila.h em arquivo objeto;
		clean: deve limpar todos os arquivos criados com as operações acima.
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
        printf ("\n\t Ação interrompida");
        
    } else {
        p->posicao++;
        p->vetPilha[p->posicao] = n;
    }
}

int desempilha (pilha *p) {
    int aux;
    
    if (estaVazia(p) == 1) {
        printf ("\n\t Ação interrompida");
        
    } else {
        aux = p->vetPilha[p->posicao];
        p->posicao--;
        
        return aux;
    }
}
