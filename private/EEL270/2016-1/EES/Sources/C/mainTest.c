/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2016/1
 * 
 * $Author$
 * $Date$
 * $Log$
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "eesConst.h"
#include "eesTypes.h"
#include "eesFunctions.h"
#include "eesErrors.h"


int main (int argc, char **argv)
{
  int languageReturn;  

  languageReturn = EesGetLanguageIndex (argv[1]);

  if(languageReturn == 0)
    printf("Language not supported.\n");

  if(languageReturn == 1)
    printf("Language = English.\n");

  if(languageReturn == 2)
    printf("Language = Portuguese.\n");

  return 0;
}

/* $RCSfile$ */
