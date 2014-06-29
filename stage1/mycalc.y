%token INTEGER VARIABLE EXIT
%right print
%left '+' '-'
%left '*' '/' '%'

%{
  #include <stdio.h>
  #include <stdlib.h>
  void yyerror(char *);
  int yylex(void);
  int sym[26];
%}

%%

line:
        line statement '\n' {printf("\n");}
        |
	;

statement:
	expr			{printf("\n%d\n", $1); }
	| VARIABLE '=' expr     {sym[$1] = $3; }
	;

expr:
	INTEGER            	{printf("%d", $1);}
	| VARIABLE         	{$$ = sym[$1]; printf("%c", $1 + 'a');}
	| expr '+' expr    	{$$ = $1 + $3; printf("+");}
	| expr '-' expr    	{$$ = $1 - $3; printf("-");}
	| expr '*' expr    	{$$ = $1 * $3; printf("*");}
	| expr '/' expr    	{$$ = $1 / $3; printf("/");}
	| expr '%' expr		{$$ = $1 % $3; printf("mod");}
	| '(' expr ')'     	{$$ = $2; }
	| print expr		{printf("%d", $2);}
	| EXIT		        {exit(EXIT_SUCCESS);}
	;

%%

void yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
}

int main(void) {
  yyparse();
  return 0;
}
