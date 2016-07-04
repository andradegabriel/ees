# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# EEL270 - Computacao II - Turma 2016/1
# Prof. Marcelo Luiz Drumond Lanza
#
# $Author$
# $Date$
# $Log$
#

CC = gcc
LD = gcc

CFLAGS = -Wall -ansi
LFLAGS = -Wall -ansi

TESTGETLANGUAGETYPE = eesFunctions.o mainTest.o

LIBMATEMATICAOBJS = aula0301a.o

LIBS = libmatematica.a

TESTE_GETLANGUAGETYPE = getLanguageType


ALL = $(LIBS)\
      $(EXECS)


EXECS = $(TESTE_GETLANGUAGETYPE)

#Implicit Rulei
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

aula03: $(AULA03)

getLanguageType: $(TESTGETLANGUAGETYPE)
	$(LD) $(LFLAGS) -o $@ $?

aula0304d: $(AULA0304DOBJS)
	$(LD) $(LFLAGS) -o $@ $? -L. -lmatematica

aula0304e: $(AULA0304EOBJS)
	$(LD) $(LFLAGS) -o $@ $? -lm

libmatematica.a: $(LIBMATEMATICAOBJS)
	ar -r $(LIBS) $(LIBMATEMATICAOBJS)

#iinstall:

#deinstall:

clean:
	rm -f *.o $(EXECS) $(LIBS)
