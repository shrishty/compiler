%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	void yyerror(char *);
	int yylex(void);
	//int sym[26];
	int temp;
	int regno, count;
	int lable, *a, ty;
	int mem = 0;
	FILE *fp;
	
	struct argStruct {
		int type;
		char name[25];
		struct argStruct *next;
	};
	struct Gsymbol {
		char name[25];
		int type;               // type = 1 -> Integer, type = 2 -> boolean, type = 0 -> notype
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
		int *binding;
		int bind;
		struct argStruct *argList;
		struct node *l, *m, *r;
	};
	typedef struct node* tr;
	#define YYSTYPE tr
	extern FILE *yyin;
	void print1(struct node*);
	int evaluate(struct node *x);
	struct node *makenode(int, char *, int, struct node*, struct node*, struct node*);
	struct node *update(struct node* a, struct node *l, struct node *m, struct node *r, int);
	int evaluate(struct node *x);
	int getreg();
	void freereg();	
	int codegen(struct node*x);
	int getlable();
	struct Gsymbol* find(char a[26]);
	void printtable();
	void checkTypeError(struct node*, int a, int b, int c);
	void isError(int a, int b);
	void set_type(struct node *a);
	struct node* findnode(struct node* x, char a[20]);
	void addVariable(char a[25], int type, int size);
	void boolcheck(struct node *t);

%}

%token INTEGER VARIABLE EXIT NUM TYPE DECL ENDDECL
%token WHILE DO ENDWHILE IF THEN ELSE ENDIF READ PRINT BOOLEAN
%right '=' PRINT WRITE
%left '+' '-'
%left '*' '/'
%left RELOP
%left BOOLOP  

%%
program: 	declaration	slist				{ $$ = makenode(5, "program", 0, $2, NULL, NULL);
											  evaluate($$);
											  fp = fopen("output.txt", "w");
								 			  fprintf(fp, "%s\n", "START");
								 			  temp = codegen($$);
								 			  fprintf(fp, "%s\n", "HALT");
											}
			;

declaration: 
			DECL declist ENDDECL			{}
			;
			
declist:		
			decl ';'						{}
			| declist decl ';'				{}
			;
			
decl:		
			type varlist					{}
			;

type: 
			TYPE							{ty = $1 -> type;}
			;
			
varlist:	variable						{}
			| varlist ',' variable			{}
			;

variable:
			VARIABLE						{ addVariable($1->name, ty, 1); }
			| VARIABLE '[' NUM ']'			{ addVariable($1-> name, ty, $3->value);}	
			;
								
slist:
			slist statement	';'		{$$ = makenode(4, "slist", 0, $1, NULL, $2);}
			
			| statement ';'			{$$ = makenode(4, "statement", 0, $1, NULL, NULL);}
			;
			
statement:
			expr											{$$ = $1;}							
			| VARIABLE '=' expr								{ $$ = update($2, $1, NULL, $3, 0); 
															  set_type($1); boolcheck($2);}
			| VARIABLE '[' expr ']' '=' expr				{ $$ = update($5, $1, $3, $6, 0); 
															  isError($3 -> type, 1); 
															  set_type($1); boolcheck($5);}
			| READ '(' VARIABLE ')'							{$$ = update($1, $3, NULL, NULL, 0); set_type($3); isError($3 -> type, 1);}
			| READ '(' VARIABLE '[' expr ']' ')'			{$$ = update($1 , $3, $5, NULL, 0);  set_type($3);  isError($3 -> type, 1);}
 			| WRITE	'(' expr ')'							{$$ = update($1, $3, NULL, NULL, 0); isError($3 -> type, 1);}
			| WHILE '(' expr ')' DO slist ENDWHILE 			{$$ = update($1, $3, NULL, $6, 0); isError($3 -> type, 2);}
			| IF '(' expr ')' THEN slist ENDIF				{$$ = update($1, $3, $6, NULL, 0); isError($3 -> type, 2);}
			| IF '(' expr ')' THEN slist ELSE slist ENDIF 	{$$ = update($1, $3, $6, $8, 0); isError($3 -> type, 2);}
			| EXIT											{$$ = update($1, NULL, NULL, NULL, 0); }
			;		

expr:
			NUM						{$$ = $1; }
			| VARIABLE				{$$ = $1; set_type($1); }
			| VARIABLE '[' expr ']' {$$ = update($1, $3, NULL, NULL, $1 -> type); set_type($1); isError($3 -> type, 1);}
			| expr '+' expr			{$$ = update($2, $1, NULL, $3, 1); checkTypeError($2, 1, 1, 1);}
			| expr '-' expr			{$$ = update($2, $1, NULL, $3, 1); checkTypeError($2, 1, 1, 1);}
			| expr '*' expr			{$$ = update($2, $1, NULL, $3, 1); checkTypeError($2, 1, 1, 1);}
			| expr '/' expr			{$$ = update($2, $1, NULL, $3, 1); checkTypeError($2, 1, 1, 1);}
			| expr RELOP expr		{$$ = update($2, $1, NULL, $3, 2); checkTypeError($2, 2, 1, 1);}
			| expr BOOLOP expr		{$$ = update($2, $1, NULL, $3, 2); checkTypeError($2, 2, 2, 2);}
			| '(' expr ')'			{$$ = $2; }
			;
						
%%

void isError(int a, int b) {
	if(a != b) {
		printf("Type Error\nline: %d\n", count);
		exit(EXIT_SUCCESS);
	}
}		

void boolcheck(struct node *t) {
	if(t -> l -> type == 2) {
		if(t -> r -> value != 1) {
			if( t -> r -> value != 0) {
				printf("Type Error\nline: %d\n", count);
				exit(EXIT_SUCCESS);
			}
		}
		else {
			t -> r -> type = 2;
		}
	}	 
}

		
void checkTypeError(struct node* n, int a, int b, int c) {
	if(n == NULL){
		printf("Some error\nline: %d\n", count);
		exit(EXIT_SUCCESS);
	}
	else {
		if(n -> type != a){
			printf("Type Error\nline: %d\n", count);
			exit(EXIT_SUCCESS);
	    }
	   
		if(n -> l -> type != b){
			printf("Type Error\nline: %d\n", count);
			exit(EXIT_SUCCESS);
	    }
	    if(n -> r -> type != c){
			printf("Type Error\nline: %d\n", count);
			exit(EXIT_SUCCESS);
	    }
	}
}
	   

struct node* findnode(struct node* x, char a[20]) {
	  if(x != NULL) {
	  	printf("Working\n");
	  	if(strcmp(x->name, a))
	  		return x;
	  	findnode(x -> l, a);
	  	findnode(x -> r, a);
	  	findnode(x -> m, a);
	}
}

void addVariable(char a[25], int type, int size) {

	struct Gsymbol *head, *t;
	t = find(a);
	
	if(t == NULL) {
		head = table;
	
		t = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
		strcpy(t->name, a);
		t -> type = type;
		t -> size = size;
		t -> bind = mem;
		if(type == 1) 
			t -> binding = (int*)malloc(sizeof(int) * size);
		if(type == 2)
			t -> binding = (int*)malloc(sizeof(int) * size);
		mem = mem + size;
	
		if(head == NULL)
			table = t;
		else {	
			while(head -> next != NULL) 
				head = head -> next;
		
			head -> next = t;
		}
	}
	else 
		printf("Variable is already defined\n");
}		

void set_type(struct node *a) {
	if(a != NULL) {
		struct Gsymbol *t = find(a->name);
		a -> type = t -> type;
		a -> binding = t -> binding;
		a -> bind = t -> bind;
	}
}

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
	
struct node * update(struct node* a, struct node *l, struct node *m, struct node *r, int type) {
	a -> l = l;
	a -> r = r;
	a -> m = m;
	a -> type = type;
	return a;
}

void print1(struct node *x) {
	if(x != NULL) {
		if(x->node_type == 0)
			printf("%d %d\n", x->value, x -> type);
		else
			printf("%s %d\n", x -> name, x -> type);		
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
			//struct Gsymbol *t = find(x -> name);
			if(x -> l != NULL) 
				b = x -> binding + evaluate(x -> l);
			else
				b = x -> binding;
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
					//struct Gsymbol *t = find(x -> l -> name);
					if(x -> m != NULL)
						b = x -> l -> binding + evaluate(x -> m);
					else
						b = x -> l -> binding;
					*b = evaluate(x -> r);
				}
			}
			
		if(x -> node_type == 3) {
			if(strcmp("exit", x->name) == 0)
				exit(EXIT_SUCCESS);
			if(strcmp("write", x->name) == 0)
				printf("Write   %d\n", evaluate(x -> l));
			if(strcmp("read", x->name) == 0) {
				int *b;
				printf("Enter a number: ");
				scanf("%d", &temp);
				//struct Gsymbol *t = find(x -> l -> name);
				
				if(x -> m != NULL)
					b = x -> l -> binding + evaluate(x -> m);
				else
					b = x -> l -> binding;
				*b = temp; 
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
					if(x -> r != NULL) {
					printf("false\n");
					evaluate(x -> r);}
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
			//struct Gsymbol *t;
			//t = find(x -> name);
			if(x -> l != NULL) {
				m = x -> bind;
				fprintf(fp, "MOV R%d, %d\n", i, m);
				j = codegen(x -> l);
				fprintf(fp, "ADD R%d, R%d\n", j, i);
				fprintf(fp, "MOV R%d, [R%d]\n", i, j);
				freereg(); 
			}	
			else {
				m = x -> bind;
				fprintf(fp, "MOV R%d, [%d]\n", i, m);
		 	}
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
				//struct Gsymbol *t = (struct Gsymbol*) malloc(sizeof(struct Gsymbol));
				//t = find(x -> l -> name);
				if(x -> m != NULL){
					m = x -> l -> bind;
					k = getreg();
					fprintf(fp, "MOV R%d, %d\n", k, m);
					j = codegen(x -> m);
					fprintf(fp, "ADD R%d, R%d\n", k , j);
					freereg();
					fprintf(fp, "MOV [R%d], R%d\n", k, i);
					freereg();
				}
				else {
					m = x -> l -> bind;
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
				if(x -> m == NULL) {
					i = getreg();
					//struct Gsymbol *t = find(x -> l -> name);
					fprintf(fp, "MOV R%d, %d\n", i, x -> l-> bind);
					j = getreg();
					fprintf(fp, "IN R%d\n", j);
					fprintf(fp, "MOV [R%d], R%d\n", i, j);
					freereg();
					freereg();
				}
				else {
					i = getreg();
					//struct Gsymbol *t = find(x -> l -> name);
					fprintf(fp, "MOV R%d, %d\n", i, x -> l -> bind);
					j = codegen(x -> m);
					fprintf(fp, "ADD R%d, R%d\n", i, j);
					freereg();
					k = getreg();
					fprintf(fp, "IN R%d\n", k);
					fprintf(fp, "MOV [R%d], R%d\n", i, k);
					freereg();
					freereg();
				}	
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
				
			if(strcmp("if", x -> name) == 0) {
				l1 = getlable();
				l2 = getlable();
				
				i = codegen(x -> l);
				fprintf(fp, "JZ R%d L%d\n", i, l1);
				freereg();
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

int main(int argc, char *argv[]) {

	FILE *input;
	
	input = fopen(argv[1], "r");
	yyin = input;
	
	yyparse();
	return 0;
}


