C = gcc
OBJS = main.o sum.o
HDRS = sum.h

prog: $(OBJS)
	$(CC) -o $@ $^

$(OBJS): $(HDRS)

clean:
	rm *.o prog
