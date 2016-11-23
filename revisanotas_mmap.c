#include <unistd.h>	// read();
#include <stdio.h>	// printf();
#include <sys/mman.h>
#include <sys/types.h>	// stat();
#include <sys/stat.h>	// stat();


#include "practica2.h"

int revisanotas(int fd) {
	int nbytes, nchanged, ntotal, i, num_alumnos;
	struct evaluacion alumno;
	struct evaluacion *p_array;
	
	struct stat fileStat;
	fstat(fd, &fileStat);
	num_alumnos = fileStat.st_size/sizeof(alumno);
	printf("Número de alumnos: %i\n", num_alumnos);

	p_array = mmap(NULL, 217*sizeof(alumno), PROT_WRITE, MAP_SHARED, fd, 0);
	
	
	for(i=0; i<217; i++) {
		//printf("%s\n", p_array[i].nombre);
		if(p_array[i].notamedia >= 4.5 && p_array[i].notamedia <5)
		{
			p_array[i].notamedia = 5;
			nchanged++;				
		}
	}
	if(munmap(p_array, 217*sizeof(alumno)) != -1) {
		printf("Escritura correcta\n");
	};

	return nchanged;
}
