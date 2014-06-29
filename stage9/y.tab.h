/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     VARIABLE = 259,
     EXIT = 260,
     NUM = 261,
     TYPE = 262,
     DECL = 263,
     ENDDECL = 264,
     LDECL = 265,
     ENDLDECL = 266,
     RETURN = 267,
     INT = 268,
     MAIN = 269,
     WHILE = 270,
     DO = 271,
     ENDWHILE = 272,
     IF = 273,
     THEN = 274,
     ELSE = 275,
     ENDIF = 276,
     READ = 277,
     PRINT = 278,
     BOOLEAN = 279,
     FIRST = 280,
     SECOND = 281,
     WRITE = 282,
     MOD = 283,
     RELOP = 284,
     BOOLOP = 285
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define VARIABLE 259
#define EXIT 260
#define NUM 261
#define TYPE 262
#define DECL 263
#define ENDDECL 264
#define LDECL 265
#define ENDLDECL 266
#define RETURN 267
#define INT 268
#define MAIN 269
#define WHILE 270
#define DO 271
#define ENDWHILE 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define READ 277
#define PRINT 278
#define BOOLEAN 279
#define FIRST 280
#define SECOND 281
#define WRITE 282
#define MOD 283
#define RELOP 284
#define BOOLOP 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


