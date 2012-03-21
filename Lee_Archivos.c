#include <stdio.h>
#include <stdlib.h>

int Contador_Archivos (char *Nombre,int  *Salida[3]){
	
	FILE *SuperDocumento;
	int y;
	int i=0;//numero de lineas
	int j=0;//numero de palabras
	int k=-1;//numero de letras
	char buffer[100];
	SuperDocumento=fopen(Nombre, "r");
	 if (SuperDocumento == NULL){
        printf("El archivo no existe \n");
		}
	else{
		for(i=0;feof(SuperDocumento) == 0;i++){
			fgets(buffer, 500 ,SuperDocumento);
			for(y=0; buffer[y]!='\0'; y++){
				if(buffer[y]==' ' || buffer[y]=='\n'){
					j++;
					}
				k++;   
				}
			}
		fclose(SuperDocumento);
		}
	printf ("numero de lineas %i\n",i);
	printf ("numero de palabras %i\n",j);
	printf ("numero de caracteres %i\n",k);
	Salida[0] = i;
	Salida[1] = j;
	Salida[2] = k;	
	return Salida[3];
}
