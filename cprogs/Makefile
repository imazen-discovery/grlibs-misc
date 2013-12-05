
CC=gcc
CFLAGS=-Wall -O -g `pkg-config gdlib --cflags`

LD=gcc
LDFLAGS=-g -lm
GDLIBS=`pkg-config gdlib --libs` -lrt


all: blur gbcoeffs

blur: blur.o util.o timer.o
	$(LD) $(LDFLAGS) -o $@ $^ $(GDLIBS)

gbcoeffs: gbcoeffs.o util.o
	$(LD) $(LDFLAGS) -o $@ $^

timer.o: timer.c timer.h
util.o: util.c util.h
blur.o: util.h timer.h
gbcoeffs.o: gbcoeffs.c util.h

clean:
	-rm *.o blur gbcoeffs
