%{
	#include <stdlib.h>
	#include <string.h>
	void yyerror(char *);
	struct node {
		int type;            // Integer Boolean or Void
		int node_type;       // operators or Statement type eg. while etc
		char name[15];
		int value;
		int *binding;
		int bind;
		struct node *argList;
		struct node *l, *m, *r;
		struct node *next, *par;
	};
	typedef struct node* tr;

	#define YYSTYPE tr
	#include "y.tab.h"
	int count = 1;
	void init(int, int, char a[15], int);
%}

%%

ldecl		{ return LDECL; }

endldecl	{ return ENDLDECL; }

return 		{ return RETURN; }

int			{	
				init(1, 3, yytext, -1);
				return TYPE;			
			}
"&"			{ return '&';}
			
INT			{ return INT; }

main 		{ return MAIN; }

bool		{	
				init(2, 3, yytext, -1);
				return TYPE;			
			}
			
decl		{ return DECL;  }

enddecl		{ return ENDDECL;}

","			{ return ','; }

print		{	
				init(0, 3, yytext, -1);
				return PRINT;			
			}
first		{ 
				init(-1, 3, yytext, -1);				
				return FIRST; 
			}

second 		{ 
				init(-1, 3, yytext, -1);
				return SECOND; 
			}

exit		{	
				init(0, 3, yytext, -1);
				return EXIT;			
			}

write		{	
				init(0, 3, yytext, -1);				
				return WRITE;			
			}

read		{	
				init(0, 3, yytext, -1);
				return READ;			
			}
do			{	
				init(0, 3, yytext, -1);
				return DO;			
			}

while		{	
				init(0, 3, yytext, -1);
				return WHILE;			
			}

endwhile	{	
				init(0, 3, yytext, -1);
				return ENDWHILE;			
			}

if			{	
				init(0, 3, yytext, -1);
				return IF;			
			}

then		{
				init(0, 3, yytext, -1);
				return THEN;			
			}

else		{
				init(0, 3, yytext, -1);
				return ELSE;			
			}

endif		{
				init(0, 3, yytext, -1);
				return ENDIF;			
			}
mod			{
				init(1, 1, yytext, -1);
				return MOD;
			}

[a-z]+		{
				init(-1, 2, yytext, -1);
				return VARIABLE;			
			}

[0-9]+		{
				init(1, 0, yytext, atoi(yytext));
				return NUM;			
			}

[-+=/*] 	{
				init(1, 1, yytext, -1);
				return *yytext;
			}
[();\[\]]   {
				return *yytext;
            }
[<>]		{
				init(2, 1, yytext, -1);
				return RELOP;		 	
			}

"=="		{
				init(2, 1, yytext, -1);
				return RELOP;		 	
			}

"<="		{
				init(2, 1, yytext, -1);
				return RELOP;		 	
			}

">="		{
				init(2, 1, yytext, -1);
				return RELOP;		 	
			}

"!="		{
				init(2, 1, yytext, -1);
				return RELOP;		 	
			}
[\&\!\|]	{
				init(0, 1, yytext, -1);
				return BOOLOP;
			}
			
[{}]		{ return yytext[0]; }
[\n]		{count++;}	
[ \t]		;

.			yyerror("ERROR");

%%


void init(int type, int node_type, char name[15], int value) {
	yylval = (struct node*) malloc(sizeof(struct node));
	yylval -> type = type;
	yylval -> node_type = node_type;
	strcpy(yylval -> name, name);
	yylval -> value = value;
	yylval -> l = NULL;
	yylval -> r = NULL;
	yylval -> m = NULL;
	//yylval -> argList = NULL;
}
	
int yywrap(void) {
	return 1;
}
