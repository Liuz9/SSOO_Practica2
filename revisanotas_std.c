#include <unistd.h>	// read();
#include <stdio.h>	// printf();

#include "practica2.h"

int revisanotas(int fd) {
	int nbytes, nchanged, ntotal;
	struct evaluacion alumno;

	while(1)
	{
		nbytes = (int) read(fd, &alumno, sizeof(alumno));
		if(nbytes == sizeof(alumno))
		{
			ntotal++;
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