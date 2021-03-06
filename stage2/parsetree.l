%{
	#include <stdlib.h>
	void yyerror(char *);
	struct node {
		int node_type;
		int val;
		char op;
		char var;
		struct node *l, *r;
	};
	typedef struct node* tr;
	#define YYSTYPE tr
	#include "y.tab.h"
%}

%%

print  	 	{ return print; }
exit		{ return EXIT;}
evaluate	{ return EVALUATE;}
read		{ return READ;}

[a-z] 	{
		yylval = (tr) malloc(sizeof(struct node));
		yylval -> node_type = 2;
		yylval -> var = *yytext;
		yylval -> l = yylval -> r = NULL;
		return VARIABLE;
	}

[0-9]+	{
		yylval = (struct node*) malloc(sizeof(struct node));
		yylval -> node_type = 1;
		yylval -> val = atoi(yytext);
		yylval -> l = yylval -> r = NULL;
		return INTEGER;
	}

[-+()=/*]  {
		yylval = (struct node*) malloc(sizeof(struct node));
		yylval -> node_type = 0;
		yylval -> op = *yytext;
		yylval -> l = yylval -> r = NULL;
		return *yytext;
	      }
[\n]		return '\n';

[ \t]	 	;

.		yyerror("Invalid Character");

%%

int yywrap(void) {
	return 1;
} 	
