all: zero.c one.c
	gcc -o one.out one.c
	gcc -o zero.out zero.c
run:
	./one.out & ./zero.out
clean:
	rm *.out
