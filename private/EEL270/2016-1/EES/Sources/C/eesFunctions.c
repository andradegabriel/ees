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

eesLanguageType EesGetLanguageIndex (char *chosenLanguage)
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

void eesGetAbsolutFileName (char *, char *)
{
  
}
/******************************************************************************************************************/

/*
*	Checks the string field to see whether it's valid or not.
*
*	Arguments (in order of declaration):
*	char *   - field to be validated.
*	char *   - the string that contains a group of valid characters.
*	unsigned - minimum number of characters that one can have on the 
*		   field (EES_CONST_USERNAME_MINIMUM_LENGTH for username 
*		   and EES_CONST_PASSWORD_MINIMUM_LENGTH for a certain password).
*	unsigned - maximum number of characters that one can have on the field 
*		   (EES_CONST_USERNAME_MAXIMUM_LENGTH for username and 
*		   EES_CONST_PASSWORD_MAXIMUM_LENGTH for a certain password)
*
*
*	Returned Value:
*	  eesErrorOk if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType eesCheckStringField (char *, char *, unsigned, unsigned)
{
   unsigned indexField, indexCharacters, valueFound;

  if (field == NULL || validCharacters == NULL)
    return eesErrorInvalidContent;

  if (strlen(field) < minimumLength || strlen(field) > maximumLength)
    return eesErrorInvalidString;


  for (indexField = 0; indexField < strlen(field); indexField++)
  {
    for (indexCharacters = 0; indexCharacters < strlen(validCharacters); indexCharacters++)
    {
      if (field[indexField] != validCharacters[indexCharacters])
	valueFound = 0;   /* if the value was NOT found */

      if (field[indexField] == validCharacters[indexCharacters])
      {
        valueFound = 1;   /* if the value was found */
        break;
      }
    }

    if (valueFound == 0)
      return eesErrorInvalidString;
  }

  return eesErrorOk;
}

/******************************************************************************************************************/

/*
*	Checks the string field to see whether it's valid or not.
*
*	Arguments (in order of declaration):
*	char *   - field to be validated.
*	char *   - the string that contains a group of valid characters.
*	unsigned - minimum number of characters that one can have on the 
*		   field (EES_CONST_USERNAME_MINIMUM_LENGTH for username 
*		   and EES_CONST_PASSWORD_MINIMUM_LENGTH for a certain password).
*	unsigned - maximum number of characters that one can have on the field 
*		   (EES_CONST_USERNAME_MAXIMUM_LENGTH for username and 
*		   EES_CONST_PASSWORD_MAXIMUM_LENGTH for a certain password)
*
*
*	Returned Value:
*	  eesErrorOk if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesCheckNickname (char *, char *, size_t, size_t);

/******************************************************************************************************************/

/*
*	Checks the string field to see whether it's valid or not.
*
*	Arguments (in order of declaration):
*	char *   - field to be validated.
*	char *   - the string that contains a group of valid characters.
*	unsigned - minimum number of characters that one can have on the 
*		   field (EES_CONST_USERNAME_MINIMUM_LENGTH for username 
*		   and EES_CONST_PASSWORD_MINIMUM_LENGTH for a certain password).
*	unsigned - maximum number of characters that one can have on the field 
*		   (EES_CONST_USERNAME_MAXIMUM_LENGTH for username and 
*		   EES_CONST_PASSWORD_MAXIMUM_LENGTH for a certain password)
*
*
*	Returned Value:
*	  eesErrorOk if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesCheckEmail (char *, char *, size_t, size_t);

/******************************************************************************************************************/

/*
*	Creates a random string. 
*
*	Arguments (in order of declaration):	
*	char *   - string that contains a group of valid characters.
*	unsigned - size of our string that will be created 
*		   (can be any size specified in the function program).
*	char *   - the third one is our created string, that will be passed
*		   by reference to our program.
*
*
*	Returned Value:
*        essErrorOk if this function is sucessfully executed. If an error
*	  occurs, the following constant will be returned:
*	  essErrorCreatingRandomString
*/
essErrorType essCreateRandomString (char *, unsigned, char *);

/******************************************************************************************************************/

/*
*	Checks the string field to see whether it's valid or not.
*
*	Arguments (in order of declaration):
*	char *   - field to be validated.
*	char *   - the string that contains a group of valid characters.
*	unsigned - minimum number of characters that one can have on the 
*		   field (EES_CONST_USERNAME_MINIMUM_LENGTH for username 
*		   and EES_CONST_PASSWORD_MINIMUM_LENGTH for a certain password).
*	unsigned - maximum number of characters that one can have on the field 
*		   (EES_CONST_USERNAME_MAXIMUM_LENGTH for username and 
*		   EES_CONST_PASSWORD_MAXIMUM_LENGTH for a certain password)
*
*
*	Returned Value:
*	  eesErrorOk if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesCreateNickname (char *, char *)
{
  int counter=0;
	int nameCounter=0;
	char copy[EES_FULL_NAME_MAXIMUM_LENGHT];
	char singleName[EES_MAXIMUM_NAMES][EES_FULL_NAME_MAXIMUM_LENGHT+1];
	char *auxString;
	eesUserDataType data;
	int checkAvailableName;
	
	/*0 - Check pointer*/
	if (!fullName) 
		return EES_ERROR_EMPTY_POINTER;
	if (!nickname)
		return EES_ERROR_EMPTY_POINTER;
	
	
	/*1 - Copy full name to auxiliar string*/
	strcpy(copy,fullName);
	
	/*2 - Convert full name to lower case*/
	do
	{
		copy[counter] = tolower(copy[counter]);
		counter++;
	}
	while (counter < strlen(copy));
	
	/*3 - Count how many spaces on full name*/
	for (counter = 0; counter < strlen(copy); counter++)
		if (copy[counter] == ' ') nameCounter++;
	
	
	/*4 - Put the single names on the array*/
	for (counter = 0; counter < nameCounter; counter++)
	{		
		auxString = strstr(copy," ");
		memset(singleName[counter],0x00,EES_FULL_NAME_MAXIMUM_LENGHT+1);
		strncpy(singleName[counter],copy,strlen(copy)-strlen(auxString));
		auxString++;
		strcpy(copy,auxString);	
	}
	
	strcpy(singleName[nameCounter],copy);
	
	/*5 - Generate a valid nickname*/
	
	memset(nickname,0x00,MAXIMUM_USER_NICKNAME_LENGTH+1);
	strcat(nickname,singleName[0]);
	strcat(nickname,".");
	strcat(nickname,singleName[nameCounter]);
	
	do
	{	
		if (strlen(singleName[nameCounter]) > 2)
		{
			memset(nickname,0x00,MAXIMUM_USER_NICKNAME_LENGTH+1);
			strcat(nickname,singleName[0]);
			strcat(nickname,".");
			strcat(nickname,singleName[nameCounter]);
			checkAvailableName = eesSearchUser(nickname, &data);
		}
		nameCounter--;
		
		if (nameCounter == -1)
		{
			memset(nickname,0x00,MAXIMUM_USER_NICKNAME_LENGTH+1);
			strcat(nickname,singleName[0]);
		}
		
		if (nameCounter == -2)
			return EES_ERROR_CREATE_NICKNAME;

	}
	while (checkAvailableName != EES_ERROR_USERNAME_NOT_FOUND); /*This check if the name is already in use*/
	
	if (strlen(nickname) < EES_MINUMUM_NICKNAME_LENGHT)
		return EES_ERROR_CREATE_NICKNAME;
	
	return EES_OK;
}

/******************************************************************************************************************/

/*
*	Checks the string field to see whether it's valid or not.
*
*	Arguments (in order of declaration):
*	char *   - field to be validated.
*	char *   - the string that contains a group of valid characters.
*	unsigned - minimum number of characters that one can have on the 
*		   field (EES_CONST_USERNAME_MINIMUM_LENGTH for username 
*		   and EES_CONST_PASSWORD_MINIMUM_LENGTH for a certain password).
*	unsigned - maximum number of characters that one can have on the field 
*		   (EES_CONST_USERNAME_MAXIMUM_LENGTH for username and 
*		   EES_CONST_PASSWORD_MAXIMUM_LENGTH for a certain password)
*
*
*	Returned Value:
*	  eesErrorOk if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesGetCryptAlgorithm (char *, eesCryptAlgorithms *);

/******************************************************************************************************************/

/*
*	Checks the string field to see whether it's valid or not.
*
*	Arguments (in order of declaration):
*	char *   - field to be validated.
*	char *   - the string that contains a group of valid characters.
*	unsigned - minimum number of characters that one can have on the 
*		   field (EES_CONST_USERNAME_MINIMUM_LENGTH for username 
*		   and EES_CONST_PASSWORD_MINIMUM_LENGTH for a certain password).
*	unsigned - maximum number of characters that one can have on the field 
*		   (EES_CONST_USERNAME_MAXIMUM_LENGTH for username and 
*		   EES_CONST_PASSWORD_MAXIMUM_LENGTH for a certain password)
*
*
*	Returned Value:
*	  eesErrorOk if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesEncodePasswordWithSpecificAlgorithm (char *, eesCryptAlgorithms, char *);

/******************************************************************************************************************/

/*
*	Checks the string field to see whether it's valid or not.
*
*	Arguments (in order of declaration):
*	char *   - field to be validated.
*	char *   - the string that contains a group of valid characters.
*	unsigned - minimum number of characters that one can have on the 
*		   field (EES_CONST_USERNAME_MINIMUM_LENGTH for username 
*		   and EES_CONST_PASSWORD_MINIMUM_LENGTH for a certain password).
*	unsigned - maximum number of characters that one can have on the field 
*		   (EES_CONST_USERNAME_MAXIMUM_LENGTH for username and 
*		   EES_CONST_PASSWORD_MAXIMUM_LENGTH for a certain password)
*
*
*	Returned Value:
*	  eesErrorOk if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesEncodePasswordWithSpecificSalt (char *, char *, char *);

/******************************************************************************************************************/

/*
*	Checks the string field to see whether it's valid or not.
*
*	Arguments (in order of declaration):
*	char *   - field to be validated.
*	char *   - the string that contains a group of valid characters.
*	unsigned - minimum number of characters that one can have on the 
*		   field (EES_CONST_USERNAME_MINIMUM_LENGTH for username 
*		   and EES_CONST_PASSWORD_MINIMUM_LENGTH for a certain password).
*	unsigned - maximum number of characters that one can have on the field 
*		   (EES_CONST_USERNAME_MAXIMUM_LENGTH for username and 
*		   EES_CONST_PASSWORD_MAXIMUM_LENGTH for a certain password)
*
*
*	Returned Value:
*	  eesErrorOk if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesCheckPassword (char *, char *);

/******************************************************************************************************************/

/*
*	Checks the string field to see whether it's valid or not.
*
*	Arguments (in order of declaration):
*	char *   - field to be validated.
*	char *   - the string that contains a group of valid characters.
*	unsigned - minimum number of characters that one can have on the 
*		   field (EES_CONST_USERNAME_MINIMUM_LENGTH for username 
*		   and EES_CONST_PASSWORD_MINIMUM_LENGTH for a certain password).
*	unsigned - maximum number of characters that one can have on the field 
*		   (EES_CONST_USERNAME_MAXIMUM_LENGTH for username and 
*		   EES_CONST_PASSWORD_MAXIMUM_LENGTH for a certain password)
*
*
*	Returned Value:
*	  eesErrorOk if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesAuthenticateUser (eesUserDataType *);

/******************************************************************************************************************/






/* $RCSfile$ */



















