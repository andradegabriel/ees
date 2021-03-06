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

#include "Libraries/mlcgi.h"
#include "eesTypes.h"
#include "eesConst.h"
#include "eesErrors.h"
#include "eesConfig.h"
#include "eesFunctions.h"
#include "eesUserInterface.h"


/*
* eesCgishowRequestRegistrationForm.c
*
* Returned code:
* ML_CGI_OK - Function has been executed successfully.
*
* Description:
* Used to show the help information on the web interface. */ 

int main (int argc, char **argv)
{
  environmentType environment;
  char systemLanguage [SYSTEM_LANGUAGE_MAXIMUM_LENGTH + 1];
  unsigned returnCode;

  if (mlCgiInitialize (&environment))
    exit (ML_CGI_OK);

  if (environment == commandLine)
  {
    printf ("This program can only be executed in the web interface.\n");
    exit (AMBIENTE_EXECUCAO_INVALIDO);
  }

  mlCgiBeginHttpHeader ("text/html");
  mlCgiEndHttpHeader ();

  returnCode = mlCgiGetFormStringNoNewLines ("eesLanguage", systemLanguage, SYSTEM_LANGUAGE_MAXIMUM_LENGTH);
  if (returnCode != ML_CGI_OK)
  {
    printf ("Error obtaining the field value eesLanguage - Error #%i\n", returnCode);
    mlCgiFreeResources ();
    exit (ML_CGI_OK);
  }
  

  if(!strcmp(systemLangauge, "eesEnglish"))
  {
    printf("<html>");
    printf("  <head>"   );
    printf("    <title>");
    printf("      Educational Evaluation System");
    printf("    </title>");
    printf("  </head>");
    printf("  <body>");
    printf("    <div style=\"text-align: center; font-family: arial; color:#5FDF00; font-size: 30px;\">");
    printf("      Educational Evaluation System");
    printf("    </div>");
    printf("    <br>");
    printf("    <div style=\"text-align: center;\">");
    printf("      <img src=\"images/GreenLine.jpg\" alt=\"Green_Line\">");
    printf("    </div>");
    printf("    <br>");
    printf("    <br>");
    printf("    <br>");
    printf("    <table border = \"0\" align = \"center\">");
    printf("    </table>");
    printf("    <br>");
    printf("    <!-- Definition of some links -->");
    printf("    <table border="0" align=\"center\">");
    printf("    </table>");
    printf("    <br>");
    printf("    <br>");
    printf("    <br>");
    printf("    <br>");
    printf("    <div style=\"text-align: center;\">");
    printf("      <img src=\"images/GreenLine.jpg\" alt=\"Green_Line\">");
    printf("    </div>");
    printf("    <br>");
    printf("  </body>");
    printf("</html>");
  }
    
  // If the language is portuguese
  else
  {
    printf("<html>");
    printf("  <head>"   );
    printf("    <title>");
    printf("      Sistema de Avalia&ccedil;&atilde;o Educacional");
    printf("    </title>");
    printf("  </head>");
    printf("  <body>");
    printf("    <div align = \"right\">");
    printf("      <a href=\"index-br.html\"><img src=\"images/brazil_Flag.jpg\" alt=\"brazil_Flag\" width=\"45\" height=\"25\"></a>");
    printf("    </div>");
    printf("    <div style=\"text-align: center; font-family: arial; color:#5FDF00; font-size: 30px;\">");
    printf("      Sistema de Avalia&ccedil;&atilde;o Educacional");
    printf("    </div>");
    printf("    <br>");
    printf("    <div style=\"text-align: center;\">");
    printf("      <img src=\"images/GreenLine.jpg\" alt=\"Green_Line\">");
    printf("    </div>");
    printf("    <br>");
    printf("    <br>");
    printf("    <br>");
    printf("    <table border = \"0\" align = \"center\">");
    printf("    </table>");
    printf("    <br>");
    printf("    <!-- Definition of some links -->");
    printf("    <table border="0" align=\"center\">");
    printf("    </table>");
    printf("    <br>");
    printf("    <br>");
    printf("    <br>");
    printf("    <br>");
    printf("    <div style=\"text-align: center;\">");
    printf("      <img src=\"images/GreenLine.jpg\" alt=\"Green_Line\">");
    printf("    </div>");
    printf("    <br>");
    printf("  </body>");
    printf("</html>");
  }
  
  mlCgiFreeResources ();
  
  return ML_CGI_OK;
}

/* $RCSfile$ */
