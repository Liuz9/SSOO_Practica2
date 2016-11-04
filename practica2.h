#ifndef _PRACTICA2_H_	
#define _PRACTICA2_H_
/* 
	Al hacer un #include se pega el texto de la librería directamente sobre
	el propio fichero .c, por lo que se puede dar una situación de dependencia
	circular. Por lo tanto, se define si no está definido al principio de cada
	librería con el nombre de ésta.
*/

struct evaluacion {
	char id[16];
	char apellido1[32];
	char apellido2[32];
	char nombre[32];
	float nota1p;
	float nota2p;
	float notamedia;
	char photofilename[20];
	int photosize;
	char photodata[16000];
};
#endif