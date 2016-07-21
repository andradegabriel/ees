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


/*Global Arrays*/
char *groupsArray[7][2]=
{
	{"Administrator","Aministrador"},
	{"Owner","Proprietario"},
	{"Administrator & Owner","Administrador & Proprietario"},
	{"User","Usuario"},
	{"Administrator & User ","Administrador & Usuario"},
	{"User & Owner","Usuario & Proprietario"},
	{"ROOT","ROOT"}
};


static struct option longOptions []=
{
	{"add",			0,	NULL	, 'a'},
  {"invite",		0,	NULL	, 'i'},
  {"accept",		0,	NULL	, 't'},
  {"reject",		0,	NULL	, 'j'},
  {"new",		0,	NULL	, 'n'},
  {"request",		0,	NULL	, 'q'},
  {"approve",		0,	NULL	, 'v'},
  {"disapprove",		0,	NULL	, 'd'},
  {"Unlocking",		0,	NULL	, 'U'},
  {"lock",		0,	NULL	, 'l'},
  {"unlock",		0,	NULL	, 'u'},
  {"password",	0,	NULL	, 'p'},
  {"reset",	0,	NULL	, 'r'},
  {"modify",	0,	NULL	, 'm'},
  {"edit",	0,	NULL	, 'e'},
  {"confirm",	0,	NULL	, 'c'},
  {"group", 		0,	NULL	, 'g'},
  {"show", 		0,	NULL	, 's'},
  {"Search", 		0,	NULL	, 'S'},
	{NULL, 			0, 	NULL	,  0 }
};

char *tokens [] =
{
	"user",
	"nickname",
	"email",
	"confirmation",
	"group",
	"username",
	"language",
	NULL
};
		
enum
{
	USER,
	NICKNAME,
	EMAIL,
	CONFIRMATION,
	GROUP,
	USERNAME,
	LANGUAGE,	
};


int main(int argc, char **argv)
{ 
	int option,argumentIndex,index;
	unsigned passwordErrorCounter = EES_PASSWORD_ATTEMPTS;	
	char *stringShortOptions = "AaCcEeGgHhIiNnPpRrZz";
	char *value;
	char systemUser [MAXIMUM_USER_NICKNAME_LENGTH + 1];
	char nickname   [MAXIMUM_USER_NICKNAME_LENGTH + 1];
	char username   [MAXIMUM_USER_NICKNAME_LENGTH + 1];
	char email      [MAXIMUM_EMAIL_LENGTH + 1];
	char confEmail  [MAXIMUM_EMAIL_LENGTH + 1];
	char *password;
	char passwordConfirm [EES_PASSWORD_MAXIMUM_LENGHT+1];
	char confirm;
	eesLanguageType language = english;
	eesUserDataType *data;
	eesErrorType errorCode;
	eesGroupType group = EES_DEFAULT_GROUP;


	/********************************************************************************/
	/*********************START OF THE MAIN PROGRAM**********************************/
	/********************************************************************************/

	/*Checks for arguments*/
	if (argc == 1)
	{
		eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT_NUMBER);
		exit(EES_INVALID_ARGUMENT_NUMBER);
	}
	
	/*Erases trash from variables*/
	memset(nickname	,0x00,MAXIMUM_USER_NICKNAME_LENGTH+1);
	memset(username	,0x00,MAXIMUM_EMAIL_LENGTH+1);
	memset(email	,0x00,MAXIMUM_EMAIL_LENGTH+1);
	memset(confEmail,0x00,MAXIMUM_EMAIL_LENGTH+1);
	opterr = 0;

	option = getopt_long(argc, argv, stringShortOptions,longOptions, NULL);
	switch (option)
	{
		/*******************************************Add User to Group*****************************************************/
		/************************************************OR***************************************************************/
		/*******************************************Change user group*****************************************************/
		case 'A':
		case 'a':
		case 'G':
		case 'g':
			/*Allocates space for data*/
			data = malloc (sizeof(eesUserDataType));
			memset(data,0x00,sizeof(eesUserDataType));			
		
			/*Get subotions*/
			argumentIndex = 0;
			while (argumentIndex < argc)
			{
				index = getsubopt (&argv[argumentIndex],tokens,&value);
								
				switch (index)
				{
					case USER:
						if(value != NULL)
							strcpy(systemUser,value);
					break;
					
					case LANGUAGE:
						if(value != NULL)
						{
							if (strcmp(value,"english") == 0) language = 0;
							if (strcmp(value,"portuguese") == 0) language = 1;
						}
					break;
					
					case NICKNAME:
						if(value != NULL)
							strcpy(nickname,value);
					break;
					
					case GROUP:
						if (!value)
							exit(EES_INVALID_ARGUMENT);
						if (strcmp(value, "administrators") == 0) group = administrador;
						if (strcmp(value,"owners") == 0) group = owner;
						if (strcmp(value,"users") == 0) group = user;
					break;
					
				}
				
				argumentIndex++;
			}	/*while*/
			
			/*Check for arguments*/
			if (strlen(systemUser) == 0)
			{
				eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
				exit (EES_INVALID_ARGUMENT);
			}
			/*Check for user*/
			errorCode = eesSearchUser(systemUser,data);
			if (errorCode != EES_OK)
			{
				eesGetTextErrorMessage(language,errorCode);
				exit (errorCode);
			}
			
			/*ask for password*/
			do
			{
				if (passwordErrorCounter == 0)
				{
					eesGetTextErrorMessage(language,EES_INCORRECT_PASSWORD);
					exit(EES_INCORRECT_PASSWORD);
				}
				passwordErrorCounter--;
				
				if (language == portuguese)	password = getpass("Entre com a senha de usuario :");
				if (language == english)	password = getpass("Enter with user password :");

			} while (eesUserLogin(systemUser,password,data) != EES_OK);
			
			/*Check for admin member*/
			if ((data->group != administrador) && (data->group != userAdmin) && (data->group != ownerAdmin) &&(data->group != root))
			{
				eesGetTextErrorMessage(language,EES_PERMISSION_DENIED);
				exit (EES_PERMISSION_DENIED);
			}
			
			/*Check for nickname argument*/
			if (strlen(nickname) != 0)
			{
				errorCode = eesSearchUser(nickname,data);
				if (errorCode != EES_OK)
				{
					eesGetTextErrorMessage(language,errorCode);
					exit(errorCode);
				}
				strcpy(username,nickname);
			}
			
			if ((option == 'a') || (option == 'A'))
				errorCode = eesAddUserToGroup(username,group);	
			if ((option == 'g') || (option == 'G'))
				errorCode = eesChangeUserGroup(username,group);
				
			if (errorCode != EES_OK)
				{
					eesGetTextErrorMessage(language,errorCode);
					exit(errorCode);
				}
				
			free(data);
			eesGetTextErrorMessage(language,EES_OK);	
		break;
		
		/************************************** Change user e-mail ***************************************************/
		case 'C':
		case 'c':
			
			/*Allocates space for data*/
			data = malloc (sizeof(eesUserDataType));
			memset(data,0x00,sizeof(eesUserDataType));
			
			/*Get subotions*/
			argumentIndex = 0;
			while (argumentIndex < argc)
			{
				index = getsubopt (&argv[argumentIndex],tokens,&value);
								
				switch (index)
				{
					case USER:
						if(value != NULL)
							strcpy(systemUser,value);
					break;
					
					case LANGUAGE:
						if(value != NULL)
						{
							if (strcmp(value,"english") == 0) language = 0;
							if (strcmp(value,"portuguese") == 0) language = 1;
						}
					break;
					
					case NICKNAME:
						if(value != NULL)
							strcpy(nickname,value);
					break;
					
					case USERNAME:
						if(value != NULL)
							strcpy(username,value); 
					break;	
					
					case EMAIL:
						if (!value)
							exit(EES_INVALID_ARGUMENT);
						strcpy(email,value);
					break;
					
					case CONFIRMATION:
						if (!value)
							exit(EES_INVALID_ARGUMENT);
						strcpy(confEmail,value);
					break;
				}
				
				argumentIndex++;
			}	/*while*/
			
			/*Check for valid arguments*/
			if (strlen(systemUser) == 0)
			{
				eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
				exit(EES_INVALID_ARGUMENT);
			}
			
			if (strlen(email) < EES_EMAIL_MINUMUM_LENGHT)
			{
				eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
				exit (EES_INVALID_ARGUMENT);	
			}
			
			if (strcmp(email,confEmail) != 0)
			{
				eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
				exit (EES_INVALID_ARGUMENT);	
			}
			
			/*ask for password*/
			do
			{
				if (passwordErrorCounter == 0)
				{
					eesGetTextErrorMessage(language,EES_INCORRECT_PASSWORD);
					exit(EES_INCORRECT_PASSWORD);
				}
				passwordErrorCounter--;
				
				if (language == portuguese)	password = getpass("Entre com a senha de usuario :");
				if (language == english)	password = getpass("Enter with user password :");

			} while (eesUserLogin(systemUser,password,data) != EES_OK);
			
			/*Check for nickname argument*/
			if (strlen(nickname) != 0)
			{       /*This will check if user is admin \/*/
				if ((data->group != administrador) && (data->group != userAdmin) && (data->group != ownerAdmin) &&(data->group != root))
				{
					eesGetTextErrorMessage(language,EES_PERMISSION_DENIED);
					exit (EES_PERMISSION_DENIED);
				}
				
				errorCode = eesSearchUser(nickname,data);
				if (errorCode != EES_OK)
				{
					eesGetTextErrorMessage(language,errorCode);				
					exit(errorCode);
				}
				strcpy(systemUser, nickname);
			}
			
			errorCode = eesChangeEmailAdress(systemUser, email, language);
			if (errorCode != EES_OK)
			{
				eesGetTextErrorMessage(language,errorCode);				
				exit(errorCode);
			}
			
			free(data);
			eesGetTextErrorMessage(language, EES_OK);
			
		break; /*Change e-mail*/
		
		/***************************************Edit user name********************************************************/
		case 'E':
		case 'e':
			
			/*Allocates space for data*/
			data = malloc (sizeof(eesUserDataType));
			memset(data,0x00,sizeof(eesUserDataType));
			
			/*Get subotions*/
			argumentIndex = 0;
			while (argumentIndex < argc)
			{
				index = getsubopt (&argv[argumentIndex],tokens,&value);
								
				switch (index)
				{
					case USER:
						if(value != NULL)
							strcpy(systemUser,value);
					break;
					
					case LANGUAGE:
						if(value != NULL)
						{
							if (strcmp(value,"english") == 0) language = 0;
							if (strcmp(value,"portuguese") == 0) language = 1;
						}
					break;
					
					case NICKNAME:
						if(value != NULL)
							strcpy(nickname,value);
					break;
					
					case USERNAME:
						if(value != NULL)
							strcpy(username,value); 
					break;	
				}
				
				argumentIndex++;
			}	/*while*/
			
			/*Check for valid arguments*/
			if (strlen(systemUser) == 0)
			{
				eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
				exit(EES_INVALID_ARGUMENT);
			}
			
			if (strlen(username) == 0)
			{
				eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
				exit(EES_INVALID_ARGUMENT);
			}
			
			/*Check for user*/
			errorCode = eesSearchUser(systemUser,data);
			if (errorCode != EES_OK)
			{
				eesGetTextErrorMessage(language,errorCode);
				exit (errorCode);
			}
			
			/*ask for password*/
			do
			{
				if (passwordErrorCounter == 0)
				{
					eesGetTextErrorMessage(language,EES_INCORRECT_PASSWORD);
					exit(EES_INCORRECT_PASSWORD);
				}
				passwordErrorCounter--;
				
				if (language == portuguese)	password = getpass("Entre com a senha de usuario :");
				if (language == english)	password = getpass("Enter with user password :");

			} while (eesUserLogin(systemUser,password,data) != EES_OK);
			
			/*Check for nickname argument*/
			if (strlen(nickname) != 0)
			{       /*This will check if user is admin \/*/
				if ((data->group != administrador) && (data->group != userAdmin) && (data->group != ownerAdmin) &&(data->group != root))
				{
					eesGetTextErrorMessage(language,EES_PERMISSION_DENIED);
					eesGetTextErrorMessage(language,EES_ERROR_EDIT_NAME);
					exit (EES_PERMISSION_DENIED);
				}
				
				errorCode = eesSearchUser(nickname,data);
				if (errorCode != EES_OK)
				{
					eesGetTextErrorMessage(language,errorCode);				
					exit(errorCode);
				}
			}
			
			strcpy(data->fullName,username);
			errorCode = eesEditUserName(data);
			if (errorCode != EES_OK)
				eesGetTextErrorMessage(language,errorCode);
						
			free(data);		
			eesGetTextErrorMessage(language,EES_OK);	
		break; /*Edit*/
		
		/*****************************************************Show help screen*****************************************************/
		case 'H':
		case 'h':
		
			argumentIndex = 0;
		
			while (argumentIndex < argc)
			{
				index = getsubopt (&argv[argumentIndex],tokens,&value);
								
				switch (index)
				{
					case LANGUAGE:
						if (strcmp(value,"english") == 0) language = 0;
						if (strcmp(value,"portuguese") == 0) language = 1;
					break;
				}
				
				argumentIndex++;
			}	
			
			eesShowCliHelp(language);
			
		break; /*Help*/
		
		
		/*****************************************************Invite Users to system*****************************************************/
		case 'I':
		case 'i': 

			/*Initiate pointer*/
			data = malloc (sizeof(eesUserDataType));
			if (!data)
				exit (EES_ERROR_INSUFICIENT_MEMORY);

			
			/*Checks for suboptions*/
			argumentIndex = 0;
			while (argumentIndex < argc)
			{
				index = getsubopt (&argv[argumentIndex],tokens,&value);
								
				switch (index)
				{
					case LANGUAGE:
						if (strcmp(value,"english") == 0) language = 0;
						if (strcmp(value,"portuguese") == 0) language = 1;
					break;
					
					case USER:
						if (!value)
							exit(EES_INVALID_ARGUMENT);
						strcpy(systemUser,value);
					break;
					
					case EMAIL:
						if (!value)
							exit(EES_INVALID_ARGUMENT);
						strcpy(email,value);
					break;
					
					case CONFIRMATION:
						if (!value)
							exit(EES_INVALID_ARGUMENT);
						strcpy(confEmail,value);
					break;
					
					case GROUP:
						if (!value)
							exit(EES_INVALID_ARGUMENT);
						if (strcmp(value, "administrators") == 0) group = administrador;
						if (strcmp(value,"owners") == 0) group = owner;
			
					break;
					
				}
			
				argumentIndex++;
			} /*while*/		
			

			/*Test arguments*/
			if ((strlen(systemUser) == 0) || (strlen(email) == 0) || (strlen(confEmail) == 0))
			{
				eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
				exit (EES_INVALID_ARGUMENT);
			}
			
			errorCode = eesSearchUser(systemUser,data);
			if (errorCode != EES_OK)
			{
				eesGetTextErrorMessage(language,errorCode);
				exit(errorCode);				
			}
			
			
			/*User login*/			
			do
			{
				if (passwordErrorCounter == 0)
				{
					eesGetTextErrorMessage(language,EES_INCORRECT_PASSWORD);
					exit(EES_INCORRECT_PASSWORD);
				}
				passwordErrorCounter--;
				
				if (language == portuguese)	password = getpass("Entre com a senha de usuario :");
				if (language == english)	password = getpass("Enter with user password :");

			} while (eesUserLogin(systemUser,password,data) != EES_OK);
			
			/*Check for system admins*/
			if ((data->group != administrador) && (data->group != userAdmin) && (data->group != ownerAdmin) && (data->group != root))
				group = 4;
			
			
			/*Clear data variable, because we don't need it*/
			memset(data,0x00,sizeof(eesUserDataType));

			/*Save new user group*/	
			data->group = group;

			/*Get the username from CLI*/
			do
			{
				if (language == portuguese)	printf("Entre com o nome do completo do usuario a ser convidado:");
				if (language == english)	printf("Enter with the full name of the invited user:");
				fgets(username,MAXIMUM_EMAIL_LENGTH,stdin);
				
				if (username[strlen(username)-1] == '\n')
					username[strlen(username)-1] = '\0';
				
				if (language == portuguese)
				{
					printf("Nome do usuario : \"%s\"\nEmail : %s\nGrupo: %s\n",username,email,groupsArray[group-1][1]);
					printf("Pressione ENTER para confirmar convite, qualquer outra tecla para corrigir");					
				}
				if (language == english)
				{
					printf("User name : %s\nEmail : %s\nGroup: %s\n",username,email,groupsArray[group-1][0]);
					printf("Press ENTER to confirm user invite, any other key to change username");
				}
				
				confirm = fgetc(stdin);
				
				
			} while (confirm != '\n');

			
			strcpy(data->fullName,username);

			/*Check for email*/
			strcpy(data->email,email);

			/*Creating new user*/
			errorCode = eesAddUser(data);
			if (errorCode != EES_OK)
			{
				eesGetTextErrorMessage(language,errorCode);
				exit(errorCode);
			}
			
			errorCode = eesGenerateTextFile();
			if (errorCode != EES_OK)
			{
				eesGetTextErrorMessage(language,errorCode);
				exit(errorCode);
			}
			
			errorCode = eesSendConfirmationMail(username,data->codedPassword,email,data->nickname,language);
			if (errorCode != 0)
				printf("Erro enviando e-mail : %d\n",errorCode);
			free(data);
			eesGetTextErrorMessage(language,EES_OK);
		break; /*invite*/
		
		/*****************************************************Initiate Ncurses interface*****************************************************/
		case 'N':
		case 'n':
			/*Checks for username*/
			if (argv[optind] != NULL)
				strcpy(nickname,argv[optind]);

			/*Check for language subotiopns*/
			argumentIndex = 0;
			while (argumentIndex < argc)
			{
				index = getsubopt (&argv[argumentIndex],tokens,&value);
								
				switch (index)
				{
					
					case LANGUAGE:
						if (strcmp(value,"english") == 0) language = 0;
						if (strcmp(value,"portuguese") == 0) language = 1;
					break;
				}
				
				argumentIndex++;
			}	

			eesRunNcursesInterface(nickname,english);
		break; /*Ncurses*/
		
		/*****************************************************Change user password************************************************/
		case 'P':
		case 'p':
			/*Initiate pointer*/
			data = malloc (sizeof(eesUserDataType));
			if (!data)
				exit (EES_ERROR_INSUFICIENT_MEMORY);
			
			
			/*Checks for suboptions*/
			argumentIndex = 0;
			while (argumentIndex < argc)
			{
				index = getsubopt (&argv[argumentIndex],tokens,&value);
								
				switch (index)
				{
					case LANGUAGE:
						if (strcmp(value,"english") == 0) language = 0;
						if (strcmp(value,"portuguese") == 0) language = 1;
					break;
					
					case USER:
						if (!value)
						{
							eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
							exit(EES_INVALID_ARGUMENT);
						}						
						strcpy(systemUser,value);
					break;
					
					case NICKNAME:
						if (!value)
						{
							eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
							exit(EES_INVALID_ARGUMENT);
						}
						strcpy(nickname,value);
					break;
					
				}
				argumentIndex++;
			}
		
			/*Check for user name*/
			errorCode = eesSearchUser(systemUser,data);
			if (errorCode != EES_OK)
			{
				eesGetTextErrorMessage(language,errorCode);
				exit(errorCode);				
			}
			
			
			/*User login*/			
			do
			{
				if (passwordErrorCounter == 0)
				{
					eesGetTextErrorMessage(language,EES_INCORRECT_PASSWORD);
					exit(EES_INCORRECT_PASSWORD);
				}
				passwordErrorCounter--;
				
				if (language == portuguese)	password = getpass("Entre com a senha de usuario :");
				if (language == english)	password = getpass("Enter with user password :");

			} while (eesUserLogin(systemUser,password,data) != EES_OK);
			
			
			if (strlen(nickname) != 0)
			{
				if ((data->group != administrador) && (data->group != userAdmin) && (data->group != ownerAdmin) &&(data->group != root))
				{
					eesGetTextErrorMessage(language,EES_PERMISSION_DENIED);
					eesGetTextErrorMessage(language,EES_ERROR_EDIT_NAME);
					exit (EES_PERMISSION_DENIED);
				}
				
				errorCode = eesSearchUser(nickname,data);
				if (errorCode != EES_OK)
				{
					eesGetTextErrorMessage(language,errorCode);				
					exit(errorCode);
				}
			}
			
			/*Data now contais desired user to change password*/
			do
			{
						
				if (language == portuguese)	password = getpass("Entre com a nova senha de usuario :");
				if (language == english)	password = getpass("Enter with new user password :");
				
				strcpy(passwordConfirm,password);
				
				if (language == portuguese)	password = getpass("Confirme a nova senha :");
				if (language == english)	password = getpass("Confirm new user password :");
				
				
			} while (strcmp(password,passwordConfirm) != 0);
			
			strcpy(data->codedPassword,password);
			
			errorCode = eesChangeUserPassword(data);
			if (errorCode != EES_OK)
			{
				eesGetTextErrorMessage(language,errorCode);				
				exit(errorCode);
			}
			
			eesGetTextErrorMessage(language,EES_OK);
		
		break; /*Password*/
		
		
		/*****************************************************Remove user from the system************************************************/
		case 'R':
		case 'r':
			/*Allocates space for data*/
			data = malloc (sizeof(eesUserDataType));
			memset(data,0x00,sizeof(eesUserDataType));	
			
			/*Checks for suboptions*/
			argumentIndex = 0;
			while (argumentIndex < argc)
			{
				index = getsubopt (&argv[argumentIndex],tokens,&value);
								
				switch (index)
				{
					case LANGUAGE:
						if (strcmp(value,"english") == 0) language = 0;
						if (strcmp(value,"portuguese") == 0) language = 1;
					break;
					
					case USER:
						if (!value)
							exit(EES_INVALID_ARGUMENT);
						strcpy(systemUser,value);
					break;
					
					case NICKNAME:
						if(value != NULL)
							strcpy(nickname,value);
					break;		
				}
				
				argumentIndex++;
			}		
			
			/*Test arguments*/
			if (strlen(systemUser) == 0)
			{
				eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
				exit (EES_INVALID_ARGUMENT);
			}

			/*ask for password*/
			do
			{
				if (passwordErrorCounter == 0)
				{
					eesGetTextErrorMessage(language,EES_INCORRECT_PASSWORD);
					exit(EES_INCORRECT_PASSWORD);
				}
				passwordErrorCounter--;
				
				if (language == portuguese)	password = getpass("Entre com a senha de usuario :");
				if (language == english)	password = getpass("Enter with user password :");

			} while (eesUserLogin(systemUser,password,data) != EES_OK);
			
			if (strlen(nickname) != 0)
			{
				if ((data->group != administrador) && (data->group != userAdmin) && (data->group != ownerAdmin) &&(data->group != root))
				{
					eesGetTextErrorMessage(language,EES_PERMISSION_DENIED);
					eesGetTextErrorMessage(language,EES_ERROR_EDIT_NAME);
					exit (EES_PERMISSION_DENIED);
				}
				
				errorCode = eesSearchUser(nickname,data);
				if (errorCode != EES_OK)
				{
					eesGetTextErrorMessage(language,errorCode);				
					exit(errorCode);
				}
			}
			
			errorCode = eesRemoveUser(data->nickname);
			if (errorCode != EES_OK)
			{
				eesGetTextErrorMessage(language,errorCode);				
				exit(errorCode);
			}
			free(data);
			eesGetTextErrorMessage(language,EES_OK);
			
		break; /*Remove*/
	
	
		/*****************************************************Initiate system*****************************************************/
		case 'Z':
		case 'z':
			if (getuid() != EES_ADMINISTRATOR_USER_IDENTIFIER)
			{
				eesGetTextErrorMessage(language,EES_PERMISSION_DENIED);
				exit (EES_PERMISSION_DENIED);
			}
			
			data = malloc (sizeof(eesUserDataType));
			if (!data)
				exit (EES_ERROR_INSUFICIENT_MEMORY);
			
			/*Checks for suboptions*/
			argumentIndex = 0;
			while (argumentIndex < argc)
			{
				index = getsubopt (&argv[argumentIndex],tokens,&value);
								
				switch (index)
				{
					case LANGUAGE:
						if (strcmp(value,"english") == 0) language = 0;
						if (strcmp(value,"portuguese") == 0) language = 1;
					break;
					
					case USERNAME:
						if (!value)
							exit(EES_INVALID_ARGUMENT);
						strcpy(username,value);
					break;
					
					case EMAIL:
						if (!value)
							exit(EES_INVALID_ARGUMENT);
						strcpy(email,value);
					break;
					
					case CONFIRMATION:
						if (!value)
							exit(EES_INVALID_ARGUMENT);
						strcpy(confEmail,value);
					break;
				}
				
				argumentIndex++;
			}		
			
			/*Test arguments*/
			if ((strlen(username) == 0) || (strlen(email) == 0) || (strlen(confEmail) == 0))
			{
				eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
				exit (EES_INVALID_ARGUMENT);
				
			}
			
			/*Check username lenght*/
			if (strlen(username) < EES_MINUMUM_FULL_NAME_LENGHT)
			{
				eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
				exit (EES_INVALID_ARGUMENT);	
			}
			
			strcpy(data->fullName,username);
			
			/*Check for email*/
			if (strlen(email) < EES_EMAIL_MINUMUM_LENGHT)
			{
				eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
				exit (EES_INVALID_ARGUMENT);	
			}
			if (strcmp(email,confEmail) != 0)
			{
				eesGetTextErrorMessage(language,EES_INVALID_ARGUMENT);
				exit (EES_INVALID_ARGUMENT);	
			}
			
			strcpy(data->email,email);
			
			/*Adds root as nickname*/
			strcpy(data->nickname,"root");
			
			data->group = root;
			data->flag = ok;
			
			errorCode = eesAddUser(data);
			if (errorCode != EES_OK)
			{
				eesGetTextErrorMessage(language,errorCode);
				exit (errorCode);
			}
			
			free(data);
			
			eesGetTextErrorMessage(language,EES_OK);
			
		break;
	
	}/*switch option*/
	

	return EES_OK;
}
