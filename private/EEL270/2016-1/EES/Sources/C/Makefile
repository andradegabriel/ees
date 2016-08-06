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

TESTGETERRORMESSAGE = eesFunctions.o eesErrors.o mainTest.o

TESTGETUSERINTERFACEMESSAGE = eesFunctions.o eesUserInterface.o mainTest.o

TESTE_GETLANGUAGETYPE = getLanguageType
TESTE_GETERRORMESSAGE = getErrorMessages
TESTE_GETUSERINTERFACEMESSAGE = getUserInterfaceMessage

ALL = $(LIBS)\
      $(EXECS)


EXECS = $(TESTE_GETLANGUAGETYPE)\
	$(TESTE_GETERRORMESSAGE)\
	$(TESTE_GETUSERINTERFACEMESSAGE)
	

#Implicit Rule
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)


getLanguageType: $(TESTGETLANGUAGETYPE)
	$(LD) $(LFLAGS) -o $@ $?

getErrorMessages: $(TESTGETERRORMESSAGE)
	$(LD) $(LFLAGS) -o $@ $?

getUserInterfaceMessage:  $(TESTGETUSERINTERFACEMESSAGE)
	$(LD) $(LFLAGS) -o $@ $?

#iinstall:

#deinstall:

clean:
	rm -f *.o $(EXECS) $(LIBS)
