all: main

main: main.o log.o
	cc -o $@ $^

main.o: main.c log.h
	cc -o $@ -c $<

log.o: log.c log.h
	cc -o $@ -c $<

clean:
	rm -rf *.dSYM *.out *.o main