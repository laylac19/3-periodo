CC = gcc
flags = -c -Wall
CFLAGS = -lm
ARQUIVOS = *.o
OBJS = list.o pilha.o fila.o principal.o
EXE = principal
MAIN = principal.c

all: list.o fila.o pilha.o principal.o
	$(CC) $(OBJS) -o $(EXE)

principal.o: principal.c
	$(CC) $(flags) $(MAIN) $(CLFLAGS)

pilha.o: pilha.c
	$(CC) $(flags) pilha.c

fila.o: fila.c
	$(CC) $(flags) fila.c

list.o: list.c
	$(CC) $(flags) list.c $(CLFLAGS)

passos: principal.c
	gcc -E principal.c -o principal.i
	gcc -S principal.i -o principal.s
	gcc -c principal.s -o principal.o
	gcc principal.o fila.o pilha.o list.o -o principal -lm


listar:
	ls $(ARQUIVOS)

clean:
	rm -f *.o *.i *.s
	rm -f $(EXE)

	

