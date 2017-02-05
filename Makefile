CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -g -c
LFLAGS =

.PHONY: clean all

all: server

server: server.o
	$(CC) $(LFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f server
	rm -f server.o
