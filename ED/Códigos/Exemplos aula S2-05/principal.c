
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fila.h"
#include "pilha.h"
#include "list.h"

#define TAM 10
#define println printf("\n")

int main(){
    //printf("%d\n", 100);
    Pilha * p = criarPilha();
    Fila * f = criarFila();
    int * v = (int *) malloc(sizeof(int)*TAM);
    for(int i = 0;i <TAM; i++){
        v[i] = (i*i)%TAM;
        push(p,v+i);
        inserirFila(f,v+i);
    }
    for(int i = 0;i <TAM; i++){
        int * x = pop(p);
        printf("%d ", x[0]);
    }
    println;
    
    for(int i = 0;i <TAM; i++){
        int * x =takeFirstFila(f);
        printf("%d ", x[0]);
    }
    println;
    
    //deletarPilha(p);
    //deletarFila(f);
    //free(v);
    return 0;
}

