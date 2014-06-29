%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	void yyerror(char *);
	int yylex(void);
	int sym[26];
	int temp;
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
	void print1(struct node*);
	int evaluate(struct node *x);
%}

%start line
%token INTEGER VARIABLE EXIT 
%token WHILE DO ENDWHILE IF THEN ELSE ENDIF READ 
%right '=' print WRITE
%left '+' '-'
%left '*' '/'
%left '<' '>' EQ LE GE

%%

program: line 											  { printf("%d", evaluate($1)); }

line: 
	line statement 			 							  {   $$ = (struct node *) malloc(sizeof(struct node));
															  $$ -> node_type = 5;
															  strcpy($$ -> name, "line");
															  $$ -> l = $1;
															  $$ -> r = $2;
															 // printf("%d ", evaluate($$));
														  }
	| statement
	;

statement:
	expr ';'		;
	| VARIABLE '=' expr ';'									{ sym[$1 -> name[0] - 'a'] = evaluate($3);
							  								  $$ = $2;
							  								  $$ -> l = $1;
							                                  $$ -> r = $3; }	
	
	| READ '(' VARIABLE ')' ';'  						   {  
																printf("Enter a number: ");
																scanf("%d", &temp);
																//printf("%c\n", $3 -> name[0]);
																sym[$3 -> name[0] - 'a'] = temp;
																$$ = $1;
																$$ -> l = $3;
							 								}
	| WRITE '(' expr ')' ';'								{  
																$$ = $1;
																$$ -> l = $3;
																printf("%d\n", evaluate($3));
						 									}
	| WRITE statement ';'								  	{		
																$$ = $1;
																$$ -> l = $2; 
																printf("%d\n", evaluate($2));
						 									}	
	| WHILE '(' expr ')' DO line ENDWHILE				{   // While
 																$$  = $1;
																$$ -> l = $3;
																$$ -> r = $6;
										  					}
	| IF expr THEN line ELSE line ENDIF  			{
													 			// if then else
													 			$$  = $1;
													 			$$ -> l = $2;
													 			$$ -> m = $4;
													 			$$ -> r = $6;
												 			}
	| print statement ';' 									{ 	print1($2);
																printf("\n"); }
	;

expr:
	INTEGER 		{$$ = $1;}
	| VARIABLE		{$$ = $1;}
	| expr '+' expr {
						$$ = $2; 
				 		$$ -> l = $1; 
						$$ -> r = $3;
					}
	| expr '-' expr {
						$$ = $2; 
				 		$$ -> l = $1; 
						$$ -> r = $3;
					}
	| expr '*' expr {
						$$ = $2; 
				 		$$ -> l = $1; 
						$$ -> r = $3;
					}
	
	| expr '/' expr {
						$$ = $2; 
				 		$$ -> l = $1; 
						$$ -> r = $3;
					}
	| '(' expr ')'	{ $$ = $2;}
	
	| expr '<' expr	{
						$$ = $2;
						$$ -> l = $1;
						$$ -> r = $3;
					}
	| expr '>' expr	{
						$$ = $2;
						$$ -> l = $1;
						$$ -> r = $3;
					}

	| expr EQ expr	{
						$$ = $2;
						$$ -> l = $1;
						$$ -> r = $3;
					}
	| expr LE expr	{
						$$ = $2;
						$$ -> l = $1;
						$$ -> r = $3;
					}
	| expr GE expr	{
						$$ = $2;
						$$ -> l = $1;
						$$ -> r = $3;
					}
	
	| EXIT		  {exit(EXIT_SUCCESS);}

	;	

%%

void yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
}

void print1(struct node *x) {
	if(x != NULL) {

		//printf("dgury%d\n", x->node_type);
		if(x->node_type == 1)
			printf("%d ", x->value);
		else
			printf("%s ", x -> name);		
		print1(x->l);
		print1(x -> m);
		print1(x->r);
	}
}

int evaluate(struct node *x) {
	if(x != NULL) {
		if(x -> node_type == 0) {
				if(strcmp("+", x->name) == 0)	
					return evaluate(x->l) + evaluate(x -> r);
				if(strcmp("-", x->name) == 0)
					return evaluate(x->l) - evaluate(x -> r);
				if(strcmp("*", x->name) == 0)
					return evaluate(x->l) * evaluate(x -> r); 
				if(strcmp("/", x->name) == 0)
					return evaluate(x->l) / evaluate(x -> r);
				if(strcmp(">", x->name) == 0)
					return evaluate(x->l) > evaluate(x -> r);
				if(strcmp("<", x->name) == 0)
					return evaluate(x->l) < evaluate(x -> r);
				if(strcmp("<=", x->name) == 0)
					return evaluate(x->l) <= evaluate(x -> r);
				if(strcmp(">=", x->name) == 0)
					return evaluate(x->l) >= evaluate(x -> r);
				if(strcmp("==", x->name) == 0)
					return evaluate(x->l) == evaluate(x -> r);
				if(strcmp("=", x->name) == 0) {
					sym[x->l->name[0] - 'a'] = evaluate(x -> r);}  

		}
		if(x -> node_type == 1)
			return x -> value;
		if(x -> node_type == 2) 
			return sym[x -> name[0] - 'a'];
		if(x -> node_type == 3) {
			if(strcmp("while", x->name) == 0) {
				while(evaluate(x->l) == 1) {
					printf("la\n");
					evaluate(x->r);
				}
			}
			if(strcmp("if", x->name) == 0)
				if(evaluate(x->l) == 1) {
					printf("true\n");
					return evaluate(x->m); }
				else {
					printf("false\n");
					return evaluate(x->r); }
			if(strcmp("write", x->name) == 0)
				printf("%d", evaluate(x -> l));
		}
		if(x -> node_type == 5) {
			return evaluate(x -> r);
		}
	}
}
	
	
int main(void) {
  yyparse();
  return 0;
}
