PATH		:= $(shell ./cfg.sh path)
SO			:= $(shell ./cfg.sh sharedobjext)
CF_EXTRA	:= $(shell ./cfg.sh cflags)
MCS			:= $(shell ./cfg.sh compiler)
LIBPF		:= $(shell ./cfg.sh lib)
GDPATH		:= $(shell ./cfg.sh gdpath)

CC=gcc
CFLAGS=-I$(GDPATH)/src/ $(CF_EXTRA)

LD=gcc
LDFLAGS=-shared -Wl,-soname,wrap.$(SO)
LIBS= -lgd -L .

SWIG=swig
SWIGFLAGS=-v -Wall -I$(GDPATH) -dllimport $(LIBPF)wrap.$(SO) \
	-namespace GD.Internal -noproxy

.SUFFIXES: .dll .exe

runme.exe: runme.cs $(LIBPF)wrap.$(SO)
	$(MCS) runme.cs

$(LIBPF)wrap.$(SO) : wrap.o
	$(LD) $(LDFLAGS) -o $(LIBPF)wrap.$(SO) wrap.o #$(LIBS)

wrap.o : wrap.c

clean:
	-rm *.o wrap.dll *.exe

