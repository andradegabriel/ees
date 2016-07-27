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

#include "eesTypes.h"
#include "eesConst.h"
#include "eesErrors.h"
#include "eesConfig.h"
#include "eesFunctions.h"
#include "eesUserInterface.h"


/*
* xyzErrorType
* XyzCreateRandomString (char *, unsigned, char *);
*
* Arguments:
* char * - set of valid characters to create the string (I)
* unsigned - string length (I)
* char * - string (O)
*
* Returned code:
* xyzOk - Function has been executed successfully.
* xyzCreateRandomStringInvalidCharacterSet . . .
  . . .
* Description:
* This function creates a random . . .*/ 

int main (int argc, char *argv[])
{
	eesErrorType errorCode;
	eesUserDataType rawData;
	eesUserIdentifier lastId, currentId;
	FILE *abeyance,*original;
	eesUserAbeyancesType data;
	eesUserAbeyancePasswordType passData;
	eesUserAbeyanceEmailType mailData;
	time_t localTime, expiration;
	int fDescriptor;
	char tempFile			[EES_TEMP_FILE_NAME_LENGHT+1]			=		EES_TEMP_FILE_NAME;
	char cookieName			[EES_COOKIE_NAME_LENGHT + 1];
	char cookiePath			[EES_MAXIMUM_COOKIE_PATH + 1];
	char cookieContent 		[EES_COOKIE_CONTENT_LENGHT + 1];
	char cookieIP			[EES_COOKIE_MAXIMUM_IP_LENGHT + 1];
	
	/*Get local time*/
	localTime = time(NULL);
	printf("Cleaning expirated data at : %s",ctime(&localTime));
	
	printf(">>>>>>>>Now cleaning users abeyance file\n");
	
	/*Creates a temporary file*/
	fDescriptor = mkstemp(tempFile);
	if (fDescriptor == -1)
	{
		printf("On user abeyance file :\n");
		eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,EES_ERROR_MKSTEMP);
		exit (EES_ERROR_MKSTEMP);
	}
	abeyance = fdopen(fDescriptor,EES_WRITE);
	if (!abeyance)
	{
		printf("On user abeyance file :\n");
		eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,EES_ERROR_WRITING_FILE);
		exit (EES_ERROR_WRITING_FILE);
	}
	
	/*Open the original file*/
	original = fopen(EES_ABEYANCES_FILE_NAME,EES_READ);
	if (!original)
	{
		printf("On user abeyance file :\n");
		eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,EES_ERROR_READING_FILE);
		fclose(abeyance);
		remove(tempFile);
		exit(EES_ERROR_READING_FILE);
	}
	
	
	while (fread(&data,1,sizeof(eesUserAbeyancesType),original) != 0)
	{
		printf("Name :%s  Expiration:%s",data.nickname,ctime(&data.expiration));
		
		if (localTime > data.expiration)
		{
			if((errorCode = eesRemoveUserData(data.nickname)) != EES_OK)
			{
				printf("On user abeyance file :\n");
				eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,errorCode);
			}	
		}
		else
			if (fwrite(&data,1,sizeof(eesUserAbeyancesType),abeyance) != sizeof(eesUserAbeyancesType))
			{
				printf("On user abeyance file :\n");
				eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,EES_ERROR_WRITING_DATA_TO_FILE);
				fclose(original);
				fclose(abeyance);
				remove(tempFile);
				exit (EES_ERROR_WRITING_DATA_TO_FILE);
			}
	}
	
	fclose(abeyance);
	fclose(original);
	
	/*Overwrite the old file*/
	remove (EES_ABEYANCES_FILE_NAME);
	rename (tempFile,EES_ABEYANCES_FILE_NAME);

	eesGenerateTextFile();
	
	/***************Cleaning password reset abeyance**************/
	
	printf(">>>>>>>>Now cleaning passwords abeyance file\n");
	
	strcpy(tempFile, EES_TEMP_FILE_NAME);
	fDescriptor = mkstemp(tempFile);
	if (fDescriptor == -1)
	{
		printf("On passwords abeyance file :\n");
		eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,EES_ERROR_MKSTEMP);
		return EES_ERROR_MKSTEMP;
	}
	
	abeyance = fdopen(fDescriptor, EES_WRITE);
	if (!abeyance)
	{
		printf("On passwords abeyance file :\n");
		eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,EES_ERROR_WRITING_FILE);
		exit (EES_ERROR_WRITING_FILE);
	}
	
	/*Open the original file*/
	original = fopen(EES_ABEYANCES_PASSWORD_FILE_NAME,EES_READ);
	if (!original)
	{
		printf("On passwords abeyance file :\n");
		eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,EES_ERROR_READING_FILE);
		fclose(abeyance);
		remove(tempFile);
		exit(EES_ERROR_READING_FILE);
	}
	
	while (fread(&passData,1,sizeof(eesUserAbeyancePasswordType),original) != 0)
	{
		printf("UID :%llu  Expiration:%s",passData.UID,ctime(&passData.expiration));
		
		if (localTime > passData.expiration)
		{
			errorCode = eesClearUserFlag(passData.UID, passwordReset); 
			if (errorCode != EES_OK)
			{
				printf("On passwords abeyance file :\n");
				eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,errorCode);				
			}
		}
		
		else
			if (fwrite(&passData,1,sizeof(eesUserAbeyancePasswordType),abeyance) != sizeof(eesUserAbeyancePasswordType))
			{
				printf("On passwords abeyance file :\n");
				eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,EES_ERROR_WRITING_DATA_TO_FILE);
				fclose(original);
				fclose(abeyance);
				remove(tempFile);
				exit (EES_ERROR_WRITING_DATA_TO_FILE);
			}
	}
	
	
	
	
	fclose(abeyance);
	fclose(original);
	
	/*Overwrite the old file*/
	remove (EES_ABEYANCES_PASSWORD_FILE_NAME);
	rename (tempFile,EES_ABEYANCES_PASSWORD_FILE_NAME);
	
	
	/***********Cleaning the e-mail abeyances file************/
	
	printf(">>>>>>>>Now cleaning e-mail abeyance file\n");
	
	strcpy(tempFile, EES_TEMP_FILE_NAME);
	fDescriptor = mkstemp(tempFile);
	if (fDescriptor == -1)
	{
		printf("On e-mail abeyance file :\n");
		eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,EES_ERROR_MKSTEMP);
		return EES_ERROR_MKSTEMP;
	}
	
	abeyance = fdopen(fDescriptor, EES_WRITE);
	if (!abeyance)
	{
		printf("On e-mail abeyance file :\n");
		eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,EES_ERROR_WRITING_FILE);
		exit (EES_ERROR_WRITING_FILE);
	}
	
	/*Open the original file*/
	original = fopen(EES_ABEYANCES_EMAIL_FILE_NAME,EES_READ);
	if (!original)
	{
		printf("On e-mail abeyance file :\n");
		eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,EES_ERROR_READING_FILE);
		fclose(abeyance);
		remove(tempFile);
		exit(EES_ERROR_READING_FILE);
	}
	
	while (fread(&mailData,1,sizeof(eesUserAbeyanceEmailType),original) != 0)
	{
		printf("UID :%llu  Expiration:%s",mailData.UID,ctime(&mailData.expiration));
		
		/*e-mail change has expirated*/
		if (localTime > mailData.expiration)
		{
			errorCode = eesClearUserFlag(mailData.UID, emailChange); 
			if (errorCode != EES_OK)
			{
				printf("On e-mail abeyance file :\n");
				eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,errorCode);				
			}
			
			errorCode = eesRemoveFromEmailAbeyanceList(mailData.UID,-1);
			if (errorCode != EES_OK)
			{
				printf("On e-mail confirmation codes file :\n");
				eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,errorCode);				
			}
		}
		
		else
			if (fwrite(&mailData,1,sizeof(eesUserAbeyanceEmailType),abeyance) != sizeof(eesUserAbeyanceEmailType))
			{
				printf("On e-mail abeyance file :\n");
				eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,EES_ERROR_WRITING_DATA_TO_FILE);
				fclose(original);
				fclose(abeyance);
				remove(tempFile);
				exit (EES_ERROR_WRITING_DATA_TO_FILE);
			}
	}
	
	
	fclose(abeyance);
	fclose(original);
	
	/*Overwrite the old file*/
	remove (EES_ABEYANCES_EMAIL_FILE_NAME);
	rename (tempFile,EES_ABEYANCES_EMAIL_FILE_NAME);
	
	/***************Cleaning expirated cookies********************/
	
	printf(">>>>>>>>Now cleaning expirated cookies\n");
	
	
	/*Get the last UID*/
	original = fopen (EES_FILE_NAME,EES_READ);
	if (!original)
	{
		printf("On cookie cleaning : \n");
		eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,errorCode);
		exit(errorCode);
	}
	
	while (fread(&rawData,1,sizeof(eesUserDataType),original) != 0);
	
	lastId = rawData.UID;
	
	/*Search for all cookies and remove old ones*/
	for (currentId = 0; currentId <= lastId; currentId++)
	{
		sprintf(cookieName,EES_COOKIE_NAME_PRINTF_FORMAT,currentId);
		strcpy(cookiePath,EES_DEFAULT_COOKIE_DIRECTORY);
		strcat(cookiePath,cookieName);
		/*Check if fille exists*/
		if (access(cookiePath,F_OK) == 0)
		{
			errorCode = eesReadCookie(cookieName,&expiration,cookieContent,cookieIP);
			if (errorCode != EES_OK)
			{
				printf("On cookie cleaning : \n");
				eesGetTextErrorMessage(EES_DEFAULT_LANGUAGE,errorCode);
				exit(errorCode);
			}
			printf("id : %llu expiration : %s",currentId,ctime(&expiration));
			
			/*cookiePath here = cookie name with full path*/
			if (localTime > expiration)	remove(cookiePath);			
		}
	}
		
	printf("Successfull removed expirated data\n");
	return EES_OK;
}   



/* $RCSfile$ */
