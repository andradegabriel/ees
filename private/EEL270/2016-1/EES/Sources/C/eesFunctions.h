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

#ifndef __EES_FUNCTIONS_H__
#define __EES_FUNCTIONS_H__	"@(#)eesFunctions.h $Revision$"

/******************************************************************************************************************/
/*
* eesLanguageType
* EesGetLanguageIndex (char *);
*
* Arguments:
* char * - string related to the language desired (I)
*
* Returned code:
* eesLanguageNotSupported - The language chosen is not supported on the system.
* eesEnglish - The language chosen is english.
* eesPortuguese - The language chosen is portuguese.
*
* Description:
* This function gets the desired language that will be used in the system. */ 
eesLanguageType
EesGetLanguageIndex (char *);

/******************************************************************************************************************/



#endif


/* $RCSfile$ */
