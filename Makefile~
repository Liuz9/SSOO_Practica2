all:	practica2.c revisanotas_malloc.c
	tar -xzvf datos.tgz
	gcc revisanotas_malloc.c practica2.c -o ejecutable
	./ejecutable

std: 	practica2.c revisanotas_std.c practica2.h datos.tgz
	tar -xzvf datos.tgz
	gcc -Wall practica2.c revisanotas_std.c -o practica2_std
	./practica2_std
	./convert

malloc:	practica2.c revisanotas_malloc.c practica2.h datos.tgz
	tar -xzvf datos.tgz
	gcc -Wall revisanotas_malloc.c practica2.c -o practica2_malloc
	./practica2_malloc
	./convert

mmap:	practica2.c revisanotas_mmap.c practica2.h datos.tgz
	tar -xzvf datos.tgz
	gcc -Wall revisanotas_mmap.c practica2.c -o practica2_mmap
	./practica2_mmap
	./convert

convert: conviertefichero.c
	gcc conviertefichero.c -o convert
	./convert

clean: 
	rm practica2_std practica2_malloc practica2_mmap

datos: 	datos.tgz
	tar -xzvf datos.tgz

std_assambler:
	gcc practica2.c -S -o practica2.s

std_static:	practica2.c revisanotas_std.c practica2.h datos.tgz
	tar -xzvf datos.tgz
	gcc -static practica2.c revisanotas_std.c -o practica2_std
	./practica2_std
	./convert