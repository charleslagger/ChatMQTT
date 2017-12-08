CC = gcc
DEBUG = -g
CFLAGS = -Wall -lpthread -c $(DEBUG)
LFLAGS = -Wall -lpthread $(DEBUG)

server: server.o utils.o
	$(CC) $(LFLAGS) server.o utils.o -o server

server.o: server.c utils.h
	$(CC) $(CFLAGS) server.c

utils.o: utils.h utils.c
	$(CC) $(CFLAGS) utils.c

clean:
	rm -rf *.o *~ server
