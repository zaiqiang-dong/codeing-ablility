CC=gcc
GCC_ARGS=
OBJS = vfork-thread \
       fork-thread  \
       clone-thread \
       pthread-thread

all: $(OBJS)

vfork-thread: ./vfork-thread.c
	$(CC) $(GCC_ARGS) -o vfork-thread ./vfork-thread.c
fork-thread: ./fork-thread.c
	$(CC) $(GCC_ARGS) -o fork-thread ./fork-thread.c
clone-thread: ./clone-thread.c
	$(CC) $(GCC_ARGS) -o clone-thread ./clone-thread.c
pthread-thread: ./pthread-thread.c
	$(CC) $(GCC_ARGS) -o pthread-thread ./pthread-thread.c -lpthread

clean:
	rm -f $(OBJS)
