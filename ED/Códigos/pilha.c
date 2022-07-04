#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct pilha {
    int vetPilha[TAM];
    int posicao;
} pilha;

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

void imprimir (pilha *p) {
    for (int i = 0; i < p->posicao; ++i)
    {
        printf("%d ", p->vetPilha[i]);
    }
}

int main() {
    pilha *p = (pilha *)malloc(sizeof(pilha));
    pilha *p2 = (pilha *)malloc(sizeof(pilha));
    
    pilha_I(p);
    pilha_I(p2);
    
    empilha (p, 10);
    empilha (p, 0);
    empilha (p, 5);
    empilha (p, 19);

    empilha (p2, 1);
    empilha (p2, 2);
    empilha (p2, 3);
    empilha (p2, 4);

    printf("PILHA 1\n");
    imprimir (p);
    printf("\n");

    printf("PILHA 2\n");
    imprimir (p2);
    printf("\n");
    
    int aux;
    aux = desempilha(p);
    printf ("\n\t Retirado: %d", aux);
    imprimir (p);

    int aux2;
    aux2 = desempilha(p2);
    printf ("\n\t Retirado: %d", aux2);
    imprimir (p2);


    return 0;
}


