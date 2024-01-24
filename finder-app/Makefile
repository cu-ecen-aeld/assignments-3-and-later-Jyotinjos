CFLAGS = -Wall -Wextra 
SRC = writer.c

all: writer

writer: writer.o
	$(CROSS_COMPILE)gcc -g $(CFLAGS) -o writer writer.o

writer.o: writer.c
	$(CROSS_COMPILE)gcc -g $(CFLAGS) -c writer.c 

clean:
	rm -rf *.o writer