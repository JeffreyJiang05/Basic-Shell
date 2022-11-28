compile: main.o shell.o shellcmd.o
	gcc -o output.out main.o shell.o shellcmd.o
main.o: main.c shell.h shellcmd.h
	gcc -c main.c
shell.o: shell.c shell.h
	gcc -c shell.c
shellcmd.o: shellcmd.c shellcmd.h
	gcc -c shellcmd.c
run:
	./output.out
clean:
	rm *.o
	rm *.out