%{
#include <stdlib.h>
#include <string.h>
void yyerror(char *);
typedef char * a;
#define YYSTYPE a
#include "y.tab.h"
%}

%%

print   { return print; }
exit	{ return EXIT;}

[a-z]     {
		     yylval = (char *) malloc(sizeof(char));
             strcpy(yylval, yytext);
             return VARIABLE;
          }

[0-9]+    {
			 yylval = (char *) malloc(sizeof(char)); 
             strcpy(yylval, yytext);
             return INTEGER;
          }

[-+()=/*\%\n]    {
			 yylval = (char *) malloc(sizeof(char)); 
             strcpy(yylval, yytext);
             return *yytext;
          }

[ \t\n]      ;

.         yyerror("invalid character");

%%

int yywrap(void) {
  return 1;
}
