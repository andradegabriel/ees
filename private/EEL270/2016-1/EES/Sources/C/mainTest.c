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
#include "eesUserInterface.h"

int main (int argc, char **argv)
{

/**********************************************************************************************************/
/* EesGetCliUserInterfaceMessage, EesGetNcursesUserInterfaceMessage, EesGetWebUserInterfaceMessage Test   */	
/**********************************************************************************************************/

/*

  int userInterfaceMessageNumber;
  eesLanguageType languageReturn;

  languageReturn = EesGetLanguageIndex (argv[2]);

  userInterfaceMessageNumber = atoi(argv[1]);

  printf("error number: %s\n", argv[1]);
  printf("languageReturn: %u\n", languageReturn);

  printf("%s\n", EesGetCliUserInterfaceMessage(userInterfaceMessageNumber, languageReturn));
  printf("%s\n", EesGetNcursesUserInterfaceMessage(userInterfaceMessageNumber, languageReturn));
  printf("%s\n", EesGetWebUserInterfaceMessage(userInterfaceMessageNumber, languageReturn));
*/

/****************************************************************************************************/




/****************************************************************************************************/
/* EesGetCliErrorMessage, EesGetNcursesErrorMessage, EesGetWebErrorMessage Test			    */	
/****************************************************************************************************/

/*

  int errorNumber;
  eesLanguageType languageReturn;

  languageReturn = EesGetLanguageIndex (argv[2]);

  errorNumber = atoi(argv[1]);

  printf("error number: %s\n", argv[1]);
  printf("languageReturn: %u\n", languageReturn);

  printf("%s\n", EesGetCliErrorMessage(errorNumber, languageReturn));
  printf("%s\n", EesGetNcursesErrorMessage(errorNumber, languageReturn));
  printf("%s\n", EesGetWebErrorMessage(errorNumber, languageReturn));
*/

/****************************************************************************************************/


/****************************************************************************************************/
/* EesGetLanguageIndex Test									    */	
/****************************************************************************************************/

/*
  eesLanguageType languageReturn;

  languageReturn = EesGetLanguageIndex (argv[1]);

  printf("argv: %s\n", argv[1]);
  printf("languageReturn: %u\n", languageReturn);

  if(languageReturn == 0)
    printf("Language = English.\n");

  if(languageReturn == 1)
    printf("Language = Portuguese.\n");
*/

/****************************************************************************************************/

  return 0;
}

/* $RCSfile$ */


