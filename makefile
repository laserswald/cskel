
CFLAGS= -g -I.

# Grab all the sources.
allsrcs=$(wildcard **/*.c *.c)
objs=$(patsubst %.c,%.o, $(allsrcs))

# Find all the unit tests.
tsrcs=$(wildcard **/tests/*.c)
tobjs=$(patsubst %.c,%.o, $(tsrcs))

# Whatever is left is production.
psrcs=$(filter-out $(tsrcs),$(allsrcs))
pobjs=$(patsubst %.c,%.o, $(psrcs))

all: libcskel.a cskel_test

libcskel.a: $(pobjs)

cskel_test: libcskel.a $(tobjs)

clean: 
	rm $(objs)
	rm $(tobjs)
	rm $(pobjs)
	rm libcskel.a
	rm cskel_test

