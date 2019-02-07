# Linux som utvecklingsmiljö
# Övning 6. Bibliotek
# libresistance.so
# VT2019
# Magnus Sjögren

CC=gcc
INCDIR=.
CFLAGS=-I$(INCDIR) -shared -fPIC

libresistance.so:
	$(CC) $(CFLAGS) libresistance.c -o libresistance.so

all: libresistance.so

clean:
	rm *.so

install:
	mkdir -p /usr/local/lib/linum
	cp libresistance.so /usr/local/lib/linum
	chown root.root /usr/local/lib/linum
	chmod 644 /usr/local/lib/linum/libresistance.so

uninstall:
	rm /usr/local/lib/linum/libresistance.so
