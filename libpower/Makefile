# Linux som utvecklingsmiljö
# Övning 6. Bibliotek
# libpower.so
# VT2019
# David Sandquist

CC=gcc
CFLAGS= -shared -fPIC

all: libpower.so

libpower.so: libpower.c libpower.h
	$(CC) $(CFLAGS) libpower.c -o libpower.so

clean:
	rm *.so

install:
	chmod 644 libpower.so
	mkdir -p /usr/local/lib/linum && cp libpower.so /usr/local/lib/linum


uninstall:
	rm /usr/local/lib/linum/libpower.so
