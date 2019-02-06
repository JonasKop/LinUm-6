# Linux som utvecklingsmiljö
# Övning 6. Bibliotek
# libpower.so
# VT2019
# David Sandquist

CC=gcc
INCDIR=.
CFLAGS=-c -Wall -Werror -I$(INCDIR) -fPIC 

all: libpower.o libpower.so

libpower.o: libpower.c libpower.h
	$(CC) $(CFLAGS) libpower.c libpower.h

libpower.so: libpower.o
	gcc -shared -o libpower.so libpower.o

clean:
	rm *.so *.o

install:
	chmod 644 libpower.so
	cp libpower.so /usr/local/lib/


uninstall:
	rm /usr/local/lib/libpower.so
