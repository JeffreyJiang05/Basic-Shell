compile: main.o shell.o shellutil.o
	gcc -o output.out main.o shell.o shellutil.o
main.o: main.c shell.h shellutil.h
	gcc -c main.c
shell.o: shell.c shell.h
	gcc -c shell.c
shellutil.o: shellutil.c shellutil.h
	gcc -c shellutil.c
run:
	./output.out
clean:
	rm *.o
	rm *.out