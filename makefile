compile: main.o shell.o shellutil.o redirect.o
	gcc -o shell.out main.o shell.o shellutil.o redirect.o
main.o: main.c shell.h shellutil.h redirect.o
	gcc -c main.c
shell.o: shell.c shell.h
	gcc -c shell.c
shellutil.o: shellutil.c shellutil.h
	gcc -c shellutil.c
redirect.o: redirect.c redirect.h
	gcc -c redirect.c
run:
	./shell.out
clean:
	rm *.o
	rm *.out
compileTest:
	gcc -o test.out test.c

