#include <stdio.h>
#include <Socket_Cliente.h>
#include <Socket.h>

main ()
{
	/*
	* Descriptor del socket y buffer para datos
	*/
	int Socket_Con_Servidor;
	char Cadena[100];
	char CadenaVerificacion;
	char mensaje[100];

	/*
	* Se abre la conexion con el servidor, pasando el nombre del ordenador
	* y el servicio solicitado.
	* "localhost" corresponde al nombre del mismo ordenador en el que
	* estamos corriendo. Esta dado de alta en /etc/hosts
	* "c_alsw" es un servicio dado de alta en /etc/services
	*/
	int i = 1;
	do{
	Socket_Con_Servidor = Abre_Conexion_Inet ("localhost", "c_alsw");
	if (Socket_Con_Servidor == 1)
	{
		printf ("No puedo establecer conexion con el servidor\n");
		exit (-1);
	}
	    printf("Nombre Archivo:");
		scanf("%s",mensaje);
		strcpy (Cadena, mensaje);
	    CadenaVerificacion = *mensaje;
		Escribe_Socket (Socket_Con_Servidor, Cadena, 100);
		
		Lee_Socket (Socket_Con_Servidor, Cadena, 100);
		printf ("Cantidad de lineas: %s\n", Cadena);
		
		Lee_Socket (Socket_Con_Servidor, Cadena, 100);
		printf ("Cantidad de palabras: %s\n", Cadena);
		
		Lee_Socket (Socket_Con_Servidor, Cadena, 100);
		printf ("Cantidad de Caracteres: %s\n", Cadena);
			
		printf("Quiere enviar otra peticion ??\n 1/Si o 0/No:");
		scanf("%d",&i);
	
	/*
	* Se cierra el socket con el servidor
	*/
	
	close (Socket_Con_Servidor);
	} while(i!=0);
	close (Socket_Con_Servidor);
}
