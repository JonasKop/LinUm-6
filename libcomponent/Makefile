# Linux som utvecklingsmiljö
# Övning 6. Bibliotek
# libresistance.so
# VT2019
# Magnus Sjögren

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
	rm /usr/local/lib/libcomponent/libcomponent.so



# This makefile installs the program into /usr/local/bin which is one of the
# places where custom binaries should be installed. To see valid install
# # locations on your system use the command "echo $PATH" and select one of those
# # or add the desirable install directory to your path.
#
# NAME=program1
# all:
#     make -C src
#     clean:
#         make -C src clean
#         install: src/$(NAME)
#             cp src/$(NAME) /usr/local/bin/$(NAME)
#             uninstall:
#                 rm /usr/local/bin/$(NAME)
