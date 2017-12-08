CC = gcc
DEBUG = -g
CFLAGS = -Wall -lpthread -c $(DEBUG)
LFLAGS = -Wall -lpthread $(DEBUG)

client: client.o utils.o
	$(CC) $(LFLAGS) client.o utils.o -o client

client.o: client.c utils.h
	$(CC) $(CFLAGS) client.c

utils.o: utils.h utils.c
	$(CC) $(CFLAGS) utils.c

clean:
	rm -rf *.o *~ client