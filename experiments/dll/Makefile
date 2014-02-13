PATH		:= $(shell ./cfg.sh path)
SO			:= $(shell ./cfg.sh sharedobjext)
CF_EXTRA	:= $(shell ./cfg.sh cflags)
MCS			:= $(shell ./cfg.sh compiler)
LIBPF		:= $(shell ./cfg.sh lib)

CC=gcc
CFLAGS=-I$(GDPATH) $(CF_EXTRA)

LD=gcc
LDFLAGS=-shared -Wl,-soname,gcd.$(SO)
LIBS= -lgd -L ../../../gd-libgd/src/ # -lc -lgd

SWIG=swig
SWIGFLAGS=-v -Wall -I$(GDPATH) -dllimport $(LIBPF)gcd.$(SO) \
	-namespace GD.Internal -noproxy

.SUFFIXES: .dll .exe

runme.exe: runme.cs $(LIBPF)gcd.$(SO)
	$(MCS) runme.cs

$(LIBPF)gcd.$(SO) : gcd.o
	$(LD) $(LDFLAGS) -o $(LIBPF)gcd.$(SO) gcd.o $(LIBS)

gcd.o : gcd.c

clean:
	-rm *.$(SO) *.o *.dll *.exe

