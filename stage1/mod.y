%token INTEGER VARIABLE EXIT READ
%right print EVALUATE
%left '+' '-'
%left '*' '/' '%'

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  void yyerror(char *);
  int yylex(void);
  char* conc(char*, char*, char*);
  int sym[26];
  typedef char *a;
  #define YYSTYPE a
%}

%%

line:
        line statement '\n' {printf("\n");}
        |
	;

statement:
	expr			{printf("%s\n", $1);}
	;

expr:
	INTEGER            	{strcpy($$, $1);}
	| VARIABLE			{strcpy($$, $1);}
	| expr '+' expr    	{strcpy($$, conc($2, $1, $3));}
	| expr '-' expr    	{strcpy($$, conc($2, $1, $3));}
	| expr '*' expr    	{strcpy($$, conc($2, $1, $3));}
	| expr '/' expr    	{strcpy($$, conc($2, $1, $3));}
	| expr '%' expr		{strcpy($$, conc($2, $1, $3));}
	| '(' expr ')'     	{strcpy($$, $2);}
	| print expr		{printf("%s", $2);}
	| EXIT		        {exit(EXIT_SUCCESS);}
	;

%%

char* conc(char *a, char *b, char *c) {
	strcat(a, b);
	strcat(a, c);
	return a;
}

void yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
}

int main(void) {
  yyparse();
  return 0;
}
