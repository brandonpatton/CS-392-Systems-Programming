# I pledge my honor that I have abided by the Stevens Honor System.
# Brandon Patton
# Makefile

CC = gcc

CFLAGS = -pthread
OBJS = cs392_thread.o
RM = rm -f

cs392_thread: $(OBJS)
	$(CC) $(CFLAGS) -o cs392_thread $(OBJS)

cs392_thread.o: cs392_thread.c
	$(CC) -o cs392_thread.o -c cs392_thread.c

clean:
	rm -rf *.o cs392_thread












