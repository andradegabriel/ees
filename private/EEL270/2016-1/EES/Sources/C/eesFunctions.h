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
eesLanguageType EesGetLanguageIndex (char *);

/******************************************************************************************************************/

/*
* void
* eesGetAbsolutFileName (char *, char *);
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
void eesGetAbsolutFileName (char *, char *);

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
eesErrorType eesCheckStringField (char *, char *, unsigned, unsigned);

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
eesErrorType EesCreateNickname (char *, char *, char *);

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

#endif


/* $RCSfile$ */














