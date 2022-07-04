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

#ifndef FILA_H
#define FILA_H

typedef struct No No;
typedef struct Fila Fila;

void criarFila (Fila *f);

void enfileirar (int dado, Fila *f);

int desenfileirar (Fila *f);

void imprimirFila (Fila *f);

#endif
