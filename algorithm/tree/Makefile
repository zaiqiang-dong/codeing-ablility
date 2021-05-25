CC=gcc
CFLAGS=
LDFLAGS=
LIBS=

OBJS = serialize

all: $(OBJS)

serialize: ./datastruct/binary-tree.h ./binary-tree/serialize.c ./binary-tree/traverse.c
	$(CC) -o $@ $^

clean:
	rm -f $(OBJS)
