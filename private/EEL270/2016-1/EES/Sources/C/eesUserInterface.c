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

#include "eesConst.h"
#include "eesTypes.h"
#include "eesErrors.h"
#include "eesUserInterface.h"
#include "eesFunctions.h"

/* TODO - Make sure that is it */
char *eesCliUserInterfaceMessages[IDIOMS_QUANTITY][USER_INTERFACE_MESSAGE_NUMBER]=
{
  /* English user interface messages */
  {
    "Create account.",
    "Delete user.",
    "Login account.",
    "No user interface info."
  },

  /* Portuguese user interface messages */
  {
    "Criar conta.",
    "Deletar usuario.",
    "Realizar o login.",
    "Nenhuma mensagem para o usuario."
  }
};

char *eesNcursesUserInterfaceMessages[IDIOMS_QUANTITY][USER_INTERFACE_MESSAGE_NUMBER]=
{
  /* English user interface messages */
  {
    "Create account.",
    "Delete user.",
    "Login account.",
    "No user interface info."
  },

  /* Portuguese user interface messages */
  {
    "Criar conta.",
    "Deletar usuario.",
    "Realizar o login.",
    "Nenhuma mensagem para o usuario."
  }
};

char *eesWebUserInterfaceMessages[IDIOMS_QUANTITY][USER_INTERFACE_MESSAGE_NUMBER]=
{
  /* English user interface messages */
  {
    "Create account.",
    "Delete user.",
    "Login account.",
    "No user interface info."
  },

  /* Portuguese user interface messages */
  {
    "Criar conta.",
    "Deletar usuario.",
    "Realizar o login.",
    "Nenhuma mensagem para o usuario."
  }
};

/******************************************************************************************************************/


/*
* char *
* EesGetCliUserInterfaceMessage (eesUserInterfaceMessageNumberType, eesLanguageType)
*
* Arguments:
* eesUserInterfaceMessageNumberType - number of the user interface message type (I)
* eesLanguageType - language type of the message (I)
*
* Returned code:
* char * - returns a string that contains an user interface message.
*
* Description:
* This function gets the user interface message that will be shown in CLI interface. */ 
char *
EesGetCliUserInterfaceMessage (eesUserInterfaceMessageNumberType messageNumber, eesLanguageType chosenLanguage)
{

   /* If the error number is greater than the total number of errors or smaller than the first error number */
  if(messageNumber > eesUserInterfaceMessageAmount || messageNumber < 0)
    return eesCliUserInterfaceMessages[chosenLanguage][eesUserInterfaceMessageAmount];

  if(chosenLanguage == eesEnglish)
    return eesCliUserInterfaceMessages[eesEnglish][messageNumber];

  return eesCliUserInterfaceMessages[eesPortuguese][messageNumber];

}

/******************************************************************************************************************/


/*
* char *
* EesGetNcursesUserInterfaceMessage (eesUserInterfaceMessageNumberType, eesLanguageType)
*
* Arguments:
* eesUserInterfaceMessageNumberType - number of the user interface message type (I)
* eesLanguageType - language type of the message (I)
*
* Returned code:
* char * - returns a string that contains an user interface message.
*
* Description:
* This function gets the user interface message that will be shown in Ncurses interface. */  
char *
EesGetNcursesUserInterfaceMessage (eesUserInterfaceMessageNumberType messageNumber, eesLanguageType chosenLanguage)
{

  /* If the error number is greater than the total number of errors or smaller than the first error number */
  if(messageNumber > eesUserInterfaceMessageAmount || messageNumber < 0)
    return eesNcursesUserInterfaceMessages[chosenLanguage][eesUserInterfaceMessageAmount];

  if(chosenLanguage == eesEnglish)
    return eesNcursesUserInterfaceMessages[eesEnglish][messageNumber];

  return eesNcursesUserInterfaceMessages[eesPortuguese][messageNumber];
}

/******************************************************************************************************************/


/*
* char *
* EesGetWebUserInterfaceMessage (eesUserInterfaceMessageNumberType, eesLanguageType)
*
* Arguments:
* eesUserInterfaceMessageNumberType - number of the user interface message type (I)
* eesLanguageType - language type of the message (I)
*
* Returned code:
* char * - returns a string that contains an user interface message.
*
* Description:
* This function gets the user interface message that will be shown in web interface. */ 
char *
EesGetWebUserInterfaceMessage (eesUserInterfaceMessageNumberType messageNumber, eesLanguageType chosenLanguage)
{
  
  /* If the error number is greater than the total number of errors or smaller than the first error number */
  if(messageNumber > eesUserInterfaceMessageAmount || messageNumber < 0)
    return eesWebUserInterfaceMessages[chosenLanguage][eesUserInterfaceMessageAmount];

  if(chosenLanguage == eesEnglish)
    return eesWebUserInterfaceMessages[eesEnglish][messageNumber];

  return eesWebUserInterfaceMessages[eesPortuguese][messageNumber];

}

/******************************************************************************************************************/

/* $RCSfile$ */


