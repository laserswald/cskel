
# Skeleton Medium-sized Makefile for C programs.
#
# by Ben Davenport-Ray

BINNAME=cskel
VERSION=0.0.1

BINDIR=bin
LIBNAME=lib$(BINNAME)

DYNLIB=$(BINNAME).dll
STATLIB=$(LIBNAME).a
TESTPRG=$(BINNAME)_test
EXECUTABLE=$(BINNAME)
SONAME=$(LIBNAME).so.$(VERSION)

PKGNAME=$(BINNAME)-$(VERSION)

MODULES=

# Source file gathering.
SOURCE=*.c
SRCDIR=src
SRCS:=$(wildcard $(SRCDIR)/$(SOURCE))

INCLUDE=include

OBJECT=$(SRCS:.c=.o)
OBJDIR=obj
OBJS:=$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(OBJECT))

CFLAGS=-g -Wall -I$(INCLUDE) -L. 
LDFLAGS=
LFLAGS= -shared -fPIC -Wl,-soname,$(SONAME)

TESTDIR=test
TESTSRC:=$(wildcard $(TESTDIR)/$(SOURCE))
TESTFLAGS=

all: build check

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DYNLIB): $(OBJS)
	$(CC) $(LFLAGS) $^ -o $(DYNLIB) 

$(STATLIB): $(OBJS)
	ar rcs $@ $^ 	

$(TESTPRG): $(TESTSRC) $(STATLIB)
	$(CC) $(CFLAGS) $^ -o $@ 

build: setup $(PROGRAM) $(TESTPRG)

rebuild: clean build

clean: 
	rm -r $(OBJDIR)

dist:
	tar -zxvf $(PKGNAME)

distexec:
	$(ZIP) $(PKGNAME)-win32.zip README.md $(EXECUTABLE)

check: $(TESTPRG)
	exec ./$(TESTPRG)

setup:
	mkdir -p $(BINDIR)
	mkdir -p $(OBJDIR)

.PHONY: all build rebuild clean dist distexec check install setup

