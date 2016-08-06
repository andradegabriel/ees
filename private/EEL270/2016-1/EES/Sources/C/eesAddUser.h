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

#ifndef 
#define  "@(#)eesAddUser.h $Revision$"


/*
* eesErrorType eesAddUser (eesUserDataType *)
* 
* Arguments: 
* eesUserDataType *						      - User data
* 
* Returned Code:			
* nullPointerError					    - Function has received a null pointer
* permissionDeniedError					- Permission denied		
* insufficientMemoryError			  - Could't allocate necessary memory
* readingFileError					    - Error reading the file
* creatingTemporaryFileError		- Error creating a temporary file	
* creatingFileError					    - Error creating file
* writingDataToFileError		    - Error writing data to the file
* generatingNicknameError				- Could't generate a nickname
* ok									          - No errors
* 
* Description:
* This function adds an user to the system, it must have e-mail, group and full name fields
* filled with user information.
*/
eesErrorType eesAddUser (eesUserDataType *);   

#endif


/* $RCSfile$ */
