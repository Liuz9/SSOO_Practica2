all:	practica2.c revisanotas_malloc.c
	gcc revisanotas_malloc.c practica2.c -o ejecutable
	./ejecutable

std: practica2.c revisanotas_malloc.c
	gcc practica2.c revisanotas_std.c -o practica2_std
	./practica2_std
convert: conviertefichero.c
	gcc conviertefichero.c -o ejecutable
	./ejecutable