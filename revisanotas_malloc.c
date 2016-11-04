#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#include "practica2.h"

int revisanotas(int fd) {
	int nbytes, nchanged, i;
	struct evaluacion alumno;
	struct evaluacion *array;

	array = malloc(217 * sizeof(struct evaluacion));

	while(1)
	{
		nbytes = (int) read(fd, &alumno, sizeof(alumno));
		if(nbytes == sizeof(alumno))
		{
			array[i] = alumno;
			i++;
		}
		else break;
	}

	printf("%s\n", array[32].nombre);
	printf("Número total de alumnos: %i\n", i);
	return nchanged;
}