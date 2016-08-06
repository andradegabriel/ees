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

#include "eesConst.h"

#ifndef __EES_TYPES_H__
#define __EES_TYPES_H__		"@(#)eesTypes.h $Revision$"

/*===========================================================================================================*/

typedef enum _eesLanguageType
{
  eesEnglish			      = 0,
  eesPortuguese			    = 1,
  eesLanguagesAmount 		= 2	/* ATENTION! eesLanguagesAmount must always be last element in this enum */
} eesLanguageType;

/*===========================================================================================================*/

typedef enum boolean
{
  false   = 0,
  true    = 1
} boolean;

/*===========================================================================================================*/

typedef unsigned long long eesUserIdentifierType;

/*===========================================================================================================*/

typedef enum _eesUserProfileType
{
  administrator                 = 1,
  professor                     = 2,
  administratorProfessor        = 3,
  alumn                         = 4,
  adminitratorAlumn             = 5
} eesUserProfileType;

/*===========================================================================================================*/

typedef struct eesUserDataType
{
  eesUserIdentifierType   userIdentifier;
  char                    eesNickname[MAXIMUM_USER_NICKNAME_LENGTH];
  char                    password[MAXIMUM_PASSWORD_LENGTH];
  char                    passwordConfirmation[MAXIMUM_PASSWORD_LENGTH];
  eesUserProfileType      profile;
  char                    fullName[MAXIMUM_USER_FULL_NAME_LENGTH];
  char                    fullNameConfirmation[MAXIMUM_USER_FULL_NAME_LENGTH];
  char                    email[MAXIMUM_EMAIL_LENGTH];
  char                    emailConfirmation[MAXIMUM_EMAIL_LENGTH];
  struct eesUserDataType  *previous, *next;
} eesUserDataType;

/*===========================================================================================================*/

typedef enum eesCryptAlgorithms
{
  eesDes              = 0, 
  eesMd5              = 1, 
  eesSha256           = 2,
  eesSha512           = 3
} eesCryptAlgorithms;

/*===========================================================================================================*/

#endif


/* $RCSfile$ */
