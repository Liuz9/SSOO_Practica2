#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/uio.h>
#include<unistd.h>
#include<string.h>

#include "practica2.h"

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
}