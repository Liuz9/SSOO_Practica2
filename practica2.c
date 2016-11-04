#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/uio.h>
#include<unistd.h>
#include<string.h>
#include<sys/time.h>

int revisanotas(int fd);

int main()
{
	int fd, modificados;
	struct timeval t1, t2;

	fd = open("datos.bin",O_RDWR); 
	if(fd != -1)
	{
		gettimeofday(&t1, NULL);
		modificados = revisanotas(fd);
		gettimeofday(&t2, NULL);

		printf("Notas modificadas: %i\n", modificados);
		printf("Tiempo empleado: %ius\n", t2.tv_usec-t1.tv_usec);

	}
	else printf("Error al abrir el archivo\n");

	close(fd);
	return 0;
}