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
#include <stdio.h>
#include <ctype.h>

#include "eesConfig.h"
#include "eesConst.h"
#include "eesTypes.h"
#include "eesFunctions.h"
#include "eesErrors.h"

/*================================================================================================================*/
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

/*================================================================================================================*/

/*
* char *
* EesGetAbsolutFileName (char *, char *);
*
* Arguments:
* char * - fisrt string to be concatenated (I)
* char * - second string to be concatenated (I)
*
* Returned code:
* char * - The concatenation of both strings.
*
* Description:
* This function concatenates both string and return the result of the concatenation. */ 

char * EesGetAbsolutFileName (char * firstString, char * secondString)
{
  char *resultString;
  
  if((firstString == NULL) || (secondString == NULL))
    return NULL;
  
  resultString = malloc(MAXIMUM_STRING_CONCATENATED_LENGTH);
  
  memset(resultString, 0x00, MAXIMUM_STRING_CONCATENATED_LENGTH);
  
  snprintf(resultString, MAXIMUM_STRING_CONCATENATED_LENGTH, "%s%s", firstString, secondString);
  
  free(resultString);
  
  return resultString;
}
/*================================================================================================================*/

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
*	  ok if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesCheckStringField (char * field, char * validCharacters, unsigned minimumLength, unsigned maximumLength)
{
  unsigned indexField, indexCharacters, valueFound;

  if (field == NULL || validCharacters == NULL)
    return invalidContentError;

  if (strlen(field) < minimumLength || strlen(field) > maximumLength)
    return invalidStringError;


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
      return invalidStringError;
  }

  return ok;
}

/*================================================================================================================*/

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
*	  ok if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesCheckNickname (char *, char *, size_t, size_t);

/*================================================================================================================*/

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
*	  ok if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesCheckEmail (char *, char *, size_t, size_t);

/*================================================================================================================*/

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
eesErrorType EesCreateRandomString (char *, unsigned, char *);

/*================================================================================================================*/

/*
* eesErrorType 
* EesSearchUser (char *nickname, eesUserDataType *data);
* 
* Arguments: 
* char *nickname					  - user nickname
* eesUserDataType *data			- struct with all user data
* 
* Returned Code:
* readingFileError			  - Error reading the file
* usernameNotFoundError		- Nickname not found on the file
* ok							        - User found without errors
* 
* Description:
* This functions takes a nickname and search for it on the file EES_FILE_NAME and saves user information
* on *data if found.
*/
eesErrorType EesSearchUser (char *nickname, eesUserDataType *data)
{
	FILE *read;
	boolean found = false;
	
	read = fopen(EES_FILE_NAME, "r");
	if (!read) 
    return readingFileError;

	while ((found == false) && (fread(data, sizeof(eesUserDataType), 1, read) != 0))
		if (strcmp(data->eesNickname, nickname) == 0) found = true; 

	fclose(read);
	
	if (found == false)
		return usernameNotFoundError;
			
	return ok;
}

/*================================================================================================================*/

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
*	  ok if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesCreateNickname (char * fullName, char * nicknameLastName, char * nicknamePenultimateName)
{
  int counter = 0;
	int nameCounter = 0;
	char copy[MAXIMUM_USER_FULL_NAME_LENGTH];
	char singleName[EES_MAXIMUM_NAME_QUANTITY][MAXIMUM_USER_FULL_NAME_LENGTH + 1];
	char *auxString;
	eesUserDataType data;
	int checkAvailableName;
	
	/*0 - Check pointer*/
	if (!fullName || !nicknameLastName) 
		return nullPointerError;
  
	/* 1 - Copy full name to auxiliar string */
	strcpy(copy,fullName);
	
	/* 2 - Convert full name to lower case */
	do
	{
		copy[counter] = tolower(copy[counter]);
		counter++;
	}
	while (counter < strlen(copy));
	
	/* 3 - Count how many spaces on full name */
	for (counter = 0; counter < strlen(copy); counter++)
		if (copy[counter] == ' ') nameCounter++;
	
	
	/* 4 - Put the single names on the array */
	for (counter = 0; counter < nameCounter; counter++)
	{		
		auxString = strstr(copy," ");
		memset(singleName[counter], 0x00, MAXIMUM_USER_FULL_NAME_LENGTH + 1);
		strncpy(singleName[counter],copy,strlen(copy)-strlen(auxString));
		auxString++;
		strcpy(copy,auxString);	
	}
	
	strcpy(singleName[nameCounter],copy);
	
	/* 5 - Generate a valid nicknameLastName */
	
	memset(nicknameLastName, 0x00, MAXIMUM_USER_NICKNAME_LENGTH + 1);
	strcat(nicknameLastName,singleName[0]);
	strcat(nicknameLastName,".");
	strcat(nicknameLastName,singleName[nameCounter]);
	
	do
	{	
		if (strlen(singleName[nameCounter]) > 2)
		{
			memset(nicknameLastName,0x00,MAXIMUM_USER_NICKNAME_LENGTH+1);
			strcat(nicknameLastName,singleName[0]);
			strcat(nicknameLastName,".");
			strcat(nicknameLastName,singleName[nameCounter]);
			checkAvailableName = EesSearchUser(nicknameLastName, &data);
		}
		nameCounter--;
		
		if (nameCounter == -1)
		{
			memset(nicknameLastName, 0x00, MAXIMUM_USER_NICKNAME_LENGTH + 1);
			strcat(nicknameLastName,singleName[0]);
		}
		
		if (nameCounter == -2)
			return creatingNicknameError;

	}
	while (checkAvailableName != usernameNotFoundError); /*This check if the name is already in use*/
	
	if (strlen(nicknameLastName) < MINIMUM_USER_NICKNAME_LENGTH)
		return creatingNicknameError;
	
	return ok;
}

/*================================================================================================================*/

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
*	  ok if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesGetCryptAlgorithm (char *, eesCryptAlgorithms *);

/*================================================================================================================*/

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
*	  ok if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesEncodePasswordWithSpecificAlgorithm (char *, eesCryptAlgorithms, char *);

/*================================================================================================================*/

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
*	  ok if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesEncodePasswordWithSpecificSalt (char *, char *, char *);

/*================================================================================================================*/

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
*	  ok if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesCheckPassword (char *, char *);
/*================================================================================================================*/

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
*	  ok if this function is sucessfully executed. If an error
*	  occurs, one of these constants may be returned:
*	  eesErrorInvalidField
*/
eesErrorType EesAuthenticateUser (eesUserDataType *);
/*================================================================================================================*/






/* $RCSfile$ */



















