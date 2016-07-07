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

#ifndef __EES_USER_INTERFACE_H__
#define __EES_USER_INTERFACE_H__ 	"@(#)eesUserInterface.h $Revision$"

typedef enum _eesUserInterfaceMessageNumberType
{
  createAccount,
  deleteUser,
  login,
  eesUserInterfaceMessageAmount
} eesUserInterfaceMessageNumberType;




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
EesGetCliUserInterfaceMessage (eesUserInterfaceMessageNumberType, eesLanguageType);


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
EesGetNcursesUserInterfaceMessage (eesUserInterfaceMessageNumberType, eesLanguageType);


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
EesGetWebUserInterfaceMessage (eesUserInterfaceMessageNumberType, eesLanguageType);

/******************************************************************************************************************/

#endif


/* $RCSfile$ */
