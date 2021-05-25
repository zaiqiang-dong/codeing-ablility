CC=gcc
CFLAGS=-I./datastruct/
LDFLAGS=
LIBS=

OBJS = serialize

all: $(OBJS)

serialize: ./datastruct/binary-tree.h ./binary-tree/serialize.c ./binary-tree/traverse.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJS)
