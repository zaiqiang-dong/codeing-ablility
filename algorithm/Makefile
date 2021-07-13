CC=gcc
CFLAGS=-I./include
LDFLAGS=
LIBS=

OBJS = serialize

all: $(OBJS)

serialize: ./binary-tree/serialize.c ./binary-tree/traverse.c ./test/test-serialize.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJS)
