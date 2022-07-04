/*
	Modularize as implementações de Lista e Pilha em arquivo de cabeçalho e código e 
	construa um Makefile que seja capaz de transformá-los em arquivo objeto.

	O seu arquivo Makefile deve conter as ações:

		all: responsável por realizar todas as transformações;
		pilha.o: responsável por transformar o arquivo pilha.c/pilha.h em arquivo objeto;
		fila.o: responsável por transformar o arquivo fila.c/fila.h em arquivo objeto;
		clean: deve limpar todos os arquivos criados com as operações acima.
*/

CC = gcc
flags = -c -Wall
CFLAGS = -lm
ARQUIVOS = *.o
OBJS = Fila.o Pilha.o Principal.o
EXE = Principal
MAIN = Principal.c

all: Fila.o Pilha.o Principal.o	
	$(CC) $(OBJS) -o $(EXE)

Principal.o: Principal.c
	$(CC) $(flags) $(MAIN) $(CLFLAGS)

Pilha.o: Pilha.c	
	//$(CC) $(flags) Pilha.c 
	gcc -c -Wall Pilha.c 
	
Fila.o: Fila.c
	//$(CC) $(flags) Fila.c
	gcc -c -Wall Fila.c 


passos: principal.c
	gcc -E Principal.c -o Principal.i
	gcc -S Principal.i -o Principal.s
	gcc -c Principal.s -o Principal.o
	gcc Principal.o Fila.o Pilha.o -o Principal -lm


listar:
	ls $(ARQUIVOS)

clean: 
	rm -f *.o *.i *.s	
	rm -f $(EXE)	
	

