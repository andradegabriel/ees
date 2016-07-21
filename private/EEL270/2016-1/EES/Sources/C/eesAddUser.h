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
* eesUserDataType *						     - User data
* 
* Returned Code:			
* EES_ERROR_EMPTY_POINTER					  - Function has received a null pointer
* EES_PERMISSION_DENIED					    - Permission denied		
* EES_ERROR_INSUFICIENT_MEMORY			- Could't allocate necessary memory
* EES_ERROR_READING_FILE					  - Error reading the file
* EES_ERROR_MKSTEMP						      - Error creating a temporary file	
* EES_ERROR_WRITING_FILE					  - Error creating file
* EES_ERROR_WRITING_DATA_TO_FILE		- Error writing data to the file
* EES_ERROR_GENERATE_NICKNAME				- Could't generate a nickname
* EES_OK									          - No errors
* 
* Description:
* This function adds an user to the system, it must have e-mail, group and full name fields
* filled with user information.
*/
eesErrorType eesAddUser (eesUserDataType *);   

#endif


/* $RCSfile$ */
