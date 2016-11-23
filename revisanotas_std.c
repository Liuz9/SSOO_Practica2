#include <unistd.h>	// read();
#include <stdio.h>	// printf();
#include <sys/types.h>	// stat();
#include <sys/stat.h>	// stat();

#include "practica2.h"

int revisanotas(int fd) {
	int nbytes, nchanged, num_alumnos;
	struct evaluacion alumno;

	struct stat fileStat;
	fstat(fd, &fileStat);
	num_alumnos = fileStat.st_size/sizeof(alumno);
	printf("Número de alumnos: %i\n", num_alumnos);

	while(1)
	{
		nbytes = (int) read(fd, &alumno, sizeof(alumno));
		if(nbytes == sizeof(alumno))
		{
			if(alumno.notamedia >= 4.5 && alumno.notamedia <5)
			{
				alumno.notamedia = 5;

				lseek(fd, -sizeof(alumno), SEEK_CUR);

				if(write(fd, &alumno, sizeof(alumno))!=-1) {
					nchanged++;
					//printf("Escritura correcta\n");
				}
			}

		}
		else break;
	}
	return nchanged;
}