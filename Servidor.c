#include <Socket_Servidor.h>
#include <Socket.h>
#include <string.h>
#include <stdio.h>
#include <Lee_Archivos.h>

main ()
{
	/*
	* Descriptores de socket servidor y de socket con el cliente
	*/
	int Socket_Servidor;
	int Socket_Cliente;
	int Dato[3];
	char Cadena[100];

	/*
	* Se abre el socket servidor, con el servicio "c_alsw" dado de
	* alta en /etc/services.
	*/
	Socket_Servidor = Abre_Socket_Inet ("c_alsw");
	if (Socket_Servidor == -1)
	{
		printf ("No se puede abrir socket servidor\n");
		exit (-1);
	}
	int i;
	for(i=1;;i++){
		printf ("Estado de espera, esperando la peticion numero  %i\n", i);	
	
	/*
	* Se espera un cliente que quiera conectarse
	*/
	Socket_Cliente = Acepta_Conexion_Cliente (Socket_Servidor);
	if (Socket_Servidor == -1)
	{
		printf ("No se puede abrir socket de cliente\n");
		exit (-1);
	}

	/*
	* Se lee la informacion del cliente, suponiendo que va a enviar 
	* 5 caracteres.
	*/
	
	Lee_Socket (Socket_Cliente, Cadena, 100);

	/*
	* Se escribe en pantalla la informacion que se ha recibido del
	* cliente
	*/
	printf ("La peticion es de contar el archivo: %s\n", Cadena);

	Contador_Archivos(Cadena,Dato);
	//printf ("El numero lineas es de: %i\n",Dato[1]);
	g_itoa(Dato[0],Cadena);	
	Escribe_Socket (Socket_Cliente, Cadena, 100);
	
	g_itoa(Dato[1],Cadena);	
	Escribe_Socket (Socket_Cliente, Cadena, 100);
	
	g_itoa(Dato[2],Cadena);	
	Escribe_Socket (Socket_Cliente, Cadena, 100);
	/*
	* Se cierran los sockets
	*/
	close (Socket_Cliente);
	}
	close (Socket_Servidor);
}
