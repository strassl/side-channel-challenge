CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -g -c -D_XOPEN_SOURCE=500
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
