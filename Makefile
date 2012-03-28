.PHONY: all
all : Servidor Cliente

SRCFLAGS = -Wall -c
BINFLAGS = -Wall -Wno-unused-function

Lee_Archivos.o : Lee_Archivos.c
Socket.o:  Socket.c
Socket_Cliente.o : Socket_Cliente.c
Socket_Servidor.o : Socket_Servidor.c
Servidor.o : Servidor.c Socket_Servidor.h Lee_Archivos.h
Cliente.o : Cliente.c Socket_Cliente.h Socket.h

%.o :
	gcc $(SRCFLAGS) $< -o $@

Servidor: Socket.o Lee_Archivos.o Servidor.o Socket_Servidor.o
	gcc $(BINFLAGS) $^ -o $@

Cliente: Socket.o Socket_Cliente.o Cliente.o
	gcc $(BINFLAGS) $^ -o $@

.PHONY: clean
clean :
	rm *.o Cliente Servidor
