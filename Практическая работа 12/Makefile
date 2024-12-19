prog: main.o background.o read_pipe.o write_pipe.o
	gcc -o result main.o background.o read_pipe.o write_pipe.o
	
main.o: main.c
	gcc -c main.c -o main.o

background.o: background.c
	gcc -c background.c -o background.o

read_pipe.o: read_pipe.c
	gcc -c read_pipe.c -o read_pipe.o

write_pipe.o: write_pipe.c
	gcc -c write_pipe.c -o write_pipe.o
