%option yylineno

%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cbison.tab.h"

#include "lib/compiler_state.h"
#include "lib/scope.h"
#include "lib/error.h"

#include "lib/node/node.h"
#include "lib/node/node_tree.h"
#include "lib/node/node_type.h"

#include "lib/symbol/symbol.h"



//come from cbison.y
extern struct compiler_state my_state;

//come from lib/node/node_type.c
extern char *node_type_str[];


//----------------------------------------------------------------------------
extern void yyerror(const char *);  /* prints grammar violation message */

extern int sym_type(const char *);  /* returns type from symbol table */

#define sym_type(identifier) IDENTIFIER /* with no symbol table, fake it */

static void comment(void);
static int check_type(void);
//----------------------------------------------------------------------------


%}

%%
"/*"                                    { comment(); }
"//".*                                    { /* consume //-comment */ }

"auto"					{ return(AUTO); }
"break"					{ return(BREAK); }
"case"					{ return(CASE); }
"char"					{ return(CHAR); }
"const"					{ return(CONST); }
"continue"				{ return(CONTINUE); }
"default"				{ return(DEFAULT); }
"do"					{ return(DO); }
"double"				{ return(DOUBLE); }
"else"					{ return(ELSE); }
"enum"					{ return(ENUM); }
"extern"				{ return(EXTERN); }
"float"					{ return(FLOAT); }
"for"					{ return(FOR); }
"goto"					{ return(GOTO); }
"if"					{ return(IF); }
"inline"				{ return(INLINE); }
"int"					{ return(INT); }
"long"					{ return(LONG); }
"register"				{ return(REGISTER); }
"restrict"				{ return(RESTRICT); }
"return"				{ return(RETURN); }
"short"					{ return(SHORT); }
"signed"				{ return(SIGNED); }
"sizeof"				{ return(SIZEOF); }
"static"				{ return(STATIC); }
"struct"				{ return(STRUCT); }
"switch"				{ return(SWITCH); }
"typedef"				{ return(TYPEDEF); }
"union"					{ return(UNION); }
"unsigned"				{ return(UNSIGNED); }
"void"					{ return(VOID); }
"volatile"				{ return(VOLATILE); }
"while"					{ return(WHILE); }
"_Alignas"                              { return ALIGNAS; }
"_Alignof"                              { return ALIGNOF; }
"_Atomic"                               { return ATOMIC; }
"_Bool"                                 { return BOOL; }
"_Complex"                              { return COMPLEX; }
"_Generic"                              { return GENERIC; }
"_Imaginary"                            { return IMAGINARY; }
"_Noreturn"                             { return NORETURN; }
"_Static_assert"                        { return STATIC_ASSERT; }
"_Thread_local"                         { return THREAD_LOCAL; }
"__func__"                              { return FUNC_NAME; }

{L}{A}*					{
                                          printf("!!!%s\n", yytext);
                                          check_identifier();
				          //symbol_number++;
                                          //node_number++;
                                          return check_type(); 
					}

{HP}{H}+{IS}?				{  
                                          printf("!!!%s\n", yytext);
                                          check_i_constant(); 
                                          //symbol_number++;
                                          //node_number++;
                                          return I_CONSTANT; 
                                        }
{NZ}{D}*{IS}?				{ 
                                          printf("!!!%s\n", yytext);
                                          check_i_constant();
                                          //symbol_number++;
                                          //node_number++;
                                          return I_CONSTANT; 
                                        }
"0"{O}*{IS}?				{ 
                                          printf("!!!%s\n", yytext);
                                          check_i_constant();
                                          //symbol_number++;
                                          //node_number++;
                                          return I_CONSTANT; 
                                        }
{CP}?"'"([^'\\\n]|{ES})+"'"		{ 
                                          printf("!!!%s\n", yytext);
                                          check_i_constant();
                                          //symbol_number++;
                                          //node_number++;
                                          return I_CONSTANT; 
                                        }

{D}+{E}{FS}?				{ 
                                          printf("!!!%s\n", yytext);
                                          check_f_constant();
                                          //symbol_number++;
                                          //node_number++;
                                          return F_CONSTANT; 
                                        }
{D}*"."{D}+{E}?{FS}?			{ 
                                          printf("!!!%s\n", yytext);
                                          check_f_constant();
                                          //symbol_number++;
                                          //node_number++;
                                          return F_CONSTANT; 
                                        }
{D}+"."{E}?{FS}?			{ 
                                          printf("!!!%s\n", yytext);
                                          check_f_constant();
                                          //symbol_number++;
                                          //node_number++;
                                          return F_CONSTANT; 
                                        }
{HP}{H}+{P}{FS}?			{ 
                                          printf("!!!%s\n", yytext);
                                          check_f_constant();
                                          //symbol_number++;
                                          //node_number++;
                                          return F_CONSTANT; 
                                        }
{HP}{H}*"."{H}+{P}{FS}?			{ 
                                          printf("!!!%s\n", yytext);
                                          check_f_constant();
                                          //symbol_number++;
                                          //node_number++;
                                          return F_CONSTANT; 
                                        }
{HP}{H}+"."{P}{FS}?			{ 
                                          printf("!!!%s\n", yytext);
                                          check_f_constant();
                                          //symbol_number++;
                                          //node_number++;
                                          return F_CONSTANT; 
                                        }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+	{ 
                                          printf("!!!%s\n", yytext);
                                          check_string_literal();
                                          //symbol_number++;
                                          //node_number++;
                                          return STRING_LITERAL; 
                                        }

"..."					{ return ELLIPSIS; }
">>="					{ return RIGHT_ASSIGN; }
"<<="					{ return LEFT_ASSIGN; }
"+="					{ return ADD_ASSIGN; }
"-="					{ return SUB_ASSIGN; }
"*="					{ return MUL_ASSIGN; }
"/="					{ return DIV_ASSIGN; }
"%="					{ return MOD_ASSIGN; }
"&="					{ return AND_ASSIGN; }
"^="					{ return XOR_ASSIGN; }
"|="					{ return OR_ASSIGN; }
">>"					{ return RIGHT_OP; }
"<<"					{ return LEFT_OP; }
"++"					{ return INC_OP; }
"--"					{ return DEC_OP; }
"->"					{ return PTR_OP; }
"&&"					{ return AND_OP; }
"||"					{ return OR_OP; }
"<="					{ return LE_OP; }
">="					{ return GE_OP; }
"=="					{ return EQ_OP; }
"!="					{ return NE_OP; }
";"					{ return ';'; }
("{"|"<%")				{
                                          push_scope_stack();
                                          print_scope_stack();
                                         // print_scope_list();
 
                                          return '{'; 
                                        }
("}"|"%>")				{
                                          pop_scope_stack(); 
                                          print_scope_stack();
                                         // print_scope_list();
                                          return '}'; 
                                        }
","					{ return ','; }
":"					{ return ':'; }
"="					{ return '='; }
"("					{ return '('; }
")"					{ return ')'; }
("["|"<:")				{ return '['; }
("]"|":>")				{ return ']'; }
"."					{ return '.'; }
"&"					{ return '&'; }
"!"					{ return '!'; }
"~"					{ return '~'; }
"-"					{ return '-'; }
"+"					{ return '+'; }
"*"					{ return '*'; }
"/"					{ return '/'; }
"%"					{ return '%'; }
"<"					{ return '<'; }
">"					{ return '>'; }
"^"					{ return '^'; }
"|"					{ return '|'; }
"?"					{ return '?'; }

{WS}					{ /* whitespace separates tokens */ }
.					{ /* discard bad characters */printf("i don't know what it is\n"); }

%%

int yywrap(void)        /* called at end of input */
{
    return 1;           /* terminate now */
}

static void comment(void)
{
    int c;

    while ((c = input()) != 0)
        if (c == '*')
        {
            while ((c = input()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
    yyerror("unterminated comment");
}

int check_identifier()
{
//    printf("check_identifier start\n");
    //point to the null
    int symbol_index=my_state.symbol_number;
    int node_index  =my_state.node_number;

    //now my_state->symbol_number has been added 1
//    printf("add_symbol 0\n");
    add_symbol(yytext, yylineno, not_know_type);
//    printf("add_symbol 1\n");
    //printf("============%s\n", node_type_str[not_know_type]);
    
    //now my_state->node_number has been added 1
    printf("291:yylineno:%d\n", yylineno);
    //yylval.node=add_node(not_know_type);
    yylval.node=add_node(IDENTIFIER_type, yylineno);
//    printf("293:yylineno:%d\n", yylineno);

    yylval.node->node_symbol_index=symbol_index;
    
    //node_index++;
    //++my_state->node_number;    

    /*
    if(need_print==1)
    {
        print_symbol_table();
        print_node_table();
    }
    */
    printf("check_identifier end\n");
    return node_index;
}
int check_i_constant()
{
    int symbol_index=my_state.symbol_number;
    int node_index  =my_state.node_number;

    add_symbol(yytext, yylineno, I_CONSTANT_type);
    yylval.node=add_node(I_CONSTANT_type, yylineno);
    yylval.node->node_symbol_index=symbol_index;
    
    //node_index++;
    //++my_state->node_number;

    /*
    if(need_print==1)
    {
        print_symbol_table();
        print_node_table();
    }
    */
    return node_index;
}
int check_f_constant()
{
    int symbol_index=my_state.symbol_number; 
    int node_index  =my_state.node_number;

    add_symbol(yytext, yylineno, F_CONSTANT_type); //my_state.symbol_number will add 1
    yylval.node=add_node(F_CONSTANT_type, yylineno);
    yylval.node->node_symbol_index=symbol_index;  //symbol_index does not add 1
  
    //node_index++;
    //++my_state->node_number;

    /*
    if(need_print==1)
    {
        print_symbol_table();
        print_node_table();
    }
    */   
 
    return node_index;
}
int check_string_literal()
{
    int symbol_index=my_state.symbol_number;
    int node_index  =my_state.node_number;

    add_symbol(yytext, yylineno, STRING_LITERAL_type);
    yylval.node=add_node(STRING_LITERAL_type, yylineno);
    yylval.node->node_symbol_index=symbol_index;
 
    //node_index++;
    //++my_state->node_number;
    
    /*
    if(need_print==1)
    {
        print_symbol_table();
        print_node_table();
    }
    */
    return node_index;
}


static int check_type(void)
{
   //yylval 
   // switch (sym_type(yytext))
   // {
   // case TYPEDEF_NAME:                /* previously defined */
   //     return TYPEDEF_NAME;
   // case ENUMERATION_CONSTANT:        /* previously defined */
   //    return ENUMERATION_CONSTANT;
   // default:                          /* includes undefined */
   //     return IDENTIFIER;
   // }
    return IDENTIFIER;    
    

}




