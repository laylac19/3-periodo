
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "list.h"

/*
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
*/

int LISTFLAG;

int nothingToCompare(void * elem, void * elem2){
	return -1;
}

void * getElemLista(listA * listb, int x){
	if(x==0){
		return listb->elem;
	}else{
		return getElemLista(listb->next, x-1);
	}
}

void * getElemLikeThisLista(listA * listb, void * elem, int (*comp)(void*,void*)){
	if(!listb) return NULL;
	if(! comp(elem, listb->elem)) return listb->elem;
	return getElemLikeThisLista(listb->next, elem, comp);
}

void * takeFirst(list * lis){
	listA * aux;
	listA * aux2;
	void * elem;
	
	aux = lis->lista;
	if(aux)
		elem = aux->elem;
	else
		return NULL;
	aux2 = aux->next;
	lis->lista = aux2;
	lis->qtd -= 1;
	lis->ultimo = 0;
	
	free(aux);
	
	return elem;
}

void * takeLast(list * lis){
	void * elem = NULL;
	listA * lisa;
	listA * lisb;
	if(lis){
		lis->qtd--;
		lisa = lis->lista;
		if(lisa->next){
			lisb = lisa->next;
		}else{
			elem = lisa->elem;
			free(lisa);
			return elem;
		}
		while(lisb->next){
			lisa = lisb;
			lisb = lisb->next;
		}
		lisa->next = NULL;
		elem = lisb->elem;
		free(lisb);
	}
	return elem;
}

void * getFirst(listA * listb){
	return listb->elem;
}

void * getElemList(list * lis, int x){
	if(x > lis->qtd){
		return NULL;
	}else{
		return getElemLista(lis->lista,x);
	}
}

void * getElemLikeThis(list * lis, void * elem, int (*comp)(void *, void *)){
	if(!lis || !elem){
		return NULL;
	}else{
		return getElemLikeThisLista(lis->lista,elem,comp);
	}
}

listA * delElemLikeThisLista(listA * listb, void * elem, int (*comp)(void*,void*)){
	listA * aux;
	listA * aux2;
	if(!listb)
		return NULL;
	aux = listb;
	aux2 = listb->next;
	
	if(comp(aux->elem, elem)==0){
		return aux2;
	}
	
	while(aux2){
		if(comp(aux2->elem, elem)==0){
			aux->next = aux2->next;
			free(aux2);
			LISTFLAG++;
			break;
		}
		aux = aux2;
		aux2 = aux->next;
	}
	return listb;
}

void delElemLikeThis(list * lis, void * elem, int (*comp)(void *, void *)){
	LISTFLAG = 0;
	if(lis->qtd==0){
		return;
	}else{
		lis->lista = delElemLikeThisLista(lis->lista, elem, comp);
		if(LISTFLAG)
			lis->qtd -= LISTFLAG;
	}
	return;	
}

listA * criarLista(void *elem){
	listA * listb = (listA *) malloc(sizeof(listA));
	listb->elem = elem;
	listb->next = NULL;
	return listb;
}

void * deleteLista(listA * listb){
	if(listb){
		if(listb->elem){
			free(listb->elem);
		}
		deleteLista(listb->next);
		free(listb);
	}
	return NULL;
}

void freeLista(listA * listb){
	if(listb){
		freeLista(listb->next);
		free(listb);
	}
	return;
}

void freeList(list * lis){
	if(lis){
		freeLista(lis->lista);
		free(lis);
	}
	return;
}

list * createList(void){
	list * lis = (list *) malloc(sizeof(list));
	lis->lista = NULL;
	lis->qtd = 0;
	lis->next = NULL;
	lis->ultimo = 0;
	return lis;
}

void setNextNULL(list * lis){
	lis->next = NULL;
	lis->ultimo = 0;
	return;
}

void * getNext(list * lis){
	listA * next;
	if(lis->next){
		next = lis->next;
	}else{
		if(lis->ultimo){
			lis->ultimo = 0;
			return NULL;
		}
		next = lis->lista;
	}
	lis->ultimo = 1;
	if(next){
		lis->next = next->next;
		return next->elem;
	}else{
		return NULL;
	}
	
}

int deleteList(list * lis){
	if(lis){
		deleteLista(lis->lista);
		free(lis);
		return 0;
	}
	return 1;
}

listA * insertLista(listA * lista, void * elem, int (* comp)(void *, void *)){
	listA * listb;
	if(!lista){
		listb = criarLista(elem);
		return listb;
	}else{
		if(comp(lista->elem,elem) >= 0){
			listb = criarLista(elem);
			listb->next = lista;
			return listb;
		}
		lista->next = insertLista(lista->next, elem, comp);
	}
	return lista;
}

int insertList(list * lista, void * elem, int(* comp)(void *, void *)){
	lista->next = NULL;
	lista->ultimo = 0;
	lista->qtd = lista->qtd + 1;
	lista->lista = insertLista(lista->lista, elem, comp);
	return 0;
}

int getQtd(list * lista){
	return lista->qtd;
}

listA * ordenaLista(listA * lista, int (*comp)(void *, void *)){
	listA * aux_menor=NULL, *aux_maior=NULL, *aux=NULL, *auxs=NULL;;
	auxs = lista->next;
	while(auxs){
		aux = auxs;
		auxs = auxs->next;
		if( comp(lista->elem, aux->elem) < 0){
			aux->next = aux_maior;
			aux_maior = aux;
		}else{
			aux->next = aux_menor;
			aux_menor = aux;
		}
	}
	if(aux_menor){
		aux_menor = ordenaLista(aux_menor, comp);
	}
	if(aux_maior){
		aux_maior = ordenaLista(aux_maior, comp);
	}
	lista->next = aux_maior;

	aux = aux_menor;
	if(aux_menor){
		while(aux->next){
			aux = aux->next;
		}
		aux->next = lista;
		return aux_menor;
	}else{
		return lista;
	}
}

void ordena(list * lista, int (*comp)(void *, void *)){
	lista->lista = ordenaLista(lista->lista, comp);
	lista->next = NULL;
	lista->ultimo = 0;
	return;
}

void sort(list *lista, int  (*comp)(void *, void *)){
	ordena(lista, comp);
	return;
}
