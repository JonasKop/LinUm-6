# Linux som utvecklingsmiljö
# Övning 6. Bibliotek
# libresistance.so
# VT2019
# Magnus Sjögren

CC=gcc
CFLAGS= -shared -fPIC

libresistance.so: libresistance.c libresistance.h
	$(CC) $(CFLAGS) libresistance.c -o libresistance.so

all: libresistance.so

clean:
	rm -f *.so 

install:
	mkdir -p /usr/local/lib/linum
	cp libresistance.so /usr/local/lib/linum
	chown root.root /usr/local/lib/linum
	chmod 644 /usr/local/lib/linum/libresistance.so

uninstall:
	rm /usr/local/lib/linum/libresistance.so
