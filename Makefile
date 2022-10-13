GCCFLAGS = -Wall -Wextra -O3 -pthread -g -o

GCC = gcc

all: main.c
	$(GCC) $(GCCFLAGS) main $<

clean:
	rm -rf main main.c
