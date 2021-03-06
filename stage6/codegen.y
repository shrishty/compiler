%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	void yyerror(char *);
	int yylex(void);
	//int sym[26];
	int temp;
	int regno;
	int lable, mem, *a;
	FILE *fp;
	struct Gsymbol {
		char name[25];
		int type;
		int size;
		int *binding;
		int bind;
		struct Gsymbol *next;
	};
	struct Gsymbol *table;
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
	struct node *makenode(int, char *, int, struct node*, struct node*, struct node*);
	struct node *update(struct node* a, struct node *l, struct node *m, struct node *r);
	int evaluate(struct node *x);
	int getreg();
	void freereg();	
	int codegen(struct node*x);
	int getlable();
	struct Gsymbol* find(char a[26]);
	void printtable();

%}

%token INTEGER VARIABLE EXIT NUM DEFINE
%token WHILE DO ENDWHILE IF THEN ELSE ENDIF READ PRINT
%right '=' PRINT WRITE
%left '+' '-'
%left '*' '/'
%left '<' '>' RELOP

%%
program: 	slist				{ $$ = makenode(5, "program", -1, $1, NULL, NULL);
								 print1($$); 
								 printf("\n"); evaluate($$); 
								 fp = fopen("output.txt", "w");
								 fprintf(fp, "START\n");
								 temp = codegen($$);
								 fprintf(fp, "HALT\n");}
			;

slist:
			slist statement	';'		{$$ = makenode(4, "slist", -1, $1, NULL, $2);}
			
			| statement ';'			{$$ = makenode(4, "statement", -1, $1, NULL, NULL);}
			;
			
statement:
			expr											{$$ = $1;}
			| DEFINE VARIABLE								{$$ = update($1, $2, NULL, NULL);}
			| DEFINE VARIABLE '[' NUM ']' 					{$$ = update($1, $2, NULL, $4);}							
			| VARIABLE '=' expr								{$$ = update($2, $1, NULL, $3);}
			| VARIABLE '[' expr ']' '=' expr				{$$ = update($5, $1, $3, $6);}
			| READ '(' VARIABLE ')'							{$$ = update($1, $3, NULL, NULL);}
			| WRITE	'(' statement ')'						{$$ = update($1, $3, NULL, NULL);}
			| WHILE '(' expr ')' DO slist ENDWHILE 			{$$ = update($1, $3, NULL, $6);}
			| IF '(' expr ')' THEN slist ELSE slist ENDIF 	{$$ = update($1, $3, $6, $8);}
			| EXIT											{$$ = update($1, NULL, NULL, NULL);}
			;		

expr:
			NUM						{$$ = $1;}
			| VARIABLE				{$$ = $1;}
			| VARIABLE '[' expr ']' {$$ = update($1, $3, NULL, NULL); }
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

void print1(struct node *x) {
	if(x != NULL) {
		if(x->node_type == 0)
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
		if(x -> node_type == 0)
			return x -> value;
		
		if(x -> node_type == 2) {
			int *b;
			struct Gsymbol *t = find(x -> name);
			if(x -> l != NULL) 
				b = t -> binding + evaluate(x -> l);
			else
				b = t -> binding;
			return *b;
		}
		
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
					int *b;
					struct Gsymbol *t = find(x -> l -> name);
					if(x -> m != NULL)
						b = t -> binding + evaluate(x -> m);
					else
						b = t -> binding;
					*b = evaluate(x -> r);
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
				struct Gsymbol *t = find(x -> l -> name);
				*t -> binding = temp; 
			}
			if(strcmp("define", x -> name) == 0) {
				struct Gsymbol *t = (struct Gsymbol*) malloc(sizeof(struct Gsymbol));
				strcpy(t -> name, x -> l -> name);
				if(x -> r != NULL) 
					t -> size = evaluate(x -> r);
				else
					t -> size = 1;
				a = (int *) malloc(t -> size * sizeof(int));
				t -> binding = a;
				t -> next = table;
				table = t;
			}
			if(strcmp("while", x->name) == 0) {
				while(evaluate(x->l) != 0) {
					printf("in while\n");
					evaluate(x -> r);
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

struct Gsymbol* find(char a[26]) {
	struct Gsymbol *head = (struct Gsymbol*) malloc(sizeof(struct Gsymbol));
	head = table;
	
	while(head != NULL && strcmp(a, head->name) != 0)
		head = head -> next;
	if(head == NULL) {
		printf("Please define the variable first!!");
		exit(EXIT_SUCCESS);
	}
	else
		return head;
}

void printtable() {
	struct Gsymbol *t;
	t = table;
				
	while(t != NULL) {
		printf("%s %d", t -> name, *t -> binding);
		t = t -> next;
	}
}

int getreg() {
	return regno++;
}

int getlable() {
	return lable++;
}

void freereg() {
	regno--;
}

int reqmemory(int size) {
	int p = mem;
	mem = mem + size;
	return p;
}

int codegen(struct node *x) {
	if (x != NULL) {
		int i, m, j, l1, l2, l3, k;
		if(x-> node_type == 0) {
			i = getreg();
			fprintf(fp, "MOV R%d, %d\n", i, x->value);
			//printf("MOV R%d, %d", i, x->value);
		}
		
		if(x -> node_type == 2) {
			i = getreg();
			struct Gsymbol *t;
			t = find(x -> name);
			if(x -> l != NULL) {
				m = t -> bind;
				fprintf(fp, "MOV R%d, %d\n", i, m);
				j = codegen(x -> l);
				fprintf(fp, "ADD R%d, R%d\n", j, i);
				fprintf(fp, "MOV R%d, [R%d]\n", i, j);
				freereg(); 
			}	
			else {
				m = t -> bind;
				fprintf(fp, "MOV R%d, [%d]\n", i, m); }
		}
		
		if(x -> node_type == 1) {
			if(strcmp("+", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "ADD R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("-", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "SUB R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("*", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "MUL R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("/", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "DIV R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp(">", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "GT R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("<", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "LT R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp(">=", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "GE R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("<=", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "LE R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("==", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "EQ R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("!=", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "NE R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("=", x -> name) == 0) {
				//i = codegen(x -> l);
				i = codegen(x -> r);
				struct Gsymbol *t = (struct Gsymbol*) malloc(sizeof(struct Gsymbol));
				t = find(x -> l -> name);
				if(x -> m != NULL){
					m = t -> bind;
					k = getreg();
					fprintf(fp, "MOV R%d, %d\n", k, m);
					j = codegen(x -> m);
					fprintf(fp, "ADD R%d, R%d\n", k , j);
					freereg();
					fprintf(fp, "MOV [R%d], R%d\n", k, i);
				}
				else {
					m = t -> bind;
					fprintf(fp, "MOV [%d], R%d\n", m, i);
				}
				freereg();
			}
		}
		
		if(x -> node_type == 3) {
			if(strcmp("write", x -> name) == 0) {
				i = codegen(x -> l);
				fprintf(fp, "OUT R%d\n", i);
				freereg();
			}
			if(strcmp("read", x -> name) == 0) {
				i = codegen(x -> l);
				fprintf(fp, "IN R%d\n", i);
			}
			if(strcmp("while", x -> name) == 0) {
				l1 = getlable();
				l2 = getlable();
				
				fprintf(fp, "L%d:\n", l1);
				
				i = codegen(x->l);
				fprintf(fp, "JZ R%d, L%d\n", i, l2);
				freereg();
				
				i = codegen(x->r);
				fprintf(fp, "JMP L%d\nL%d:\n", l1, l2);
			}
			if(strcmp("define", x -> name) == 0) {
				struct Gsymbol *t = (struct Gsymbol*) malloc(sizeof(struct Gsymbol));
				strcpy(t -> name, x -> l -> name);
				if(x -> r != NULL) 
					t -> size = x -> r -> value;
				else
					t -> size = 1;
				t -> bind = reqmemory(t -> size);
				t -> next = table;
				table = t;
			}
				
			if(strcmp("if", x -> name) == 0) {
				l1 = getlable();
				l2 = getlable();
				
				i = codegen(x -> l);
				fprintf(fp, "JZ R%d L%d\n", i, l1);
				i = codegen(x -> m);
				fprintf(fp, "JMP L%d\nL%d:\n", l2, l1);
				i = codegen(x -> r);
				fprintf(fp, "L%d:\n", l2);
			}
				
		}
				
		if(x -> node_type == 4) {
				if(strcmp("slist", x->name) == 0) {
					codegen(x -> l);
					codegen(x -> r);
				}
				if(strcmp("statement", x->name) == 0) 
					codegen(x -> l);
		}
		
		if(x -> node_type == 5) 
			codegen(x -> l);
	return i;
	}	
}	

	
			
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int main(void) {
	yyparse();
	return 0;
}


