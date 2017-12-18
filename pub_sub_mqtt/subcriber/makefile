CC = gcc
DEBUG = -g
CFLAGS = -Wall -lpthread -c $(DEBUG)
LFLAGS = -Wall -lpthread $(DEBUG)

sub: sub.o mqtt.o
	$(CC) $(LFLAGS) sub.o mqtt.o -o sub

sub.o: sub.c mqtt.h
	$(CC) $(CFLAGS) sub.c

mqtt.o: mqtt.h mqtt.c
	$(CC) $(CFLAGS) mqtt.c

clean:
	rm -rf *.o *~ sub
