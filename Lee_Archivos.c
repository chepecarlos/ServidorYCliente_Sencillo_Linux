#include <stdio.h>
#include <stdlib.h>


int Contador_Archivos (char *Nombre){
	
	FILE *SuperDocumento;
	int Datos =-1;
	int caracter;
	SuperDocumento=fopen(Nombre, "r");
	 if (SuperDocumento == NULL){
        printf("El archivo no existe \n");
		}
	else{
		Datos = 1;
		 do{
            caracter = getc(SuperDocumento); 
            putchar(caracter);
            if(caracter ==  "/n")
            Datos++;
			}
        while (caracter != EOF); 
		fclose(SuperDocumento);
		}
	return Datos;
}
