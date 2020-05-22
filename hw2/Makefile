%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

CC = gcc

CFLAGS = -Wall -O -g -fPIC
LIBFLAGS = -shared -fPIC

LIBS = libcs392string.so

$(PROG): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBS): cs392_strlen.o cs392_memcpy.o
	$(CC) $(LIBFLAGS) -o $@ $^

clean:
	rm -rf *.o *.so 
