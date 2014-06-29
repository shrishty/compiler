%{
	#include <stdlib.h>
	#include <string.h>
	void yyerror(char *);
	struct node {
		int type;            // Integer Boolean or Void
		int node_type;       // operators or Statement type eg. while etc
		char name[15];
		int value;
		struct node *arglist;
		struct node *l, *m, *r;
	};
	typedef struct node* tr;

	#define YYSTYPE tr
	#include "y.tab.h"
%}

%%

define		{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 3;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return DEFINE;			
			}

print		{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 3;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return PRINT;			
			}

exit		{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 3;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return EXIT;			
			}

write		{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 3;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return WRITE;			
			}

read		{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 3;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return READ;			
			}
do			{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 3;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return DO;			
			}

while		{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 3;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return WHILE;			
			}

endwhile	{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 3;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return ENDWHILE;			
			}

if			{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 3;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return IF;			
			}

then		{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 3;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return THEN;			
			}

else		{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 3;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return ELSE;			
			}

endif		{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 3;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return ENDIF;			
			}

[a-z]+		{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 2;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return VARIABLE;			
			}

[0-9]+		{	yylval = (tr) malloc(sizeof(struct node));
				yylval -> node_type = 0;
				yylval -> value = atoi(yytext);
				yylval -> l = yylval -> r = yylval -> m = NULL;
				return NUM;			
			}

[-+()=/*;\[\]] {
				yylval = (struct node*) malloc(sizeof(struct node));
				yylval -> node_type = 1;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = NULL;
				return *yytext;
			}

[<>]		{
				yylval = (struct node*) malloc(sizeof(struct node));
				yylval -> node_type = 1;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = NULL;
				return RELOP;		 	
			}

"=="		{
				yylval = (struct node*) malloc(sizeof(struct node));
				yylval -> node_type = 1;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = NULL;
				return RELOP;		 	
			}

"<="		{
				yylval = (struct node*) malloc(sizeof(struct node));
				yylval -> node_type = 1;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = NULL;
				return RELOP;		 	
			}

">="		{
				yylval = (struct node*) malloc(sizeof(struct node));
				yylval -> node_type = 1;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = NULL;
				return RELOP;		 	
			}

"!="		{
				yylval = (struct node*) malloc(sizeof(struct node));
				yylval -> node_type = 1;
				strcpy(yylval -> name, yytext);
				yylval -> l = yylval -> r = NULL;
				return RELOP;		 	
			}
[ \t\n]		;

.			yyerror("ERROR");

%%

int yywrap(void) {
	return 1;
}
