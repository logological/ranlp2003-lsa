# $Id: Makefile,v 0.0 2002-08-31 16:43:35 psy Exp $
# ------------------------------------------------------------------------------

CC = gcc
CFLAGS = -Wall -ansi -pedantic -O3
STRIP = strip
RM = rm -rf

all:	getrand

getrand:	getrand.c
	$(CC) $(CFLAGS) -ogetrand getrand.c
	$(STRIP) getrand

clean:
	$(RM) getrand
