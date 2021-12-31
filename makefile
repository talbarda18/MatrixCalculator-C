all: mymat.o mat.o add_func.o
	gcc -g -ansi -Wall -pedantic mymat.o mat.o add_func.c -o mymat 
	
mymat.o: mymat.c mat.h
	gcc -c -ansi -Wall -pedantic mymat.c -o mymat.o

mat.o: mat.c 
	gcc -c -ansi -Wall -pedantic mat.c -o mat.o	

add_func.o: add_func.c 
	gcc -c -ansi -Wall -pedantic add_func.c -o add_func.o	
