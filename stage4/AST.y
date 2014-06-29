%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	void yyerror(char *);
	int yylex(void);
	int sym[26];
	int temp;
	int preveval;
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
	struct node *makenode(int node_type, char name[15], int value, struct node *l, struct node *m, struct node *r);
	struct node * update(struct node* a, struct node *l, struct node *m, struct node *r);
	int evaluate(struct node *x);	

%}

%token INTEGER VARIABLE EXIT NUM
%token WHILE DO ENDWHILE IF THEN ELSE ENDIF READ PRINT
%right '=' PRINT WRITE
%left '+' '-'
%left '*' '/'
%left '<' '>' RELOP

%%
program: 	slist				{ $$ = makenode(5, "program", -1, $1, NULL, NULL);
								 print1($$); 
								 printf("\n"); evaluate($$); }

slist:
			slist statement	';'		{$$ = makenode(4, "slist", -1, $1, NULL, $2);}
			
			| statement ';'			{$$ = makenode(4, "statement", -1, $1, NULL, NULL);}
			;
			
statement:
			expr											{$$ = $1;}
			| VARIABLE '=' expr								{$$ = update($2, $1, NULL, $3);}
			| READ '(' VARIABLE ')'							{$$ = update($1, $3, NULL, NULL);}
			| WRITE	'(' statement ')'						{$$ = update($1, $3, NULL, NULL);}
			| WHILE '(' expr ')' DO slist ENDWHILE 			{$$ = update($1, $3, NULL, $6);}
			| IF '(' expr ')' THEN slist ELSE slist ENDIF 	{$$ = update($1, $3, $6, $8);}
			| EXIT											{$$ = update($1, NULL, NULL, NULL);}
			;		

expr:
			NUM						{$$ = $1;}
			| VARIABLE				{$$ = $1;}
			| expr '+' expr			{$$ = update($2, $1, NULL, $3);}
			| expr '-' expr			{$$ = update($2, $1, NULL, $3);}
			| expr '*' expr			{$$ = update($2, $1, NULL, $3);}
			| expr '/' expr			{$$ = update($2, $1, NULL, $3);}
			| expr RELOP expr		{$$ = update($2, $1, NULL, $3);}
			| '(' expr ')'			{$$ = $2;}
			;
						
%%

struct node *makenode(int node_type, char name[15], int value, struct node *l, struct node *m, struct node *r)	
{
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	
	newnode -> node_type = node_type;
	strcpy(newnode -> name, name);
	newnode -> value = value;
	newnode -> l = l;
	newnode -> m = m;
	newnode -> r = r;
	
	return newnode;
}
	
struct node * update(struct node* a, struct node *l, struct node *m, struct node *r) {
	a -> l = l;
	a -> r = r;
	a -> m = m;
	
	return a;
}

int isRelop(char a[3]) {
	if(strcmp("<", a) == 0)
		return 1;
	if(strcmp("<=", a) == 0)
		return 1;
	if(strcmp(">", a) == 0)
		return 1;
	if(strcmp(">=", a) == 0)
		return 1;
	if(strcmp("==", a) == 0)
		return 1;
	if(strcmp("!=", a) == 0)
		return 1;
	return 0;
}

void print1(struct node *x) {
	if(x != NULL) {

		//printf("dgury%d\n", x->node_type);
		if(x->node_type == 0)
			printf("%d ", x->value);		
		else
			printf("%s ", x -> name);
		if(x -> node_type == 1) {
			if(isRelop(x->l->name)) {
				printf("Semantic Error\n");
				exit(EXIT_SUCCESS);
			}
			if(isRelop(x->r->name)) {
				printf("Semantic Error\n");
				exit(EXIT_SUCCESS);
			}			
		}		
		print1(x->l);
		print1(x -> m);
		print1(x->r);
	}
}

int evaluate(struct node *x) {
	if(x != NULL) {
		if(x -> node_type == 0)
			return x -> value;
		
		if(x -> node_type == 2)
			return sym[x->name[0] - 'a'];
		
		if(x -> node_type == 1) {
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
			if(strcmp("!=", x->name) == 0)
					return evaluate(x->l) != evaluate(x -> r);
			if(strcmp("=", x->name) == 0) {
					sym[x->l->name[0] - 'a'] = evaluate(x -> r);
					//printf("%c %d\n", x -> l -> name[0], evaluate(x -> r));
					}
					  
			}
			
		if(x -> node_type == 3) {
			if(strcmp("exit", x->name) == 0)
				exit(EXIT_SUCCESS);
			if(strcmp("write", x->name) == 0)
				printf("%d\n", evaluate(x -> l));
			if(strcmp("read", x->name) == 0) {
				printf("Enter a number: ");
				scanf("%d", &temp);
				sym[x -> l -> name[0] - 'a'] = temp; }
			if(strcmp("while", x->name) == 0) {
				while(evaluate(x->l) != 0) {
					printf("in while\n");
					evaluate(x -> r);
					//print1(x -> r);
					//printf("\n");
				}
			}
			if(strcmp("if", x->name) == 0) {
				if(evaluate(x -> l) != 0){
					printf("true\n");
					evaluate(x -> m);
				}
				else {
					printf("false\n");
					evaluate(x -> r);
				}
			}
		}
		
		if(x -> node_type == 4) {
			if(strcmp("slist", x->name) == 0) {
				evaluate(x -> l);
				evaluate(x -> r);
			}
			if(strcmp("statement", x->name) == 0)
				evaluate(x -> l);
		}
		
		if(x -> node_type == 5) 
			evaluate(x -> l);
	}
}
			
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int main(void) {
	yyparse();
	return 0;
}


