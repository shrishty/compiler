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
     WHILE = 265,
     DO = 266,
     ENDWHILE = 267,
     IF = 268,
     THEN = 269,
     ELSE = 270,
     ENDIF = 271,
     READ = 272,
     PRINT = 273,
     BOOLEAN = 274,
     WRITE = 275,
     RELOP = 276,
     BOOLOP = 277
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
#define WHILE 265
#define DO 266
#define ENDWHILE 267
#define IF 268
#define THEN 269
#define ELSE 270
#define ENDIF 271
#define READ 272
#define PRINT 273
#define BOOLEAN 274
#define WRITE 275
#define RELOP 276
#define BOOLOP 277




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


