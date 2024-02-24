all: main clean

main: 
	gcc -g -c Name_generator/name_gen.c -c Create.c
	gcc name_gen.o Create.o -o test

clean:
	rm *.o
