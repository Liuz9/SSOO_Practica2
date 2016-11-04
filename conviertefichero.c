#include <stdio.h>			// fopen();
#include <fcntl.h>			// open();
#include <sys/types.h>	// read();
#include <sys/uio.h>		// read();
#include <unistd.h>			// read();


#include "practica2.h"

int main()
{
	int fdread;
	int i, nbytes;
	struct evaluacion alumno;

	FILE *fwrite;

	fdread = open("datos.bin", O_RDONLY);
	fwrite = fopen("datos.txt", "w");

	if(fdread != -1)
	{
		while(1)
		{
			nbytes = (int) read(fdread, &alumno, sizeof(alumno));
			if(nbytes == sizeof(alumno))
			{
				i++;
				fprintf(fwrite, "%i.- %s %s, %s %3.2f\n", i, alumno.apellido1, alumno.apellido2, alumno.nombre, alumno.notamedia);
			}
			else break;
		}
	}
	else printf("Error al abrir los archivos\n");

	close(fdread);
	fclose(fwrite);
	return 0;
}