all: main clean

main: 
	gcc -g -c Name_generator/name_gen.c -c Create.c -c Job_Hobby_gen/Activity_gen.c -c Id_generator/ID_gen.c -c MISC/show_colonist.c -c Trait_gen/Trait_gen.c
	gcc name_gen.o Create.o Activity_gen.o ID_gen.o show_colonist.o Trait_gen.o -o test

clean:
	del *.o
