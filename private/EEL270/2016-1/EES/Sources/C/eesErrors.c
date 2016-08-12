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

#include "eesConst.h"
#include "eesErrors.h"
#include "eesTypes.h"
#include "eesFunctions.h"


char *eesCliErrorMessages[IDIOMS_QUANTITY][ERROR_CODE_QUANTITY]=
{
  /* English Error Messages */
  {
    "Successful operation!",
    "Invalid argument error.",
    "Invalid chosen language error.",
    "Null pointer error.",
    "Error while creating nickname.",
    "Invalid string error.",
    "Invalid content error.",
    "Permision denied.",
    "Insufficient memory error.",
    "Error while reading file.",
    "Error while creating temporary file.",
    "Error while creating file.",
    "Error while writing data to file.",
    "Generating nickname error.",
    "Username not found error."
    "Invalid error number."
  },

  /* Portuguese Error Messages */
  {
    "Operacao realizada com sucesso.",
    "Argumento invalido.",
    "Lingua escolhida eh invalida.",
    "Erro: ponteiro nulo.",
    "Erro criando nickname.",
    "Erro: string invalida.",
    "Erro: conteudo invalido.",
    "Permissao negada.",
    "Erro: memoria insuficiente.",
    "Erro lendo o arquivo.",
    "Erro criando arquivo temporario.",
    "Erro criando arquivo.",
    "Erro escrevendo os dados no arquivo.",
    "Erro na geracao do nickname.",
    "Erro: nome de usuario nao encontrado."
    "Numero de erro invalido."
  }
};

char *eesNcursesErrorMessages[IDIOMS_QUANTITY][ERROR_CODE_QUANTITY]=
{
   /* English Error Messages */
  {
    "Successful operation!",
    "Invalid argument error.",
    "Invalid chosen language error.",
    "Null pointer error.",
    "Error while creating nickname.",
    "Invalid string error.",
    "Invalid content error.",
    "Permision denied.",
    "Insufficient memory error.",
    "Error while reading file.",
    "Error while creating temporary file.",
    "Error while creating file.",
    "Error while writing data to file.",
    "Generating nickname error.",
    "Username not found error."
    "Invalid error number."
  },

  /* Portuguese Error Messages */
  {
    "Operacao realizada com sucesso.",
    "Argumento invalido.",
    "Lingua escolhida eh invalida.",
    "Erro: ponteiro nulo.",
    "Erro criando nickname.",
    "Erro: string invalida.",
    "Erro: conteudo invalido.",
    "Permissao negada.",
    "Erro: memoria insuficiente.",
    "Erro lendo o arquivo.",
    "Erro criando arquivo temporario.",
    "Erro criando arquivo.",
    "Erro escrevendo os dados no arquivo.",
    "Erro na geracao do nickname.",
    "Erro: nome de usuario nao encontrado."
    "Numero de erro invalido."
  }
};

char *eesWebErrorMessages[IDIOMS_QUANTITY][ERROR_CODE_QUANTITY]=
{
  /* English Error Messages */
  {
    "Successful operation!",
    "Invalid argument error.",
    "Invalid chosen language error.",
    "Null pointer error.",
    "Error while creating nickname.",
    "Invalid string error.",
    "Invalid content error.",
    "Permision denied.",
    "Insufficient memory error.",
    "Error while reading file.",
    "Error while creating temporary file.",
    "Error while creating file.",
    "Error while writing data to file.",
    "Generating nickname error.",
    "Username not found error."
    "Invalid error number."
  },

  /* Portuguese Error Messages */
  {
    "Operacao realizada com sucesso.",
    "Argumento invalido.",
    "Lingua escolhida eh invalida.",
    "Erro: ponteiro nulo.",
    "Erro criando nickname.",
    "Erro: string invalida.",
    "Erro: conteudo invalido.",
    "Permissao negada.",
    "Erro: memoria insuficiente.",
    "Erro lendo o arquivo.",
    "Erro criando arquivo temporario.",
    "Erro criando arquivo.",
    "Erro escrevendo os dados no arquivo.",
    "Erro na geracao do nickname.",
    "Erro: nome de usuario nao encontrado."
    "Numero de erro invalido."
  }
};

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
* char * - returns a string that contains the error message.
*
* Description:
* This function gets the error message that will be shown in CLI interface. */ 
char *
EesGetCliErrorMessage (eesErrorType errorNumber, eesLanguageType chosenLanguage)
{

  /* If the error number is greater than the total number of errors or smaller than the first error number */
  if(errorNumber > eesErrorsAmount || errorNumber < 0)
    return eesCliErrorMessages[chosenLanguage][eesErrorsAmount];

  if(chosenLanguage == eesEnglish)
    return eesCliErrorMessages[eesEnglish][errorNumber];

  return eesCliErrorMessages[eesPortuguese][errorNumber];

}

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
* char * - returns a string that contains the error message.
*
* Description:
* This function gets the error message that will be shown in Ncurses interface. */  
char *
EesGetNcursesErrorMessage (eesErrorType errorNumber, eesLanguageType chosenLanguage)
{
  /* If the error number is greater than the total number of errors or smaller than the first error number */
  if(errorNumber > eesErrorsAmount || errorNumber < 0)
    return eesNcursesErrorMessages[chosenLanguage][eesErrorsAmount];

  if(chosenLanguage == eesEnglish)
    return eesNcursesErrorMessages[eesEnglish][errorNumber];

  return eesNcursesErrorMessages[eesPortuguese][errorNumber];
}

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
* char * - returns a string that contains the error message.
*
* Description:
* This function gets the error message that will be shown in web interface. */ 
char *
EesGetWebErrorMessage (eesErrorType errorNumber, eesLanguageType chosenLanguage)
{
  /* If the error number is greater than the total number of errors or smaller than the first error number */
  if(errorNumber > eesErrorsAmount || errorNumber < 0)
    return eesWebErrorMessages[chosenLanguage][eesErrorsAmount];

  if(chosenLanguage == eesEnglish)
    return eesWebErrorMessages[eesEnglish][errorNumber];

  return eesWebErrorMessages[eesPortuguese][errorNumber];
}

/******************************************************************************************************************/

/* $RCSfile$ */
