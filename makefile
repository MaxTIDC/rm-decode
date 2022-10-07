CC      = gcc
CFLAGS  = -Wall -D_POSIX_SOURCE -D_DEFAULT_SOURCE -std=c99 -Werror -pedantic
LNKLIBS = -lm

.PHONY: all clean

all: rm_decode

rm_decode: main.o rm_decode.o $(LNKLIBS)

rm_decode.o: rm_decode.h

clean:
	rm -f $(wildcard *.o)
	rm -f rm_decode
