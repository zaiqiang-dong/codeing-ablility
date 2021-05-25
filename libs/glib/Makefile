CC=gcc
CFLAGS=$(shell pkg-config --cflags glib-2.0) -I../../
LDFLAGS=$(shell pkg-config --libs glib-2.0)
LIBS=

OBJS = glib-idle-event \
       glib-idle-diy-event \
       glib-timeout-event \
       glib-timeout-diy-event \
       glib-io-event \
       glib-io-diy-event


all: $(OBJS)

glib-idle-event: ./glib-idle-event.c ../../util/util.c ../../util/util.h
	$(CC) -o $@  $^ $(CFLAGS) $(LDFLAGS)

glib-idle-diy-event: ./glib-idle-diy-event.c ../../util/util.c ../../util/util.h
	$(CC) -o $@  $^ $(CFLAGS) $(LDFLAGS)

glib-timeout-event: ./glib-timeout-event.c ../../util/util.c ../../util/util.h
	$(CC) -o $@  $^ $(CFLAGS) $(LDFLAGS)

glib-timeout-diy-event: ./glib-timeout-diy-event.c ../../util/util.c ../../util/util.h
	$(CC) -o $@  $^ $(CFLAGS) $(LDFLAGS)

glib-io-event: ./glib-io-event.c ../../util/util.c ../../util/util.h
	$(CC) -o $@  $^ $(CFLAGS) $(LDFLAGS)

glib-io-diy-event: ./glib-io-diy-event.c ../../util/util.c ../../util/util.h
	$(CC) -o $@  $^ $(CFLAGS) $(LDFLAGS)
clean:
	rm -f $(OBJS)
