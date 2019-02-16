# Linux som utvecklingsmiljö
# Övning 6. Bibliotek
# libcomponent.so
# VT2019
# Jonas Sjödin

CC=gcc
CFLAGS= -shared -fPIC

all: libcomponent.so

libcomponent.so: libcomponent.c libcomponent.h
	$(CC) $(CFLAGS) libcomponent.c -o libcomponent.so

clean:
	rm *.so

install:
	mkdir -p /usr/local/lib/linum && cp libcomponent.so /usr/local/lib/linum

uninstall:
	rm /usr/local/lib/linum/libcomponent.so
