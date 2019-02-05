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
        mkdir -p /usr/local/lib/libresistance
        cp libresistance.so /usr/local/lib/libresistance
        chown root.root /usr/local/lib/libresistance
        chmod 644 /usr/local/lib/libresistance/libresistance.so

uninstall:
        rm /usr/local/lib/libresistance/libresistance.so
