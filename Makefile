CC = gcc
CFLAGS = -std=c99

OBJS = smss.o queue.o  # Include queue.o in the object files list

all: smss

smss: $(OBJS)
	$(CC) $(CFLAGS) -o smss $(OBJS)

smss.o: smss.c smss.h
	$(CC) $(CFLAGS) -c smss.c

queue.o: queue.c queue.h  # Add rules for queue.o
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm -f *.o smss LogFile.txt


