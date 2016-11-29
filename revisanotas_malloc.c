#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>	// stat();
#include <sys/stat.h>	// stat();

#include "practica2.h"

int revisanotas(int fd) {
	int nbytes, nchanged, i, num_alumnos;
	struct evaluacion alumno;
	struct evaluacion *p_array;

	

	struct stat fileStat;
	fstat(fd, &fileStat);
	num_alumnos = fileStat.st_size/sizeof(alumno);
	printf("Número de alumnos: %i\n", num_alumnos);

	nchanged = 0;
	i = 0;

	p_array = malloc(num_alumnos * sizeof(struct evaluacion)); //	Malloc devuelve un puntero

	while(1)
	{
		nbytes = read(fd, &alumno, sizeof(alumno));
		if(nbytes == sizeof(alumno))
		{			
			if(alumno.notamedia >= 4.5 && alumno.notamedia <5)
			{
				alumno.notamedia = 5;
				nchanged++;				
			}
			p_array[i] = alumno;
			i++;
		}
		else break;
	}

	lseek(fd, 0, SEEK_SET);

	if(write(fd, p_array, num_alumnos*sizeof(alumno))!=-1) {
		printf("Escritura correcta\n");
	}

	return nchanged;
}
