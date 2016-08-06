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


# Default Directories ##########################################################
DEFAULT_CGI_DIRECTORY = /users/gabriel.souza/public/EEL270/2016-1/EES/CGIs/
DEFAULT_BINARIES_DIRECTORY = /users/gabriel.souza/private/EEL270/2016-1/EES/Binaries/


# Linking Tests Files ##########################################################
TEST_GETLANGUAGETYPE = eesFunctions.o mainTest.o
TEST_GETERRORMESSAGE = eesFunctions.o eesErrors.o mainTest.o
TEST_GETUSERINTERFACEMESSAGE = eesFunctions.o eesUserInterface.o mainTest.o
TEST_GETABSOLUTFILENAME = eesFunctions.o mainTest.o


# Linking System Files #########################################################
# TODO


# Test Binaries (in order) #####################################################
TEST_GET_LANGUAGE_TYPE = getLanguageType
TEST_GET_ERROR_MESSAGE = getErrorMessages
TEST_GET_USER_INTERFACE_MESSAGE = getUserInterfaceMessage
TEST_GET_ABSOLUT_FILE_NAME = getAbsolutFileName

# System Binaries (in order) ###################################################
# TODO


ALL = $(LIBS)\
      $(EXECS)


EXECS = $(TEST_GET_LANGUAGE_TYPE)\
	$(TEST_GET_ERROR_MESSAGE)\
	$(TEST_GET_USER_INTERFACE_MESSAGE)\
	$(TEST_GETABSOLUTFILENAME)
	

# Compilation Rule #############################################################
.c.o:
	$(CC) $(CFLAGS) -c $<


# Rotules ######################################################################
all: $(ALL)


# Tests Linking Rules ##########################################################
getLanguageType: $(TEST_GETLANGUAGETYPE)
	$(LD) $(LFLAGS) -o $@ $?

getErrorMessages: $(TEST_GETERRORMESSAGE)
	$(LD) $(LFLAGS) -o $@ $?

getUserInterfaceMessage:  $(TEST_GETUSERINTERFACEMESSAGE)
	$(LD) $(LFLAGS) -o $@ $?

getAbsolutFileName: $(TEST_GETABSOLUTFILENAME)
	$(LD) $(LFLAGS) -o $@ $?


# System Installation Rules ####################################################

install:

#deinstall:

clean:
	rm -f *.o $(EXECS) $(LIBS)
