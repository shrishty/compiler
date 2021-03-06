%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	void yyerror(char *);
	int yylex(void);
	//int sym[26];
	int temp, pushcount;
	int regno, count;
	int lable, *a, ty;
	int mem = 0;
	int memL, lcount;
	FILE *fp;
	
	struct argStruct {
		int type;
		char name[25];
		struct argStruct *next;
	};
	
	struct argStruct *arguments;
	struct Gsymbol {
		char name[25];
		int type;               // type = 1 -> Integer, type = 2 -> boolean, type = 0 -> notype
		int size;
		int *binding;
		int bind;
		struct argStruct *argList;
		struct Gsymbol *next;
	};
	struct Gsymbol *table;
	
	struct Lsymbol {
		char name[25];
		int type;
		int bind;
		struct Lsymbol *next;
	};
	struct Lsymbol *Ltable;
	 
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
	struct node *function, *currFunc;
	
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
	void addFunction(char a[25], int type, struct node *l);
	void makeArgList(struct node *a, struct node *b);
	void addType(int type, struct node *t);
	void pushRegisters(int);
	void addToLocalList(struct node *t, int type);
	void addArgListToLtable(struct node *function, struct node *list);
	void pushArguments(struct node* t);
	void popArguments(struct node* t) ;
	void push();
	void popRegisters(int);
	struct Lsymbol * findInLtable(char a[25]);
	void call(char a[30]);
	void pushLocalDecl(int);
	void popLocalDecl(int);
	void fCheckTypeError(struct node *t);
	struct node* makelist(struct node* a, struct node* b);
	struct node* setparametertypes(struct node *t);
	
%}

%token INTEGER VARIABLE EXIT NUM TYPE DECL ENDDECL LDECL ENDLDECL RETURN INT MAIN
%token WHILE DO ENDWHILE IF THEN ELSE ENDIF READ PRINT BOOLEAN FIRST SECOND
%right '=' PRINT WRITE
%left '+' '-'
%left '*' '/' MOD
%left RELOP
%left BOOLOP  

%%
program: 	declaration	fdeflist Mainblock	{ 
												$$ = makenode(5, "program", 0, $2, NULL, NULL);
											 	//print1($$);
											 	// evaluate($$);
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
			|'(' TYPE ',' TYPE ')'			{ty = $2 -> type * 100 + $4 -> type;}
			;
			
varlist:	variable						{}
			| varlist ',' variable			{}
			;

variable:
			VARIABLE						{ 
												if(ty >= 100)
													addVariable($1->name, ty, 2);
												else
													addVariable($1->name, ty, 1);
											}
			| VARIABLE '[' NUM ']'			{ addVariable($1-> name, ty, $3->value);}
			| funcname '(' ArgList ')'		{ addFunction(function -> name, function -> type, $3);}									
			;

funcname: VARIABLE							{$1 -> type = ty; function = $1; }
			;

ArgList:									{$$ = NULL;}
			| ArgDecl						{$$ = $1;}
			| ArgList ';' ArgDecl			{makeArgList($1, $3); $$ = $1;}
			;
	
ArgDecl:	ArgType ArgVarList				{$$ = $2;}
			;
	
ArgType:	TYPE							{ty = $1 -> type;}
			;
	
ArgVarList:	ArgVar							{$$ = $1;}
			| ArgVarList ',' ArgVar			{makeArgList($1, $3); $$ = $1;}
			;
	
ArgVar: 	VARIABLE						{addType(ty, $1); $$ = $1;}
			| '&' VARIABLE					{addType(ty + 10, $2); $$ = $2; }
			;

fdeflist:	fdef							{}
			| fdeflist fdef					{}
			;

fdef:		type fID '(' ArgDefList ')''{' LDECL ldeclist ENDLDECL body '}' {	
																				regno = 0; 
																				/*struct Lsymbol *t = Ltable;
																				while(t != NULL) {
																					printf("%s %d %d\n",t -> name, t->type, t->bind);
																					t = t -> next;
																				}*/
																				fprintf(fp, "PUSH BP\n");
																				fprintf(fp, "MOV BP, SP\n");
																				pushLocalDecl(lcount);
																				codegen($10);
																				popLocalDecl(lcount);
																				fprintf(fp, "POP BP\n");
																				fprintf(fp, "RET\n");
																				lcount = 0;
																				Ltable = NULL;
																			 }
			;
	
fID:		VARIABLE						{	memL = 1;
												struct Gsymbol *t = find($1 -> name);
												if(t == NULL)
													printf("function not defined %d\n", count); 
												$1 -> type = ty; 
												function = $1; 
												$$ = $1;
												fprintf(fp, "%s:\n", $1 -> name);
												//printf("%s\n", $1->name);
											}
			;

ArgDefList: ArgList							{addArgListToLtable(function, $1);}
			;
ldeclist:		
			ldecl ';'						{}
			| ldeclist ldecl ';'			{}
			;

ldecl:		type lvarlist 	 				{ty = $1 -> type; }
			;
			
lvarlist:	lvar							{}
			| lvarlist ',' lvar				{}
			;

lvar: 		VARIABLE						{ 
												addToLocalList($1, ty); lcount++;
												if(ty >= 100)
													lcount++; 
											}
			;	

	
body:		slist retstmt					{$$ = makenode(6, "FuncBody", 0, $1, NULL, $2); }
			|retstmt						{$$ = makenode(6, "FuncBody", 0, $1, NULL, NULL); }
			;
	
retstmt: 	RETURN expr ';'					{
												$$ = makenode(6, "return", 0, $2, NULL, NULL);
												if(strcmp(function -> name, "main") != 0) {
											 		struct Gsymbol *t = find(function -> name);	
											 		//printf("type %d %d\n", t -> type, $2 -> type);
											 		if($2 -> type%10 != t -> type%10) {
											 			printf("Type Error \n Line no. : %d\n", count);
											 			exit(EXIT_SUCCESS);
											 		}
											 	}
											} 
			;	
			
Mainblock:	type main '(' ')' '{' LDECL ldeclist ENDLDECL body '}' 	{ 
																		pushLocalDecl(lcount);
																		//print1($9);
																		codegen($9);
																		popLocalDecl(lcount);
																		fprintf(fp, "%s\n", "HALT");
																		Ltable = NULL; 
																		lcount = 0;
																	}

main:		MAIN													{
																		memL = 1;
																		regno = 1;
																		fprintf(fp, "%s\n", "START");
																		fprintf(fp, "MOV BP, %d\n", mem);
																		fprintf(fp, "MOV SP, BP\n");
																		strcpy(function -> name, "main");
																		function -> type = 1;
																	}
								
slist:
			slist statement	';'		{$$ = makenode(4, "slist", 0, $1, NULL, $2);}
			
			| statement ';'			{$$ = makenode(4, "statement", 0, $1, NULL, NULL);}
			;
			
statement:
			VARIABLE '=' expr								{ $$ = update($2, $1, NULL, $3, 0); 
															  set_type($1); boolcheck($2); }
			| VARIABLE '[' expr ']' '=' expr				{ 
																$$ = update($5, $1, $3, $6, 0); 
															  	isError($3 -> type, 1); 
															  	set_type($1); boolcheck($5);
															}
			| FIRST '(' VARIABLE ')' '=' expr				{	
																set_type($3);
																$1 = update($1, $3, NULL, NULL, $3->type/100);
																$$ = update($5, $1, NULL, $6, 0);
															}
			| SECOND '(' VARIABLE ')' '=' expr				{
																set_type($3);
																$1 = update($1, $3, NULL, NULL, $3 -> type/100);
																$$ = update($5, $1, NULL, $6, 0);
															}
			| READ '(' VARIABLE ')'							{$$ = update($1, $3, NULL, NULL, 0); set_type($3); isError($3 -> type, 1);} 
			| READ '(' VARIABLE '[' expr ']' ')'			{$$ = update($1 , $3, $5, NULL, 0);  set_type($3);  isError($3 -> type, 1);}
 			| WRITE	'(' expr ')'							{$$ = update($1, $3, NULL, NULL, 0); isError($3 -> type, 1);}
			| WHILE '(' expr ')' DO slist ENDWHILE 			{$$ = update($1, $3, NULL, $6, 0); isError($3 -> type, 2);}
			| IF '(' expr ')' THEN slist ENDIF				{$$ = update($1, $3, $6, NULL, 0); isError($3 -> type, 2);}
			| IF '(' expr ')' THEN slist ELSE slist ENDIF 	{$$ = update($1, $3, $6, $8, 0); isError($3 -> type, 2);}
			| EXIT											{$$ = update($1, NULL, NULL, NULL, 0); }
			;		

expr:
			NUM									{$$ = $1; }
			| VARIABLE							{$$ = $1; set_type($1);}
			| VARIABLE '[' expr ']' 			{$$ = update($1, $3, NULL, NULL, $1 -> type); set_type($1); isError($3 -> type, 1);}
			| VARIABLE '(' parameterList ')'	{
													struct Gsymbol *g = find($1 -> name);
													arguments = g -> argList;
													while(arguments) {
														printf("%s %d\n", arguments -> name, arguments -> type);
														arguments = arguments -> next;
													}
													arguments = g -> argList;
													$3 = setparametertypes($3);
													arguments = g -> argList;
													fCheckTypeError($3);	
													$1 -> node_type = 7;
													struct node *a = (struct node *) malloc(sizeof(struct node*));
													strcpy(a -> name, "call");
													a -> node_type = 7; 
													$$ = update($1, $3, a, NULL, $1 -> type); set_type($1);
												}
			| FIRST '(' VARIABLE ')'			{
													set_type($3); 
													$$ = update($1, $3, NULL, NULL, $3 -> type/100); 
												}
			| SECOND '(' VARIABLE ')'			{	
													set_type($3);
													$$ = update($1, $3, NULL, NULL, $3 -> type%100);
												}
 			| expr '+' expr						{$$ = update($2, $1, NULL, $3, 1); checkTypeError($2, 1, 1, 1);}
			| expr '-' expr						{$$ = update($2, $1, NULL, $3, 1); checkTypeError($2, 1, 1, 1);}
			| expr '*' expr						{$$ = update($2, $1, NULL, $3, 1); checkTypeError($2, 1, 1, 1);}
			| expr '/' expr						{$$ = update($2, $1, NULL, $3, 1); checkTypeError($2, 1, 1, 1);}
			| expr MOD expr						{$$ = update($2, $1, NULL, $3, 1); checkTypeError($2, 1, 1, 1);}
			| expr RELOP expr					{$$ = update($2, $1, NULL, $3, 2); checkTypeError($2, 2, 1, 1);}
			| expr BOOLOP expr					{$$ = update($2, $1, NULL, $3, 2); checkTypeError($2, 2, 2, 2);}
			| '(' expr ')'						{$$ = $2; }
			;

parameterList: 	expr						{$$ = $1;}
				| parameterList ','	expr	{$$ = makelist($1, $3);}
				;
				
%%

struct node* setparametertypes(struct node *t) {
	struct node *top;
	top = t;
	while(top) {
		printf("%s \n", top ->name);
		addType(arguments -> type, top);
		arguments = arguments -> next;
		top = top -> next;
	}
	return t;
}	
	
struct node* makelist(struct node* a, struct node* b) {
	b -> next = a;
	return b;
}

int codegen(struct node *x) {
	if (x != NULL) {
		int i, m, j, l1, l2, l3, k;
		i = 0;
		
		if(x-> node_type == 0) {      						// INTEGER Value
			i = getreg();
			fprintf(fp, "MOV R%d, %d\n", i, x->value);
			//printf("MOV R%d, %d", i, x->value);
		}	
		
		if(x -> node_type == 2) {     						// Variable  
			i = getreg();
			struct Lsymbol *t;
			t = findInLtable(x -> name);
			//printf("name %s bind %d type %d\n", x->name, x->bind, x->type);	
			if(x -> type >= 100) {
				i = getreg();
				fprintf(fp, "MOV R%d, %d\n", i, x->bind);
				j = getreg();
				fprintf(fp, "MOV R%d, BP\n", j);
				fprintf(fp, "ADD R%d, R%d\n", i, j);
				freereg();
				fprintf(fp, "MOV R%d, [R%d]\n", i, i);
				j = getreg();
				fprintf(fp, "MOV R%d, %d\n", j, x->bind+1);
				k = getreg();
				fprintf(fp, "MOV R%d, BP\n", k);
				fprintf(fp, "ADD R%d, R%d\n", j, k);
				freereg();
				fprintf(fp, "MOV R%d, [R%d]\n", j, j);
				i = j;
			}
			else	
			if(x -> l != NULL) {
				m = x -> bind;
				fprintf(fp, "MOV R%d, %d\n", i, m);
				j = codegen(x -> l);
				fprintf(fp, "ADD R%d, R%d\n", j, i);
				fprintf(fp, "MOV R%d, [R%d]\n", i, j);
				freereg(); 
			}	
			else {
				if(t != NULL) {
					if(t -> type >= 10) {
						//printf("variable\n");
						fprintf(fp, "MOV R%d, %d\n", i, x->bind);
						j = getreg();
						fprintf(fp, "MOV R%d, BP\n", j);
						fprintf(fp, "ADD R%d, R%d\n", i, j);
						fprintf(fp, "MOV R%d, [R%d]\n", i, i);
						fprintf(fp, "MOV R%d, [R%d]\n", i, i);
						freereg();
					}
					else {
						fprintf(fp, "MOV R%d, %d\n", i, t -> bind);
						j = getreg();
						fprintf(fp, "MOV R%d, BP\n", j);
						fprintf(fp, "ADD R%d, R%d\n", i, j);
						freereg();
						fprintf(fp, "MOV R%d, [R%d]\n", i, i);
					}
				}
				else {
					m = x -> bind;
					fprintf(fp, "MOV R%d, [%d]\n", i, m);
				}
		 	}
		}
		
		if(x -> node_type == 1) {					// operators
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
			if(strcmp("mod", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "MOD R%d, R%d\n", i, j);
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
				i = codegen(x -> r);
				struct Lsymbol *t;
				t = findInLtable(x -> l -> name);
				if(strcmp(x->l->name, "first") == 0) {
					t = findInLtable(x -> l -> l -> name);
					j = getreg();
					fprintf(fp, "MOV R%d, %d\n", j, t -> bind);
					k = getreg();
					fprintf(fp, "MOV R%d, BP\n", k);
					fprintf(fp, "ADD R%d, R%d\n", j, k);
					freereg();
					fprintf(fp, "MOV [R%d], R%d\n", j, i);
					freereg();
				}
				else
				if(strcmp(x->l->name, "second") == 0) {
					t = findInLtable(x -> l -> l -> name);
					j = getreg();
					fprintf(fp, "MOV R%d, %d\n", j, t -> bind + 1);
					k = getreg();
					fprintf(fp, "MOV R%d, BP\n", k);
					fprintf(fp, "ADD R%d, R%d\n", j, k);
					freereg();
					fprintf(fp, "MOV [R%d], R%d\n", j, i);
					freereg();
				}
				else
				if(x -> l -> type >= 100) {
					t = findInLtable(x -> l -> name);
					if(t != NULL) {
						j = getreg();
						fprintf(fp, "MOV R%d, %d\n", j, t -> bind);
						k = getreg();
						fprintf(fp, "MOV R%d, BP\n", k);
						fprintf(fp, "ADD R%d, R%d\n", j, k);
						freereg();
						fprintf(fp, "MOV [R%d], R%d\n", j, i-1);
						freereg();
						
						j = getreg();
						fprintf(fp, "MOV R%d, %d\n", j, t -> bind + 1);
						k = getreg();
						fprintf(fp, "MOV R%d, BP\n", k);
						fprintf(fp, "ADD R%d, R%d\n", j, k);
						freereg();
						fprintf(fp, "MOV [R%d], R%d\n", j, i);
						freereg();
					}
				}else	
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
					if(t != NULL) {
						if(t -> type >= 10) {
							j = getreg();
							fprintf(fp, "MOV R%d, %d\n", j, x->l->bind);
							k = getreg();
							fprintf(fp, "MOV R%d, BP\n", k);
							fprintf(fp, "ADD R%d, R%d\n", j, k);
							fprintf(fp, "MOV R%d, [R%d]\n", j, j);
							freereg();
							fprintf(fp, "MOV [R%d], R%d\n", j, i);
							freereg();
						}
						else {
							j = getreg();
							fprintf(fp, "MOV R%d, %d\n", j, m);
							k = getreg();
							fprintf(fp, "MOV R%d, BP\n", k);
							fprintf(fp, "ADD R%d, R%d\n", j, k);
							freereg();
							fprintf(fp, "MOV [R%d], R%d\n", j, i);
							freereg();
						}
					}
					else {
						fprintf(fp, "MOV [%d], R%d\n", m, i);
					}
				}	
				freereg();
			}	
		}
		
		if(x -> node_type == 3) {					// Reserved words
			
			if(strcmp("first", x -> name) == 0) {
				struct Lsymbol *t = findInLtable(x -> l -> name);
				if(t != NULL) {
					i = getreg();
					fprintf(fp, "MOV R%d %d\n", i, t -> bind);
					j = getreg();
					fprintf(fp, "MOV R%d BP\n", j);
					fprintf(fp, "ADD R%d R%d\n", i, j);
					freereg();
					fprintf(fp, "MOV R%d, [R%d]\n", i, i);
				}
				else {
					struct Gsymbol *s = find(x -> l -> name);
					if(s != NULL) {
						i = getreg();
						fprintf(fp, "MOV R%d %d\n", i, s -> bind);
						fprintf(fp, "MOV R%d, [R%d]\n", i, i);
					}
				}
			}
			if(strcmp("second", x -> name) == 0) {
				struct Lsymbol *t = findInLtable(x -> l -> name);
				if(t != NULL) {
					i = getreg();
					fprintf(fp, "MOV R%d %d\n", i, t -> bind + 1);
					j = getreg();
					fprintf(fp, "MOV R%d BP\n", j);
					fprintf(fp, "ADD R%d R%d\n", i, j);
					freereg();
					fprintf(fp, "MOV R%d, [R%d]\n", i, i);
				}
				else {
					struct Gsymbol *s = find(x -> l -> name);
					if(s != NULL) {
						i = getreg();
						fprintf(fp, "MOV R%d %d\n", i, s -> bind + 1);
						fprintf(fp, "MOV R%d, [R%d]\n", i, i);
					}
				}
			}				
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
				
		if(x -> node_type == 4) {                     		// Statement and statement lists
				if(strcmp("slist", x->name) == 0) {
					codegen(x -> l);
					codegen(x -> r);
				}
				if(strcmp("statement", x->name) == 0) 
					codegen(x -> l);
		}
		
		if(x -> node_type == 5) 							// Program
			codegen(x -> l);
		
		if(x -> node_type == 6) {							// Function declaration		
			if(strcmp("FuncBody", x -> name) == 0) {
				codegen(x -> l);
				k = codegen(x -> r);
				i = getreg();
				fprintf(fp, "MOV R%d, %d\n", i, -2);
				j = getreg();
				fprintf(fp, "MOV R%d, BP\n", j);
				fprintf(fp, "ADD R%d, R%d\n", i, j);
				freereg();
				fprintf(fp, "MOV [R%d], R%d\n", i, k);
				if(function -> type >= 100) {
					i = getreg();
					fprintf(fp, "MOV R%d, %d\n", i, -3);
					j = getreg();
					fprintf(fp, "MOV R%d, BP\n", j);
					fprintf(fp, "ADD R%d, R%d\n", i, j);
					freereg();
					fprintf(fp, "MOV [R%d], R%d\n", i, k-1);
				}
				freereg();
			}
			if(strcmp("return", x -> name) == 0)
				i = codegen(x -> l);
		}
		
		if(x -> node_type == 7) {					// Function call
			
			if(function != NULL && strcmp(function -> name, "main") != 0) {
				struct Gsymbol *g = find(function -> name);
				if(g != NULL) 
					arguments = g -> argList;
			}
			else
				arguments = NULL;
			
			pushRegisters(regno - 1);
			pushcount = regno - 1;
			pushArguments(x -> l); 
			push(); 
			if(x -> type >= 100)
				push();
			call(x -> name);
			i = getreg();
			i = getreg();
			if(x -> type >= 100)
				i = getreg();
			//printf("PushCount: %d %d %d\n", pushcount, i, regno);	
			fprintf(fp, "POP R%d\n", i);
			if(x -> type >= 100)
				fprintf(fp, "POP R%d\n", i - 1);
			popArguments(x -> l);
			popRegisters(pushcount);
		}			
	return i;
	}	
}	

void fCheckTypeError(struct node *t) {
	if(t != NULL) {
		if(t -> node_type == 0 || t -> node_type == 2) {
			if(t -> type%10 == arguments -> type%10) {
				arguments = arguments -> next;
				fCheckTypeError(t -> r);
				fCheckTypeError(t -> l);
			}
			else { 
				printf("Type Error\nLINE NO %d\n", count);
				exit(EXIT_SUCCESS);
			}	
		}
		if(t -> node_type == 4) {
			fCheckTypeError(t -> r);
			fCheckTypeError(t -> l);
		}
	}
}

void pushLocalDecl(int lct) {
	while(lct--) {
		fprintf(fp, "PUSH R0\n");
	}
}

void popLocalDecl(int lct) {
	while(lct--) {
		fprintf(fp, "POP R0\n");
	}
}	

void pushArguments(struct node* t) {
	int i, j, k;
	if(t != NULL) {
		pushArguments(t -> next);
		//if(arguments != NULL)
			//printf("arguments: %s %s %d %d\n", arguments -> name, function -> name, arguments -> type, t -> type);
		if(t -> type >= 10 && arguments != NULL && arguments -> type >= 10) {
			i = getreg();
			fprintf(fp, "MOV R%d, %d\n", i, t -> bind);
			j = getreg();
			fprintf(fp, "MOV R%d, BP\n", j);
			fprintf(fp, "ADD R%d, R%d\n", i, j);
			freereg();
			fprintf(fp, "MOV R%d, [R%d]\n", i, i);
		}
		else if(t -> type >= 10) {
			i = getreg();
			fprintf(fp,"MOV R%d, %d\n", i, t->bind);
			j = getreg();
			fprintf(fp, "MOV R%d, BP\n", j);
			fprintf(fp, "ADD R%d, R%d\n", i, j);
			freereg();
		}
		else
			i = codegen(t);
		if(arguments != NULL)
			arguments = arguments -> next;
		fprintf(fp, "PUSH R%d\n", i);
		freereg();
	}
}

void popArguments(struct node* x) {
	if(x != NULL) {
		fprintf(fp, "POP R0\n");
		popArguments(x->next);
	}
}

struct Lsymbol * findInLtable(char a[25]) {
	struct Lsymbol *t = Ltable;
	
	while(t != NULL) {
		//printf("TName: %s %s\n", t -> name, a);
		if(strcmp(a, t -> name) == 0)
			return t;
		t = t -> next;
	}
}				

void pushRegisters(int k) {
	int i, size;
	
	size = k;
	i = 0;
	
	while(i <= size) {
		fprintf(fp, "PUSH R%d\n", i);
		i = i + 1;
	}
}

void addToLocalList(struct node *t, int type) {
	struct Lsymbol *lt = (struct Lsymbol*) malloc(sizeof(struct Lsymbol));
	
	strcpy(lt -> name, t -> name);
	lt -> type = type;
	lt -> bind = memL;
	memL++;
	if(type >= 100)
		memL++;
	
	if(Ltable == NULL)
		Ltable = lt;
	else {
		lt -> next = Ltable;
		Ltable = lt;
	}
}

void addArgListToLtable(struct node *func, struct node *list) {
	struct Gsymbol *t = find(func -> name);
	//printf("%s\n", func -> name);
	struct argStruct *m = t -> argList;
	struct argStruct *treeList, *tmp;
	struct Lsymbol *lt;
	int l;
	
	if(func ->type >= 100)
		l = -4;
	else
		l = -3;
	
	while(list != NULL) {
		tmp = (struct argStruct*) malloc(sizeof(struct argStruct));
		strcpy(tmp -> name, list -> name);
		tmp -> type = list -> type;

		if(treeList == NULL)
			treeList = tmp;
		else {
			tmp -> next = treeList;
			treeList = tmp;
		}
		list = list -> l;
	}
	
	while(m != NULL) {
		//printf("%d %d\n", m -> type, treeList -> type);
		if(m -> type%10 == treeList -> type%10 && strcmp(m -> name, treeList -> name) == 0) {
			lt = (struct Lsymbol*) malloc(sizeof(struct Lsymbol));
			strcpy(lt -> name, m -> name);
			lt -> type = m -> type;
			lt -> bind = l;
			l--;
			if(Ltable == NULL)
				Ltable = lt;
			else {
				lt -> next = Ltable;
				Ltable = lt;
			}	
			m = m -> next;
			treeList = treeList -> next;
		}
		else { 
			printf("Type Error\n Line no: %d\n", count);
			exit(EXIT_SUCCESS);
		}
	}
}

void call(char a[30]) {
	fprintf(fp, "CALL %s\n", a);
}

void push() {
	fprintf(fp, "%s%d\n", "PUSH R", 0);
}
	
void popRegisters(int i) {
	while(i >= 0) 
		fprintf(fp, "POP R%d\n", i--);
}
	
void isError(int a, int b) {
	if(a%10 != b%10) {
		printf("Type Error\nline: %d\n", count);
		exit(EXIT_SUCCESS);
	}
}		

void boolcheck(struct node *t) {
	if(t -> l -> type%10 == 2) {
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
		if(n -> type%10 != a%10){
			printf("Type Error\nline: %d\n", count);
			exit(EXIT_SUCCESS);
	    }
	   
		if(n -> l -> type%10 != b%10){
			printf("Type Error\nline: %d\n", count);
			exit(EXIT_SUCCESS);
	    }
	    if(n -> r -> type%10 != c%10){
			printf("Type Error\nline: %d\n", count);
			exit(EXIT_SUCCESS);
	    }
	}
}
	   

struct node* findnode(struct node* x, char a[20]) {
	  if(x != NULL) {
	  	//printf("Working\n");
	  	if(strcmp(x->name, a))
	  		return x;
	  	findnode(x -> l, a);
	  	findnode(x -> r, a);
	  	findnode(x -> m, a);
	}
}

// Adding variable to Global Symbol table
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
		printf("Variable %s is already defined\n", a);
}		

// Adds fuction to the Global symbol table
void addFunction(char a[25], int type, struct node *l) {
	struct Gsymbol *head, *t;
	struct argStruct *argl, *tmp, *last;
	struct node* ptop;
	
	argl = NULL;
	ptop = l;
	while(ptop != NULL) {
		tmp = (struct argStruct*) malloc(sizeof(struct argStruct));
		strcpy(tmp->name, ptop -> name);
		tmp -> type = ptop -> type;
		
		if(argl == NULL) {
			argl = tmp;
		}
		else {
			tmp -> next = argl;
			argl = tmp;
		}
		ptop = ptop -> l;
	}
			
	
	t = find(a);
	
	if(t == NULL) {
		head = table;
		
		t = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
		strcpy(t->name, a);
		t -> type = type;
		t -> size = 0;
		t -> argList = argl;
		
		if(head == NULL)
			table = t;
		else {	
			while(head -> next != NULL) 
				head = head -> next;
		
			head -> next = t;
		}
	}
	else
		printf("ID already defined\n");
}

//
void makeArgList(struct node *a, struct node *b) {
	struct node *t;
	
	t = a;
	
	if(t == NULL)
		a = b;
	else {
		while(t -> l != NULL)
			t  = t -> l;
		t -> l = b;
	}
	
	t = a;
	
	/*while( t != NULL){
		printf("%s ", t -> name);
		t = t -> l;
	}
	printf("\n");*/
}
		
// adds type to argument-tree-list of function
void addType(int type, struct node *t) {
	t -> type = type;
}

void set_type(struct node *a) {

	if(a != NULL) {
	
		struct Lsymbol *q = findInLtable(a -> name);
		if(q != NULL) {
			a -> type = q -> type;
			a -> bind = q -> bind;
		}
		else {
			//printf("%s\n", a -> name);
			struct Gsymbol *t = find(a->name);
			a -> type = t -> type;
			a -> binding = t -> binding;
			a -> bind = t -> bind;
		}
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
			
		printf("%s\n", x -> name);
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
	//printf("regno %d\n", regno);
	return regno++;
}

int getlable() {
	return lable++;
}

void freereg() {
	if(regno > 0)
		regno--;
}
	
			
void yyerror(char *s) {
	fprintf(stderr, "%s %d\n", s, count);
}

int main(int argc, char *argv[]) {

	FILE *input;
	fp = fopen("output.txt", "w");
	input = fopen(argv[1], "r");
	yyin = input;
	
	yyparse();
	return 0;
}


