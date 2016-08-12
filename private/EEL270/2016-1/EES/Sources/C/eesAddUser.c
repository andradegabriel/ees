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


/*
* eesErrorType eesAddUser (eesUserDataType *)
* 
* Arguments: 
* eesUserDataType *						     - User data
* 
* Returned Code:			
* nullPointerError					       - Function has received a null pointer
* permissionDeniedError					   - Permission denied		
* insufficientMemoryError			     - Could't allocate necessary memory
* readingFileError					       - Error reading the file
* creatingTemporaryFileError			 - Error creating a temporary file	
* creatingFileError					       - Error creating file
* writingDataToFileError		       - Error writing data to the file
* generatingNicknameError				   - Could't generate a nickname
* ok									             - No errors
* 
* Description:
* This function adds an user to the system, it must have e-mail, group and full name fields
* filled with user information.
*/
            
eesErrorType eesAddUser (eesUserDataType *data)    
{
	eesErrorType errorCode;
	eesUserAbeyancesType abeyances;
	char *password;
	char *passwordConfirm;
	char encryptedPassword [EES_ENCRYPTED_PASSWORD_LENGHT+1];
	char nickname[EES_NICKNAME_MAXIMUM_LENGHT+1];	
	eesUserIdentifier UID;
	char tempPassword[EES_TEMP_PASSWORD_LENGHT+1];
	
	if(!data) 
    return nullPointerError;

	
	if (strcmp(data->nickname, EES_ROOT_NAME) == 0)
	{
		if (getuid() == EES_ADMINISTRATOR_USER_IDENTIFIER)
		{
			
			password = malloc(EES_PASSWORD_MAXIMUM_LENGHT+1);
			do
			{
				passwordConfirm = getpass("Enter a password : ");
				strcpy(password,passwordConfirm);
				passwordConfirm = getpass("Confirm your password : ");
				if (strcmp(passwordConfirm,password) != 0) printf("Passwords didn't match, try again \n");
			} while (strcmp(passwordConfirm,password) != 0);
			
			
			errorCode = eesEncryptPassword(password,encryptedPassword);
			strcpy(data->codedPassword,encryptedPassword);
			/*Erase plain password from memory*/
			free(password);
			memset(passwordConfirm,0x00,strlen(passwordConfirm));				
			
			/*Set UID = 0 on root user*/
			data->UID = 0;


			if ((errorCode = eesWriteFile(data)) != ok)
				return errorCode;
			
			return (eesGenerateTextFile());
						
		}
		else
			return permissionDeniedError;
	}
	/*if nickname = root*/
	
	/*Add nickname field*/
	if ((errorCode = eesGenerateNickname(data->fullName,nickname)) != ok)
		return errorCode;
		
	strcpy(data->nickname,nickname);
	data->flag = abeyance;
	
	/*Add uid field*/
	if ((errorCode = eesGetValidUid(&UID)) != ok)
		return errorCode;
	data->UID = UID;
	
	/*Creates a temporary password*/
	memset(data->codedPassword,0x00,EES_ENCRYPTED_PASSWORD_LENGHT+1);
	memset(tempPassword,0x00,EES_TEMP_PASSWORD_LENGHT+1);
	eesGenerateTemporaryPassword(tempPassword);
	
	/*Save to struct*/
	eesEncryptPassword(tempPassword,encryptedPassword);
	strcpy(data->codedPassword,encryptedPassword);
	
	
	/*Writing data to new file*/
	if ((errorCode = eesWriteFile(data)) != ok)
		return errorCode;
	
	/*Adding users to abeyances file*/
	memset(&abeyances,0x00,sizeof(eesUserAbeyancesType));
	abeyances.expiration = time(NULL) + EES_ABEYANCES_EXPIRATION;
	strcpy(abeyances.nickname,data->nickname);
	eesAddAbeyanceUser(abeyances,EES_ABEYANCES_FILE_NAME);
	
	
	/*Sends back plain password for confirmation process*/
	memset(data->codedPassword,0x00,EES_ENCRYPTED_PASSWORD_LENGHT+1);
	strncpy(data->codedPassword,tempPassword,EES_TEMP_PASSWORD_LENGHT+1);


	return ok;

}


/* $RCSfile$ */
