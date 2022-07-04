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

#include "Fila.h"
#include "Pilha.h"

#define TAM 10
#define println printf("\n\n")

int main() {
    Fila *f1 = (Fila*)malloc(sizeof(Fila));
    pilha *p = (pilha *)malloc(sizeof(pilha));
    
    if (f1 == NULL) {
        printf ("\n\t Erro!! \n");
        return 0;
        
    } else {
        criarFila(f1);
        
        enfileirar (10,f1);
        println;
        enfileirar (11,f1);
        println;
        enfileirar (12,f1);
        println;
        enfileirar (13,f1);
        
        imprimirFila(f1);
    /*    
        printf ("\n\t Desenfileirar \n");
        desenfileirar (f1);
        imprimirFila(f1);
    */    
    }
    
    pilha_I(p);
    
    empilha (p, 10);
    empilha (p, 0);
    empilha (p, 5);
    empilha (p, 19);
    empilha (p, 2);
    
    int aux;
    
    /*
    aux = desempilha(p);
    printf ("\n\t Retirado: %d", aux);
    */
    
    return 0;
}
