exe: sistemacompleto2.o funcoes.o
	gcc $(CFLAGS) -o exe funcoes.o sistemacompleto2.o -lpthread

sistemacompleto2.o: sistemacompleto2.c funcoes.h
	gcc $(CFLAGS) -c sistemacompleto2.c

funcoes.o: funcoes.c funcoes.h
	gcc $(CFLAGS) -c funcoes.c

clean:
	rm -f *.o exe
