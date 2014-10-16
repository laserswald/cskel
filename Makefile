# Skeleton Medium-sized Makefile for C programs.
#
# by Ben Davenport-Ray

BINNAME=cskel
VERSION=0.0.1

LIBNAME=lib$(BINNAME)

STATLIB=$(LIBNAME).a
TESTPRG=$(BINNAME)_test
PROGRAM=$(BINNAME)
SONAME=$(LIBNAME).so.$(VERSION)
DYNLIB=$(LIBNAME).so.0

PKGNAME=$(BINNAME)-$(VERSION)

MODULES=

# Source file gathering.
SRCS:=$(wildcard ./*/*.c)
INCLUDES:=$(wildcard ./*/*.h)

OBJS=$(SRCS:.c=.o)

CFLAGS=-g -Wall -I. -fPIC -lm
LDFLAGS=
LFLAGS= -lm -Wl,-soname,$(SONAME)

TESTDIR=test
TESTSRC:=$(wildcard $(TESTDIR)/$(SOURCE))
TESTFLAGS=

CLEAN_OBJS=$(OBJS)

all: build check

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DYNLIB): $(OBJS)
	ld -shared -soname $(SONAME) -o $@ -lc $^

$(STATLIB): $(OBJS)
	ar rcs $@ $^ 	

$(TESTPRG): $(TESTSRC) $(STATLIB)
	$(CC) $(CFLAGS) $^ -o $@ 

$(PROGRAM): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ 

build: $(DYNLIB) $(TESTPRG)

rebuild: clean build

install: $(DYNLIB)
	install $(DYNLIB) /usr/lib
	mkdir /usr/include/cskel
	install $(INCLUDES) /usr/include/cskel

uninstall:


clean: 
	rm $(CLEAN_OBJS)

check: $(TESTPRG)
	exec ./$(TESTPRG)

.PHONY: all build rebuild clean dist distexec check install setup

