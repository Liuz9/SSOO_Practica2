#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/uio.h>
#include<unistd.h>
#include<string.h>

#include "practica2.h"

// struct evaluacion
// {
// 	char 	id[16];
// 	char 	apellido1[32];
// 	char 	apellido2[32];
// 	char 	nombre[32];
// 	float	nota1p;
// 	float nota2p;
// 	float notamedia;
// 	char 	photofilename[20];
// 	int		photosize;
// 	char 	photodata;
//};

int main()
{
	int fd, fd2;
	char buffer[128];
	char c;
	FILE *p;

	struct evaluacion alumno;

	p = fopen("datos.bin", "rb");
	while(1)
	{
		fread(&alumno, sizeof(alumno), 1, p);
		if(feof(p)!=0)
    	break;
		printf("%s %s %s\n", alumno.apellido1, alumno.apellido2, alumno.nombre);
	}
	fclose(p);
	return 0;

	// fd = open("datos.bin", O_RDONLY);
	// if(fd == -1)
	// {
	// 	printf("Error leyendo el archivo\n");
	// 	exit(0);
	// }


	// for(int i=0; i<5000; i++) {
	// 	read(fd, &c, 1);
	// 	//printf("%c", c);
	// }	
}