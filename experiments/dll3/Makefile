PATH		:= $(shell ./cfg.sh path)
SO			:= $(shell ./cfg.sh sharedobjext)
CF_EXTRA	:= $(shell ./cfg.sh cflags)
MCS			:= $(shell ./cfg.sh compiler)
LIBPF		:= $(shell ./cfg.sh lib)

CC=gcc
CFLAGS=-I$(GDPATH) $(CF_EXTRA)

LD=gcc
LDFLAGS=
LIBS= #-lgd -L ../../../gd-libgd/src/ # -lc -lgd

#-Wl,--out-implib,libexample_dll.a
.SUFFIXES: .dll .exe

runme.exe: runme.cs $(LIBPF)gcd.$(SO) $(LIBPF)wrap.$(SO)
	$(MCS) runme.cs

$(LIBPF)gcd.$(SO) : gcd.o
	$(LD) -shared -Wl,-soname,gcd.$(SO),--out-implib,libgcd.a -o $(LIBPF)gcd.$(SO) gcd.o $(LIBS)

$(LIBPF)wrap.$(SO) : wrap.o $(LIBPF)gcd.$(SO)
	$(LD) -shared -Wl,-soname,wrap.$(SO) -o $(LIBPF)wrap.$(SO) wrap.o -L . $(LIBS) -lgcd

gcd.o : gcd.c
wrap.o : wrap.c

clean:
	-rm *.$(SO) *.o *.dll *.exe

