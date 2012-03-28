#include <stdio.h>
#include <stdlib.h>

int Contador_Archivos (char *Nombre,int  *Salida[3]){
	
	FILE *SuperDocumento;
	int y=0;
	int i= 0;//numero de lineas
	int j= 0;//numero de palabras
	int k= 0;//numero de letras
	char buffer[100];
	SuperDocumento=fopen(Nombre, "r");
	 if (SuperDocumento == NULL){
        printf("El archivo no existe \n");
		}
	else{
		for(i=-1;feof(SuperDocumento) == 0;i++){
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
		k = k-4;
		j=j-1;
	printf ("numero de lineas %i\n",i);
	printf ("numero de palabras %i\n",j);
	printf ("numero de caracteres %i\n",k);
	Salida[0] = i;
	Salida[1] = j;
	Salida[2] = k;	
	return Salida[3];
}

char* g_itoa(int num, char *numero){
	int pivote, usando, i;
	for(i=0;i<4;i++){
		if(i==0)usando=1000;
		else if(i==1)usando = 100;
		else if(i==2)usando = 10;
		else if(i==3)usando = 1;
		pivote = num%usando;
		numero[i] = ((num-pivote)/usando) + 48;
		num = pivote;
    }
    numero[4]='\0';
    return numero;
}
