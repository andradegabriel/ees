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

#include <string.h>
#include <stdlib.h>

#include "eesTypes.h"
#include "eesFunctions.h"
#include "eesErrors.h"

/******************************************************************************************************************/
/*
* eesLanguageType
* EesGetLanguageIndex (char *);
*
* Arguments:
* char * - string related to the language desired (I)
*
* Returned code:
* eesEnglish - If the language chosen is not supported on the system, english will be the default language.
* eesEnglish - The language chosen is english.
* eesPortuguese - The language chosen is portuguese.
*
* Description:
* This function gets the desired language that will be used in the system. */ 

eesLanguageType
EesGetLanguageIndex (char *chosenLanguage)
{
  if(chosenLanguage == NULL)
    return eesEnglish;

  /* If a language is not define, the default language will be English */
  if((strcmp(chosenLanguage, "eesEnglish") != 0) && (strcmp(chosenLanguage, "eesPortuguese") != 0))
    return eesEnglish;

  /* Case in which the chosenLanguage is EQUAL to eesEnglish */
  if(strcmp(chosenLanguage, "eesEnglish") == 0)
    return eesEnglish;  

  /* Case in which the chosenLanguage is EQUAL to eesPortuguese */
  return eesPortuguese;
}

/******************************************************************************************************************/


/* $RCSfile$ */
