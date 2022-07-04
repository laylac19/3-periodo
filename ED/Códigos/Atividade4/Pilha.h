/*
	Modularize as implementações de Lista e Pilha em arquivo de cabeçalho e código e 
	construa um Makefile que seja capaz de transformá-los em arquivo objeto.

	O seu arquivo Makefile deve conter as ações:

		all: responsável por realizar todas as transformações;
		pilha.o: responsável por transformar o arquivo pilha.c/pilha.h em arquivo objeto;
		fila.o: responsável por transformar o arquivo fila.c/fila.h em arquivo objeto;
		clean: deve limpar todos os arquivos criados com as operações acima.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef PILHA_H
#define PILHA_H

typedef struct pilha {
    int vetPilha[TAM];
    int posicao;
} pilha;

void pilha_I (pilha *p);

int estaCheia (pilha *p);

int estaVazia (pilha *p);

void empilha (pilha *p, int n);

int desempilha (pilha *p);

#endif

