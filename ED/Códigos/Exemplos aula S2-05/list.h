
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef LISTJV
#define LISTJV

typedef struct listA{
	void * elem;
	struct listA * next;
}listA;

typedef struct list{
	listA * lista;
	listA * next;
	int ultimo;
	int qtd;
}list;

int nothingToCompare(void * elem1, void * elem2);

void * getElemLista(listA * listb, int x);

void * getElemLikeThisLista(listA * listb, void * elem, int (*comp)(void*,void*));

listA * delElemLikeThisLista(listA * listb, void * elem, int (*comp)(void*,void*));

void * takeLast(list * lis);

void * takeFirst(list * lis);

void * getFirst(listA * listb);

void * getElemList(list * lis, int x);

void delElemLikeThis(list * lis, void * elem, int (*comp)(void *, void *));

void * getElemLikeThis(list * lis, void * elem, int (*comp)(void *, void *));

listA * criarLista(void *elem);

void * deleteLista(listA * listb);

void freeLista(listA * listb);

void freeList(list * lis);

list * createList(void);

void setNextNULL(list * lis);

void * getNext(list * lis);

int deleteList(list * lis);

listA * insertLista(listA * lista, void * elem, int (* comp)(void *, void *));

int insertList(list * lista, void * elem, int(* comp)(void *, void *));

int getQtd(list * lista);

listA * ordenaLista(listA * lista, int (*comp)(void *, void *));

void ordena(list * lista, int (*comp)(void *, void *));

void sort(list *lista, int  (*comp)(void *, void *));

#endif
