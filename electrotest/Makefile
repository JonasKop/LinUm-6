# Linux som utvecklingsmiljö
# Övning 6. Bibliotek
# libresistance.so
# VT2019
# David Sandquist, Jonas Sjödin, Magnus Sjögren

CC=gcc
DEBUG=-g

LIBDIR=/usr/local/lib/linum
RPATH=-Wl,-rpath=$(LIBDIR)
LFLAGS=-lcomponent -lpower -lresistance
CFLAGS=$(RPATH) $(LFLAGS) -L$(LIBDIR)

# Local test with no install
TLIBDIR=-L../libpower -L../libresistance -L../libcomponent
TRPATH=-Wl,-rpath=../libpower,-rpath=../libresistance,-rpath=../libcomponent
TCFLAGS=$(TRPATH) $(LFLAGS) $(TLIBDIR)

electrotest: electrotest.c electrotest.h
	+$(MAKE) -C ../libpower 
	+$(MAKE) -C ../libresistance
	+$(MAKE) -C ../libcomponent
	+$(MAKE) libinstall
	$(CC) electrotest.c -o electrotest $(CFLAGS)

clean:
	rm electrotest
	+$(MAKE) clean -C ../libpower
	+$(MAKE) clean -C ../libresistance
	+$(MAKE) clean -C ../libcomponent

libinstall:
	+$(MAKE) install -C ../libpower
	+$(MAKE) install -C ../libresistance
	+$(MAKE) install -C ../libcomponent

install:
	+$(MAKE) libinstall
	cp electrotest /usr/local/bin
	chown root.root /usr/local/bin/electrotest
	chmod 755 /usr/local/bin/electrotest

uninstall:
	rm /usr/local/bin/electrotest
	+$(MAKE) uninstall -C ../libpower
	+$(MAKE) uninstall -C ../libresistance
	+$(MAKE) uninstall -C ../libcomponent

test:
	+$(MAKE) -C ../libpower
	+$(MAKE) -C ../libresistance
	+$(MAKE) -C ../libcomponent
	$(CC) electrotest.c -o electrotest $(TCFLAGS)



all: electrotest install

