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


#include <stdlib.h>                           
#include <stdio.h>                            
#include <ncurses.h>     
#include <string.h>
#include <unistd.h>
#include <menu.h>
                                              
#include "eesConst.h"                       
#include "eesTypes.h"                       
#include "eesError.h"                       
#include "eesFunctions.h"                   
#include "eesShowNcursesHelp.h"                   

#include "eesAddUser.h"                                            
#include "eesRunNcursesInterface.h"                          
#include "eesChangeUserPassword.h"

char *choices[][2] = 
{
	{"Invite User","Convidar usuario"},
	{"Change e-mail","Trocar e-mail"},
	{"Change username","Trocar nome"},
	{"Show Help","Mostrar Ajuda"},
	{"Change Password","Trocar Senha"},
	{"Remove user","Remover usuário"},
	{"Change Group","Trocar Grupo"},
	{"Add to Group","Adicionar ao grupo"},
};

char *description[][2] = 
{
	{"        : Invite a friend to join the system as a user","        : Convida um amigo para participar do sistema"},
	{"        : Change your e-mail","        : Altera seu e-mail"},
	{"        : Change the username and generates a new nickname","        : Altera o nome de usuario e gera um novo nickname"},
	{"        : Show help screen (semi implemented)","        : Mostra tela de ajuda (nao feito ainda)"},
	{"        : Change user password","        : Troca senha de usuario"},
	{"        : Remove user from system","        : Remove usuário do sistema"},
	{"        : Change user group","        : Troca grupo do usuario"},
	{"        : Add user to group","        : Adiciona usuario ao grupo"}
};
       
 
char *text[][2]=
{
/*0*/	{"Welcome to Ncurses interface","Bem vindo a interface Ncurses"},
/*1*/	{"Press F2 to exit","Pressione F2 para sair"},
/*2*/	{"Enter with your nickname: ","Entre com o nickname: "},
/*3*/	{"User not found\nPress any key to exit","Usuário não encontrado\nPressione qualquer tecla para sair"},	
/*4*/	{"Enter with user password :","Entre com a senha :"},	
/*5*/	{"Maximun number of errors\nPress any key to exit","Maximo numero de tentativas\nPressione qualquer tecla para sair"},	
/*6*/	{"Enter with the full name : ","Entre com o nome completo : "},	
/*7*/	{"Enter with e-mail  : ","Entre com o e-mail : "},	
/*8*/	{"Confirm the e-mail : ","Confirme o e-mail  : "},	
/*9*/	{"Successfully invite the user","Usuario convidade com sucesso"},	
/*10*/	{"Select user that will have his username changed : ","Selecione o usuário que terá seu nome de usuário alterado : "},	
/*11*/	{"Enter with the new full name : ","Entre com o novo completo : "},	
/*12*/	{"Select user that will have his password changed : ","Selecione o usuário que terá sua senha alterada : "},	
/*13*/	{"Enter with the new password : ","Entre com a nova senha : "},	
/*14*/	{"Confirm your password : ","Confirme sua senha :"},	
/*15*/	{"Passwords didn't match\nPress any key to exit","Senhas nao batem\nPressione qualquer tecla para sair"},	
/*16*/	{"Password changed, press any key to return","Senha alterada com sucesso\nPressione qualquer tecla pasa voltar"},	
/*17*/	{"Select user to change his e-mail : ","Selectione o usuário para ter seu e-mail alterado : "},	
/*18*/	{"Enter with the new e-mail : ","Entre com o novo e-mail : "},	
/*19*/	{"Confirm the e-mail        : ","Confirme o e-mail       : "},	
/*20*/	{"Select user to have his group changed : ","Selecione o usuário para ter seu grupo alterado : "},	
/*21*/	{"User name : ","Nome do usuário : "},	
/*22*/	{"Select the desired group\n'a' for admin\n'u' for user\n'o'for owner\n","Selecione o grupo desejado\n'a' para administrador\n'u' para usuario\n'p' para proprietário\n"},	
/*23*/	{"None of the options was selected, press any key to continue","Nenhuma opção foi selecionada, pressione qualquer tecla para sair"},	
/*24*/	{"Select User to delete from system : ","Selecione o usuário para deletar do sistema : "},	
/*25*/	{"Are you sure you want to remove this account ? Y/N\n","Tem certeza que deseja remover este usuário ? S/N\n"},	
/*26*/	{"User Removed, press any key to return","Usuário Removido com sucesso, pressione qualquer tecla para voltar"},	
/*27*/	{"User wasn't remove, press any key to return","Usuário nao foi apagado, pressione qualquer tecla para voltar"},	
};              

                       
int adminChoices = 0;  

eesErrorType eesRunNcursesInterface (char *nickname, eesLanguageType language)
{
	eesUserDataType data;
	unsigned passwordErrorCounter = EES_PASSWORD_ATTEMPTS;	
	char password[EES_PASSWORD_MAXIMUM_LENGHT+1];
	ITEM **myItems;
	int option;				
	MENU *myMenu;
	int numberChoices; 
	int index;
	int loop = 1;
	
	
	/*Init ncurses screen*/
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	
	if ((nickname == NULL) || (strlen(nickname) == 0))
	{	
		printw("%s",text[2][language]);
		getstr(nickname);	
	}
	
	if (eesSearchUser(nickname, &data) == EES_ERROR_USERNAME_NOT_FOUND)
	{
		printw("%s",text[3][language]);
		getch();
		endwin();
		return EES_ERROR_USERNAME_NOT_FOUND;
	}
	
	do
	{
		noecho();
		passwordErrorCounter--;
		if (passwordErrorCounter == 0)
		{
			printw("%s",text[5][language]);
			getch();
			endwin();
			return EES_PERMISSION_DENIED;
		}
		
		printw("%s",text[4][language]);	
		getstr(password);

	}
	while ((passwordErrorCounter != 0) && (eesUserLogin(nickname,password, &data) != EES_OK));
	
	/*Check for admin member*/
	if ((data.group != administrador) && (data.group != userAdmin) && (data.group != ownerAdmin) &&(data.group != root))
		adminChoices = 2;
	
	printw("%s,%s",nickname,text[0][language]);
	getch();
	
	numberChoices = ARRAY_SIZE(choices) - adminChoices;
	myItems = (ITEM **)calloc(numberChoices + 1, sizeof(ITEM *));

	for(index = 0; index < numberChoices; index++)
	        myItems[index] = new_item(choices[index][language], description[index][language]);
	myItems[numberChoices] = (ITEM *)NULL;

	myMenu = new_menu((ITEM **)myItems);
	
	post_menu(myMenu);
	refresh();
	
	
	mvprintw(LINES-3,0,"%s",text[1][language]);
	index = 1;
	while(((option = getch()) != KEY_F(2)) && (loop == 1))
	{   
		switch(option)
	    {	
			case KEY_DOWN:
				if (index != numberChoices) index++;
		        menu_driver(myMenu, REQ_DOWN_ITEM);
			break;
			
			case KEY_UP:
				if (index != 1) index--;
				menu_driver(myMenu, REQ_UP_ITEM);
			break;
			
			case 10:
				switch (index)
				{
						
					case EES_CURSES_INVITE:
						unpost_menu(myMenu);
						eesCursesInvite(data,language);
						post_menu(myMenu);
						noecho();
						refresh();
					break;
					
					case EES_CURSES_SHOW_HELP:
						unpost_menu(myMenu);
						eesShowNcursesHelp(language);
						post_menu(myMenu);
						noecho();
						refresh();
					break;
					
					case EES_CURSES_CHANGE_EMAIL:
						unpost_menu(myMenu);
						eesCursesChangeEmail(&data,language);
						post_menu(myMenu);
						noecho();
						refresh();
					break;
					
					case EES_CURSES_CHANGE_USERNAME:
						unpost_menu(myMenu);
						eesCursesChangeUsername(data, language);
						post_menu(myMenu);
						noecho();
						refresh();
					break;
					
					case EES_CURSES_PASSWORD:
						unpost_menu(myMenu);
						eesCursesChangePassword(&data, language);
						post_menu(myMenu);
						noecho();
						refresh();
					break;
					
					case EES_CURSES_REMOVE:
						unpost_menu(myMenu);
						eesCursesRemoveUser(data, language);
						post_menu(myMenu);
						noecho();
						refresh();
					break;
					
					case EES_CURSES_CHANGE_GROUP:
						unpost_menu(myMenu);
						eesCursesChangeGroup('c',language);
						post_menu(myMenu);
						noecho();
						refresh();
					break;
					
					case EES_CURSES_ADD_GROUP:
						unpost_menu(myMenu);
						eesCursesChangeGroup('a',language);
						post_menu(myMenu);
						noecho();
						refresh();
					break;
					
				}
			break;	
		}
		mvprintw(LINES-3,0,"%s",text[1][language]);
		refresh();
	}	

	free_item(myItems[0]);
	free_item(myItems[1]);
	free_menu(myMenu);
	endwin();
	
	return EES_OK;
}  




eesErrorType eesCursesChangeEmail(eesUserDataType *data, eesLanguageType language)
{
	char email[EES_EMAIL_MAXIMUM_LENGHT+1];
	char confEmail[EES_EMAIL_MAXIMUM_LENGHT+1];
	char nickname[EES_NICKNAME_MAXIMUM_LENGHT +1];
	eesErrorType errorCode;
	
	memset(nickname,0x00,EES_NICKNAME_MAXIMUM_LENGHT);
	
	echo();
	
	/*Check for admin member*/
	if ((data->group != administrador) && (data->group != userAdmin) && (data->group != ownerAdmin) &&(data->group != root))
	{
		printw("%s",text[17][language]);
		getstr(nickname);
	}
	
	if (strlen (nickname) == 0)
		strcpy(nickname,data->nickname);
		
	printw("%s",text[18][language]);	
	getstr(email);
	
	printw("%s",text[19][language]);	
	getstr(confEmail);
	
	if (strcmp (email,confEmail) != 0)
	{
		printw("a");
		return EES_INVALID_ARGUMENT;
	}
	
	errorCode = eesChangeEmailAdress(nickname,email,language);
	
	if (errorCode != EES_OK) return errorCode;
	
	getch();
	noecho();
	
	return EES_OK;
}

eesErrorType eesCursesChangeGroup(char operation, eesLanguageType language)
{
	eesUserDataType data;
	char nickname[EES_NICKNAME_MAXIMUM_LENGHT + 1];
	eesErrorType errorCode;
	eesGroupType group;
	char selectedGroup;
	
	
	echo();
	printw("%s",text[20][language]);
	getstr(nickname);

	errorCode = eesSearchUser(nickname,&data);
	if (errorCode != EES_OK)
	{
		eesGetCursesErrorMessage(language,errorCode);
		return errorCode;
	}
		
	printw("%s : %s\n",text[21][language],data.fullName);
	printw("%s",text[22][language]);
	selectedGroup = getch();
	switch (selectedGroup)
	{
		case 'a' :
			group = administrador;
			break;
		case 'u' :
			group = user;
			break;
		case 'o' :
		case 'p' :
			group = owner;
			break;
		
		default :	
			printw("%s",text[23][language]);
			getch();
			return EES_OK;
	}
	
	if (operation == 'a')
		errorCode = eesAddUserToGroup(nickname,group);	
	if (operation == 'c')
		errorCode = eesChangeUserGroup(nickname,group);
	
	if (errorCode != EES_OK)
		eesGetCursesErrorMessage(language,errorCode);	
		
	return errorCode;	
}



eesErrorType eesCursesInvite(eesUserDataType userData, eesLanguageType language)
{
	char username[EES_FULL_NAME_MAXIMUM_LENGHT+1];
	char email[EES_EMAIL_MAXIMUM_LENGHT+1];
	char confEmail[EES_EMAIL_MAXIMUM_LENGHT+1];
	eesUserDataType data;
	eesErrorType errorCode;
	
	echo();
	
	printw("%s",text[6][language]);	
	getstr(username);
	
	printw("%s",text[7][language]);	
	getstr(email);
	
	printw("%s",text[8][language]);	
	getstr(confEmail);
	
	/*Check for email*/
	if (strlen(email) < EES_EMAIL_MINUMUM_LENGHT)
	{
		eesGetCursesErrorMessage(language,EES_INVALID_ARGUMENT);
		move(0,0);
		clrtobot();
		return (EES_INVALID_ARGUMENT);	
	}
	if (strcmp(email,confEmail) != 0)
	{
		eesGetCursesErrorMessage(language,EES_INVALID_ARGUMENT);
		move(0,0);
		clrtobot();
		return (EES_INVALID_ARGUMENT);		
	}
	
	/*Check for username*/
	if (strlen(username) == 0)
	{
		eesGetCursesErrorMessage(language,EES_INVALID_ARGUMENT);
		move(0,0);
		clrtobot();
		return (EES_INVALID_ARGUMENT);		
	}
	
	strcpy(data.fullName,username);
	strcpy(data.email,email);
	data.group = user;
	
	errorCode = eesAddUser(&data);
	if (errorCode != EES_OK) 
	{
		eesGetCursesErrorMessage(language,errorCode);	
		return errorCode;
	}
	
	eesGenerateTextFile();
	
	errorCode = eesInvitationMail (username,userData.fullName,data.codedPassword,email,data.nickname,language);
	if (errorCode != EES_OK)
	{
		eesGetCursesErrorMessage(language,errorCode);	
		return errorCode;
	}

	printf("%s",text[9][language]);

	getch();
	move(0,0);
	clrtobot();
	
	return EES_OK;
}


eesErrorType eesCursesChangePassword(eesUserDataType *data, eesLanguageType language)
{
	char password[EES_PASSWORD_MAXIMUM_LENGHT+1];
	char confirm [EES_PASSWORD_MAXIMUM_LENGHT+1];	
	char nickname[EES_NICKNAME_MAXIMUM_LENGHT+1];
	eesErrorType errorCode;
	eesUserDataType userData;
	
	memset(nickname,0x00,EES_NICKNAME_MAXIMUM_LENGHT);
	
	if (adminChoices == 0)
	{
		printw("%s",text[12][language]);
		getstr(nickname);
	}	
	
	if (strlen(nickname) == 0)
		strcpy(nickname,data->nickname);
	
	errorCode = eesSearchUser(nickname,&userData);
	if (errorCode != EES_OK) return errorCode;
	
	noecho();
	printw("%s",text[13][language]);
	getstr(password);
	printw("%s",text[14][language]);
	getstr(confirm);
	if (strcmp(password,confirm) != 0)
	{
		printw("%s",text[15][language]);
		getch();
		return EES_OK;
	}
	
	strcpy(userData.codedPassword,password);
	errorCode = eesChangeUserPassword(data);
	if (errorCode != EES_OK)
	{
		eesGetCursesErrorMessage(language,errorCode);	
		return errorCode;
	}
	
	printw("%s",text[16][language]);
	getch();
	
	return EES_OK;
}


eesErrorType eesCursesChangeUsername(eesUserDataType data,eesLanguageType language)
{
	char username[EES_FULL_NAME_MAXIMUM_LENGHT+1];
	char nickname[EES_NICKNAME_MAXIMUM_LENGHT + 1];
	eesUserDataType userData;
	eesErrorType errorCode;
	
	echo();
	
	memset(nickname,0x00,EES_NICKNAME_MAXIMUM_LENGHT);
	
	if (adminChoices == 0)
	{
		printw("%s",text[10][language]);
		getstr(nickname);
	}
	
	if (strlen(nickname) == 0)
		strcpy(nickname,data.nickname);

	errorCode = eesSearchUser(nickname,&userData);
	if (errorCode != EES_OK) 
	{
		eesGetCursesErrorMessage(language,errorCode);	
		return errorCode;
	}
	
	printw("%s",text[11][language]);	
	getstr(username);
		
	/*Check for username*/
	if (strlen(username) < EES_MINUMUM_FULL_NAME_LENGHT)
	{
		eesGetCursesErrorMessage(language,EES_INVALID_ARGUMENT);	
		move(0,0);
		clrtobot();
		return (EES_INVALID_ARGUMENT);		
	}
	
	strcpy(userData.fullName,username);
	
	errorCode = eesEditUserName(&userData);
	if (errorCode != EES_OK); 
	{
		eesGetCursesErrorMessage(language,errorCode);	
		return errorCode;
	}
		
	getch();
	move(0,0);
	clrtobot();
	
	return EES_OK;
}         

eesErrorType eesCursesRemoveUser (eesUserDataType data, eesLanguageType language)
{
	eesErrorType errorCode;
	char nickname[EES_NICKNAME_MAXIMUM_LENGHT + 1];
	char op;
	
	echo();
	if (adminChoices == 0)
	{
		printw("%s",text[24][language]);
		getstr(nickname);
	}
	
	if (strlen(nickname) == 0)
		strcpy(nickname,data.nickname);
		
	printw("%s",text[25][language]);
		
	op = getch();
	if ((op == 'Y') || (op == 'y') || (op == 'S') || (op == 's'))
	{	
		errorCode = eesRemoveUser(nickname);	
		if (errorCode != EES_OK)
		{
			eesGetCursesErrorMessage(language,errorCode);	
			return errorCode;
		}
		
		printw("%s",text[26][language]);
	}
	
	else
		printw("%s",text[27][language]);
	
	getch();
	noecho();
	return EES_OK;
}   

/* $RCSfile$ */
