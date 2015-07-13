
CFLAGS= -g -I. -L. -lm

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
	ar rcs libcskel.a $^

cskel_test: libcskel.a $(tobjs)
	$(CC) $(CFLAGS) -o $@ $(tobjs) -lcskel

clean: 
	rm $(tobjs)
	rm $(pobjs)
	rm libcskel.a
	rm cskel_test

.PHONY: clean all
