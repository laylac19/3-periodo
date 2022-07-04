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

#ifndef FILA_H
#define FILA_H

typedef struct No No;
typedef struct Fila Fila;

void criarFila (Fila *f);

void enfileirar (int dado, Fila *f);

int desenfileirar (Fila *f);

void imprimirFila (Fila *f);

#endif
