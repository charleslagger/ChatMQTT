CC = gcc
DEBUG = -g
CFLAGS = -Wall -lpthread -c $(DEBUG)
LFLAGS = -Wall -lpthread $(DEBUG)

pub: pub.o mqtt.o
	$(CC) $(LFLAGS) pub.o mqtt.o -o pub

pub.o: pub.c mqtt.h
	$(CC) $(CFLAGS) pub.c

mqtt.o: mqtt.h mqtt.c
	$(CC) $(CFLAGS) mqtt.c

clean:
	rm -rf *.o *~ pub