
CC=gcc
CFLAGS=-Wall -O -g `pkg-config gdlib --cflags`

LD=gcc
LDFLAGS=-g
GDLIBS=`pkg-config gdlib --libs` -lm -lrt


all: blur

blur: blur.o util.o timer.o
	$(LD) $(LDFLAGS) -o $@ $^ $(GDLIBS)


timer.o: timer.c timer.h
util.o: util.c util.h
blur.o: util.h timer.h

clean:
	-rm *.o blur
