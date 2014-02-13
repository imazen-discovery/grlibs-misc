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

runme.exe: runme.cs $(LIBPF)mygd.$(SO) $(LIBPF)wrap.$(SO)
	$(MCS) runme.cs

$(LIBPF)mygd.$(SO) : mygd.o
	$(LD) -shared -Wl,-soname,mygd.$(SO),--out-implib,libmygd.a -o $(LIBPF)mygd.$(SO) mygd.o $(LIBS)

$(LIBPF)wrap.$(SO) : wrap.o $(LIBPF)mygd.$(SO)
	$(LD) -shared -Wl,-soname,wrap.$(SO) -o $(LIBPF)wrap.$(SO) wrap.o -L . $(LIBS) -lmygd

mygd.o : mygd.c
wrap.o : wrap.c

clean:
	-rm *.o *.$(SO) *.exe *.a

