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


static const char eesCliErrosMessages[][]=
{
  /* English Error Messages */
  {
    "Successful operation!",
    "Invalid argument."
  },

  /* Portuguese Error Messages */
  {
    "Operacao realizada com sucesso.",
    "Argumento invalido."
  }
};

static const char eesNcursesErrosMessages[][]=
{
  /* English Error Messages */
  {
    "Successful operation!",
    "Invalid argument."
  },

  /* Portuguese Error Messages */
  {
    "Operacao realizada com sucesso.",
    "Argumento invalido."
  }
};

static const char eesWebErrosMessages[][]=
{
  /* English Error Messages */
  {
    "Successful operation!",
    "Invalid argument."
  },

  /* Portuguese Error Messages */
  {
    "Operacao realizada com sucesso.",
    "Argumento invalido."
  }
};

/******************************************************************************************************************/

/* TODO */
/*
* char *
* EesGetCliErrorMessage (eesErrorType, eesLanguageType)
*
* Arguments:
* eesErrorType - number of the error type (I)
* eesLanguageType - language type of the message (I)
*
* Returned code:
*  TODO
* xyzOk - Function has been executed successfully.
*
* Description:
* This function gets the error message that will be shown in CLI interface. */ 
char *
EesGetCliErrorMessage (eesErrorType, eesLanguageType)
{
}

/******************************************************************************************************************/

/* TODO */
/*
* char *
* EesGetNcursesErrorMessage (eesErrorType, eesLanguageType)
*
* Arguments:
* eesErrorType - number of the error type (I)
* eesLanguageType - language type of the message (I)
*
* Returned code:
*  TODO
* xyzOk - Function has been executed successfully.
*
* Description:
* This function gets the error message that will be shown in Ncurses interface. */  
char *
EesGetNcursesErrorMessage (eesErrorType, eesLanguageType)
{
}

/******************************************************************************************************************/

/* TODO */
/*
* char *
* EesGetCliErrorMessage (eesErrorType, eesLanguageType)
*
* Arguments:
* eesErrorType - number of the error type (I)
* eesLanguageType - language type of the message (I)
*
* Returned code:
*  TODO
* xyzOk - Function has been executed successfully.
*
* Description:
* This function gets the error message that will be shown in web interface. */ 
char *
EesGetWebErrorMessage (eesErrorType, eesLanguageType)
{
}

/******************************************************************************************************************/

/* $RCSfile$ */
