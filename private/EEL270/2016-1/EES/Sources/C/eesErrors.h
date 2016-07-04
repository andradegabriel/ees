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

#ifndef __EES_ERRORS_H__
#define __EES_ERRORS_H__	"@(#)eesErrors.h $Revision$"

typedef enum _eesErrorType 
{
  ok,
  invalidArgument
} eesErrorType;


/******************************************************************************************************************/


/*
* char *
* EesGetCliErrorMessage (eesErrorType, eesLanguageType)
*
* Arguments:
* eesErrorType - number of the error type (I)
* eesLanguageType - language type of the message (I)
*
* Returned code:
*  TODO
* xyzOk - Function has been executed successfully.
*
* Description:
* This function gets the error message that will be shown in CLI interface. */ 
char *
EesGetCliErrorMessage (eesErrorType, eesLanguageType);


/******************************************************************************************************************/

/*
* char *
* EesGetNcursesErrorMessage (eesErrorType, eesLanguageType)
*
* Arguments:
* eesErrorType - number of the error type (I)
* eesLanguageType - language type of the message (I)
*
* Returned code:
*  TODO
* xyzOk - Function has been executed successfully.
*
* Description:
* This function gets the error message that will be shown in Ncurses interface. */  
char *
EesGetNcursesErrorMessage (eesErrorType, eesLanguageType);


/******************************************************************************************************************/

/*
* char *
* EesGetWebErrorMessage (eesErrorType, eesLanguageType)
*
* Arguments:
* eesErrorType - number of the error type (I)
* eesLanguageType - language type of the message (I)
*
* Returned code:
*  TODO
* xyzOk - Function has been executed successfully.
*
* Description:
* This function gets the error message that will be shown in web interface. */ 
char *
EesGetWebErrorMessage (eesErrorType, eesLanguageType);

/******************************************************************************************************************/


#endif


/* $RCSfile$ */
