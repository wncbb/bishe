%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "lib/compiler_state.h"
#include "lib/scope.h"
#include "lib/error.h"

#include "lib/node/node.h"
#include "lib/node/node_tree.h"
#include "lib/node/node_type.h"

#include "lib/symbol/symbol.h"
#include "lib/symbol/smbl_function_definition.h"
#include "lib/symbol/deal_instruction.h"

//#include "lib/semantic/declaration_specifiers.h"

#define YYERROR_VERBOSE


//#include "analysis.h"

//come from lib/node/node_type.c
extern char *node_type_str[];

//come from clex.l
extern int yylineno;


struct compiler_state my_state;

/*
// coming from analysis.c start
extern struct storage_class_specifier_infor* storage_class_specifier_table[];
extern int    storage_class_specifier_num;
extern struct type_specifier_infor* type_specifier_table[];
extern int    type_specifier_num;
extern struct type_qualifier_infor* type_qualifier_table[];
extern int    type_qualifier_num;
extern struct function_specifier_infor* function_specifier_table[];
extern int    function_specifier_num;
extern struct alignment_specifier_infor* alignment_specifier_table[];
extern int    alignment_specifier_num;

extern struct declaration_specifiers_infor* declaration_specifiers_table[];
extern int    declaration_specifiers_num;

extern struct function_definition_infor* function_definition_table[];
extern int    function_definition_num;
// coming from analysis.c end
*/


//int dot_fd;

//struct node_my * translation_unit_table[65536];
//int translation_unit_number=0;

//struct node_my * external_declaration_table[65536];
//int external_declaration_number=0;

%}

%union{
    struct node_my *node;
}

%token	IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL FUNC_NAME SIZEOF
%token	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	XOR_ASSIGN OR_ASSIGN
%token	TYPEDEF_NAME ENUMERATION_CONSTANT

%token	TYPEDEF EXTERN STATIC AUTO REGISTER INLINE
%token	CONST RESTRICT VOLATILE
%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	COMPLEX IMAGINARY 
%token	STRUCT UNION ENUM ELLIPSIS

%token	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token	ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

%type <node> IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL TYPEDEF_NAME ENUMERATION_CONSTANT

%type <node> primary_expression constant enumeration_constant string generic_selection
%type <node> generic_association postfix_expression argument_expression_list unary_expression unary_operator
%type <node> cast_expression multiplicative_expression additive_expression shift_expression relational_expression
%type <node> equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression
%type <node> logical_or_expression conditional_expression assignment_expression assignment_operator expression
%type <node> constant_expression declaration declaration_specifiers init_declarator_list init_declarator
%type <node> storage_class_specifier type_specifier struct_or_union_specifier struct_or_union struct_declaration_list
%type <node> struct_declaration specifier_qualifier_list struct_declarator_list struct_declarator enum_specifier
%type <node> enumerator_list enumerator atomic_type_specifier type_qualifier function_specifier
%type <node> alignment_specifier declarator direct_declarator pointer type_qualifier_list
%type <node> parameter_type_list parameter_list parameter_declaration identifier_list type_name
%type <node> abstract_declarator direct_abstract_declarator initializer initializer_list designation
%type <node> designator_list designator static_assert_declaration statement labeled_statement
%type <node> compound_statement block_item_list block_item expression_statement selection_statement
%type <node> iteration_statement jump_statement translation_unit external_declaration function_definition
%type <node> declaration_list

%type <node> generic_assoc_list


%start translation_unit
%%

primary_expression
	: IDENTIFIER              {
                                    $$=make_parent(primary_expression_type, $1, 0, yylineno);
                                    printf("primary_expression: IDENTIFIER\n");
                                  }
	| constant                {
                                    $$=make_parent(primary_expression_type, $1, 1, yylineno);
                                    printf("primary_expression: constant\n");
                                  }
	| string                  {
                                    $$=make_parent(primary_expression_type, $1, 2, yylineno);
                                    printf("primary_expression: string\n");
                                  }
	| '(' expression ')'      {
                                    $$=make_parent(primary_expression_type, $2, 3, yylineno);
                                    printf("primary_expression: '(' expression ')'\n");
                                  }
	| generic_selection       {
                                    $$=make_parent(primary_expression_type, $1, 4, yylineno);
                                    printf("primary_expression: generic_selection\n");
                                  }
	;

constant
	: I_CONSTANT	           {
                                     $$=make_parent(constant_type, $1, 0, yylineno);
                                     printf("constant: I_CONSTANT\n");
                                   }	/* includes character_constant */
	| F_CONSTANT               {
                                     $$=make_parent(constant_type, $1, 1, yylineno);
                                     printf("constant: F_CONSTANT\n");
                                   }
	| ENUMERATION_CONSTANT	   {
                                     $$=make_parent(constant_type, $1, 2, yylineno);
                                     printf("constant: ENUMERATION_CONSTANT\n");
                                   }/* after it has been defined as such */
	;

enumeration_constant		/* before it has been defined as such */
	: IDENTIFIER               {
                                     $$=make_parent(enumeration_constant_type, $1, 0, yylineno); 
                                     printf("enumeration_constant: IDENTIFIER\n");
                                   }
	;

string
	: STRING_LITERAL      {
                                $$=make_parent(string_type, $1, 0, yylineno);
                                printf("string: STRING_LITERAL\n");
                              }
	| FUNC_NAME           {
                                $$=make_parent(string_type, 0x00, 1, yylineno);
                                printf("string: FUNC_NAME\n");
                              }
	;

generic_selection
	: GENERIC '(' assignment_expression ',' generic_assoc_list ')'  {
                                                                          $$=make_parent(generic_selection_type, $3, 0, yylineno);
                                                                          make_brother($3, $5);
                                
                                                                          printf("generic_selection: GENERIC '(' assignment_expression ',' generic_assoc_list ')'\n");
                                                                        }
	;

generic_assoc_list
	: generic_association                            {
                                                           $$=make_parent(generic_assoc_list_type, $1, 0, yylineno);
                                                           printf("generic_assoc_list: generic_association\n");
                                                         }
	| generic_assoc_list ',' generic_association     {
                                                           add_child($1, $3);
                                                           $$=$1;
                                                           printf("generic_assoc_list: generic_assoc_list ',' generic_association\n");
                                                         }
	;

generic_association
	: type_name ':' assignment_expression    {
                                                   $$=make_parent(generic_association_type, $1, 0, yylineno);
                                                   make_brother($1, $3);
                                                   printf("generic_association: type_name ':' assignment_expression\n");
                                                 }
	| DEFAULT ':' assignment_expression      {
                                                   $$=make_parent(generic_association_type, $3, 1, yylineno);
                                                   printf("generic_association: DEFAULT ':' assignment_expression\n");
                                                 }
	;

postfix_expression
	: primary_expression                                   {
                                                                 $$=make_parent(postfix_expression_type, $1, 0, yylineno);
                                                                 printf("postfix_expression: primary_expression\n");
                                                               }
	| postfix_expression '[' expression ']'                {
                                                                 $$=make_parent(postfix_expression_type, $1, 1, yylineno);
                                                                 make_brother($1, $3);
                                                                 printf("postfix_expression: postfix_expression '[' expression ']'\n");
                                                               }
	| postfix_expression '(' ')'                           {
                                                                 $$=make_parent(postfix_expression_type, $1, 2, yylineno);
                                                                 printf("postfix_expression: postfix_expression '(' ')'\n");
                                                               }
	| postfix_expression '(' argument_expression_list ')'  {
                                                                 $$=make_parent(postfix_expression_type, $1, 3, yylineno);
                                                                 make_brother($1, $3);
                                                                 printf("postfix_expression: postfix_expression '(' argument_expression_list')'\n");
                                                               }
	| postfix_expression '.' IDENTIFIER                    {
                                                                 $$=make_parent(postfix_expression_type, $1, 4, yylineno);
                                                                 make_brother($1, $3);
                                                                 printf("postfix_expression: postfix_expression '.' IDENTIFIER\n");
                                                               }
	| postfix_expression PTR_OP IDENTIFIER                 {
                                                                 $$=make_parent(postfix_expression_type, $1, 5, yylineno);
                                                                 make_brother($1, $3);
                                                                 printf("postfix_expression: postfix_expression PTR_OP IDENTIFIER\n");
                                                               }
	| postfix_expression INC_OP                            {
                                                                 $$=make_parent(postfix_expression_type, $1, 6, yylineno);
                                                                 printf("postfix_expression: postfix_expression INC_OP\n");
                                                               }
	| postfix_expression DEC_OP                            {
                                                                 $$=make_parent(postfix_expression_type, $1, 7, yylineno);
                                                                 printf("postfix_expression: postfix_expression DEC_OP\n");
                                                               }
	| '(' type_name ')' '{' initializer_list '}'           {
                                                                 $$=make_parent(postfix_expression_type, $2, 8, yylineno);
                                                                 make_brother($2, $5);
                                                                 printf("postfix_expression: '(' type_name ')' '{' initializer_list '}'\n");
                                                               }
	| '(' type_name ')' '{' initializer_list ',' '}'       {
                                                                 $$=make_parent(postfix_expression_type, $2, 9, yylineno);
                                                                 make_brother($2, $5);
                                                                 printf("postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'\n");
                                                               }
	;

argument_expression_list
	: assignment_expression                                          {
                                                                           $$=make_parent(argument_expression_list_type, $1, 0, yylineno);
                                                                           printf("argument_expression_list: assignment_expression\n");
                                                                         }
	| argument_expression_list ',' assignment_expression             {
                                                                           add_child($1, $3);
                                                                           $$=$1;
                                                                           printf("argument_expression_list: argument_expression_list ',' assignment_expression\n");
                                                                         }
	;

unary_expression
	: postfix_expression                  {
                                                $$=make_parent(unary_expression_type, $1, 0, yylineno);
                                                printf("unary_expression: postfix_expression\n");
                                              }
	| INC_OP unary_expression             {
                                                $$=make_parent(unary_expression_type, $2, 1, yylineno);
                                                printf("unary_expression: INC_OP unary_expression\n");
                                              }
	| DEC_OP unary_expression             {
                                                $$=make_parent(unary_expression_type, $2, 2, yylineno);
                                                printf("unary_expression: DEC_OP unary_expression\n");
                                              }
	| unary_operator cast_expression      {
                                                $$=make_parent(unary_expression_type, $1, 3, yylineno);
                                                make_brother($1, $2);
                                                printf("unary_expression: unary_operator cast_expression\n");
                                              }
	| SIZEOF unary_expression             {
                                                $$=make_parent(unary_expression_type, $2, 4, yylineno);
                                                printf("unary_expression: SIZEOF unary_expression\n");
                                              }
	| SIZEOF '(' type_name ')'            {
                                                $$=make_parent(unary_expression_type, $3, 5, yylineno);
                                                printf("unary_expression: SIZEOF '(' type_name ')'\n");
                                              }
	| ALIGNOF '(' type_name ')'           {
                                                $$=make_parent(unary_expression_type, $3, 6, yylineno);
                                                printf("unary_expression: ALIGNOF '(' type_name ')'\n");
                                              }
	;

unary_operator
	: '&'             {
                            $$=make_parent(unary_operator_type, 0x00, 0, yylineno);
                            printf("unary_operator: '&'\n");
                          }
	| '*'             {
                            $$=make_parent(unary_operator_type, 0x00, 1, yylineno);
                            printf("unary_operator: '*'\n");
                          }
	| '+'             {
                            $$=make_parent(unary_operator_type, 0x00, 2, yylineno);
                            printf("unary_operator: '+'\n");
                          }
	| '-'             {
                            $$=make_parent(unary_operator_type, 0x00, 3, yylineno);
                            printf("unary_operator: '-'\n");
                          }
	| '~'             {
                            $$=make_parent(unary_operator_type, 0x00, 4, yylineno);
                            printf("unary_operator: '~'\n");
                          }
	| '!'             {
                            $$=make_parent(unary_operator_type, 0x00, 5, yylineno);
                            printf("unary_operator: '!'\n");
                          }
	;

cast_expression
	: unary_expression                        {
                                                    $$=make_parent(cast_expression_type, $1, 0, yylineno);
                                                    printf("cast_expression: unary_expression\n");
                                                  }
	| '(' type_name ')' cast_expression       {
                                                    $$=make_parent(cast_expression_type, $2, 1, yylineno);
                                                    make_brother($2, $4);
                                                    printf("cast_expression: '(' type_name ')' cast_expression\n");
                                                  }
	;

multiplicative_expression
	: cast_expression                                      {
                                                                 $$=make_parent(multiplicative_expression_type, $1, 0, yylineno);
                                                                 printf("multiplicative_expression: cast_expression\n");
                                                               }
	| multiplicative_expression '*' cast_expression        {
                                                                 $$=make_parent(multiplicative_expression_type, $1, 1, yylineno);
                                                                 make_brother($1, $3);
                                                                 printf("multiplicative_expression: multiplicative_expression '*' cast_expression\n");
                                                               }
	| multiplicative_expression '/' cast_expression        {
                                                                 $$=make_parent(multiplicative_expression_type, $1, 2, yylineno);
                                                                 make_brother($1, $3);
                                                                 printf("multiplicative_expression: multiplicative_expression '/' cast_expression\n");
                                                               }
	| multiplicative_expression '%' cast_expression        {
                                                                 $$=make_parent(multiplicative_expression_type, $1, 3, yylineno);
                                                                 make_brother($1, $3);
                                                                 printf("multiplicative_expression: multiplicative_expression  mod  cast_expression\n");
                                                               }
	;

additive_expression
	: multiplicative_expression                          {
                                                               $$=make_parent(additive_expression_type, $1, 0, yylineno);
                                                               printf("additive_expression: multiplicative_expression\n");
                                                             }
	| additive_expression '+' multiplicative_expression  {
                                                               $$=make_parent(additive_expression_type, $1, 1, yylineno);
                                                               make_brother($1, $3);
                                                               printf("additive_expression: additive_expression '+' multiplicative_expression\n");
                                                             }
	| additive_expression '-' multiplicative_expression  {
                                                               $$=make_parent(additive_expression_type, $1, 2, yylineno);
                                                               make_brother($1, $3);
                                                               printf("additive_expression: additive_expression '-' multiplicative_expression\n");
                                                             }
	;

shift_expression
	: additive_expression                            {
                                                           $$=make_parent(shift_expression_type, $1, 0, yylineno);
                                                           printf("shift_expression: additive_expression\n");
                                                         }
	| shift_expression LEFT_OP additive_expression   {
                                                           $$=make_parent(shift_expression_type, $1, 1, yylineno);
                                                           make_brother($1, $3);      
                                                           printf("shift_expression: shift_expression LEFT_OP additive_expression\n");
                                                         }
	| shift_expression RIGHT_OP additive_expression  {
                                                           $$=make_parent(shift_expression_type, $1, 2, yylineno);
                                                           make_brother($1, $3);
                                                           printf("shift_expression: shift_expression RIGHT_OP additive_expression\n");
                                                         }
	;

relational_expression
	: shift_expression                             {
                                                         $$=make_parent(relational_expression_type, $1, 0, yylineno);
                                                         printf("relational_expression: shift_expression\n");
                                                       }
	| relational_expression '<' shift_expression   {
                                                         $$=make_parent(relational_expression_type, $1, 1, yylineno);
                                                         make_brother($1, $3);
                                                         printf("relational_expression: relational_expression '<' shift_expression\n");
                                                       }
	| relational_expression '>' shift_expression   {
                                                         $$=make_parent(relational_expression_type, $1, 2, yylineno);
                                                         make_brother($1, $3);
                                                         printf("relational_expression: relational_expression '>' shift_expression\n");
                                                       }
	| relational_expression LE_OP shift_expression {
                                                         $$=make_parent(relational_expression_type, $1, 3, yylineno);
                                                         make_brother($1, $3);
                                                         printf("relational_expression: relational_expression LE_OP shift_expression\n");
                                                       }
	| relational_expression GE_OP shift_expression {
                                                         $$=make_parent(relational_expression_type, $1, 4, yylineno);
                                                         make_brother($1, $3);
                                                         printf("relational_expression: relational_expression GE_OP shift_expression\n");
                                                       }
	;

equality_expression
	: relational_expression                            {
                                                             $$=make_parent(equality_expression_type, $1, 0, yylineno);
                                                             printf("equality_expression: relational_expression\n");
                                                           }
	| equality_expression EQ_OP relational_expression  {
                                                             $$=make_parent(equality_expression_type, $1, 1, yylineno);
                                                             make_brother($1, $3);
                                                             printf("equality_expression: equality_expression EQ_OP relational_expression\n");
                                                           }
	| equality_expression NE_OP relational_expression  {
                                                             $$=make_parent(equality_expression_type, $1, 2, yylineno);
                                                             make_brother($1, $3);
                                                             printf("equality_expression: equality_expression NE_OP relational_expression\n");
                                                           }
	;

and_expression
	: equality_expression                     {
                                                    $$=make_parent(and_expression_type, $1, 0, yylineno);
                                                    printf("and_expression: equality_expression\n");
                                                  }
	| and_expression '&' equality_expression  {
                                                    $$=make_parent(and_expression_type, $1, 1, yylineno);
                                                    make_brother($1, $3);
                                                    printf("and_expression: and_expression '&' equality_expression\n");
                                                  }
	;

exclusive_or_expression
	: and_expression                              {
                                                        $$=make_parent(exclusive_or_expression_type, $1, 0, yylineno);
                                                        printf("exclusive_or_expression: and_expression\n");
                                                      }
	| exclusive_or_expression '^' and_expression  {
                                                        $$=make_parent(exclusive_or_expression_type, $1, 1, yylineno);
                                                        make_brother($1, $3);
                                                        printf("exclusive_or_expression: exclusive_or_expression '^' and_expression\n");
                                                      }
	;

inclusive_or_expression
	: exclusive_or_expression                              {
                                                                 $$=make_parent(inclusive_or_expression_type, $1, 0, yylineno);
                                                                 printf("inclusive_or_expression: exclusive_or_expression\n");
                                                               }
	| inclusive_or_expression '|' exclusive_or_expression  {
                                                                 $$=make_parent(inclusive_or_expression_type, $1, 1, yylineno);  
                                                                 make_brother($1, $3);
                                                                 printf("inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression\n");
                                                               }
	;

logical_and_expression
	: inclusive_or_expression                               {
                                                                  $$=make_parent(logical_and_expression_type, $1, 0, yylineno);
                                                                  printf("logical_and_expression: inclusive_or_expression\n");
                                                                }
	| logical_and_expression AND_OP inclusive_or_expression { 
                                                                  $$=make_parent(logical_and_expression_type, $1, 1, yylineno);
                                                                  make_brother($1, $3);
                                                                  printf("logical_and_expression: logical_and_expression AND_OP inclusive_or_expression\n");
                                                                }
	;

logical_or_expression
	: logical_and_expression                                {
                                                                  $$=make_parent(logical_or_expression_type, $1, 0, yylineno);
                                                                  printf("logical_or_expression: logical_and_expression\n");
                                                                }
	| logical_or_expression OR_OP logical_and_expression    {
                                                                  $$=make_parent(logical_or_expression_type, $1, 1, yylineno);
                                                                  make_brother($1, $3);
                                                                  printf("logical_or_expression: logical_or_expression OR_OP logical_and_expression\n");
                                                                }
	;

conditional_expression
	: logical_or_expression                                           {
                                                                            $$=make_parent(conditional_expression_type, $1, 0, yylineno);
                                                                            printf("conditional_expression: logical_or_expression\n");
                                                                          }
	| logical_or_expression '?' expression ':' conditional_expression {
                                                                            $$=make_parent(conditional_expression_type, $1, 1, yylineno);
                                                                            make_brother($1, $3);
                                                                            make_brother($3, $5);
                                                                            
                                                                            printf("conditional_expression: logical_or_expression '?' expression ':' conditional_expression\n");
                                                                          }
	;

assignment_expression
	: conditional_expression                                      {
                                                                        $$=make_parent(assignment_expression_type, $1, 0, yylineno);
                                                                        printf("assignment_expression: conditional_expression\n");
                                                                      }
	| unary_expression assignment_operator assignment_expression  {
                                                                        $$=make_parent(assignment_expression_type, $1, 1, yylineno);
                                                                        make_brother($1, $2);
                                                                        make_brother($2, $3);
                                                                        printf("assignment_expression: unary_expression assignment_operator assignment_expression\n");
                                                                      }
	;

assignment_operator
	: '='             {
                            struct node_my *child_tmp=make_parent(EQU_ASSIGN_type, 0x00, -1, yylineno);
                            $$=make_parent(assignment_operator_type, child_tmp, 0, yylineno);
                            printf("assignment_operator: '='\n");
                          }
	| MUL_ASSIGN      {
                            struct node_my *child_tmp=make_parent(MUL_ASSIGN_type, 0x00, -1, yylineno);
                            $$=make_parent(assignment_operator_type, child_tmp, 1, yylineno);
                            printf("assignment_operator: MUL_ASSIGN\n");
                          }
	| DIV_ASSIGN      {
                            struct node_my *child_tmp=make_parent(DIV_ASSIGN_type, 0x00, -1, yylineno);
                            $$=make_parent(assignment_operator_type, child_tmp, 2, yylineno);
                            printf("assignment_operator: DIV_ASSIGN\n");
                          }            
	| MOD_ASSIGN      {
                            struct node_my *child_tmp=make_parent(MOD_ASSIGN_type, 0x00, -1, yylineno);
                            $$=make_parent(assignment_operator_type, child_tmp, 3, yylineno);
                            printf("assignment_operator: MOD_ASSIGN\n");
                          }
	| ADD_ASSIGN      {
                            struct node_my *child_tmp=make_parent(ADD_ASSIGN_type, 0x00, -1, yylineno);
                            $$=make_parent(assignment_operator_type, child_tmp, 4, yylineno);
                            printf("assignment_operator: ADD_ASSIGN\n");
                          }
	| SUB_ASSIGN      {
                            struct node_my *child_tmp=make_parent(SUB_ASSIGN_type, 0x00, -1, yylineno);
                            $$=make_parent(assignment_operator_type, child_tmp, 5, yylineno);
                            printf("assignment_operator: SUB_ASSIGN\n");
                          }
	| LEFT_ASSIGN     {
                            struct node_my *child_tmp=make_parent(LEFT_ASSIGN_type, 0x00, -1, yylineno);
                            $$=make_parent(assignment_operator_type, child_tmp, 6, yylineno);
                            printf("assignment_operator: LEFT_ASSIGN\n");
                          }
	| RIGHT_ASSIGN    {
                            struct node_my *child_tmp=make_parent(RIGHT_ASSIGN_type, 0x00, -1, yylineno);
                            $$=make_parent(assignment_operator_type, child_tmp, 7, yylineno);
                            printf("assignment_operator: RIGHT_ASSIGN\n");
                          }
	| AND_ASSIGN      {
                            struct node_my *child_tmp=make_parent(AND_ASSIGN_type, 0x00, -1, yylineno);
                            $$=make_parent(assignment_operator_type, child_tmp, 8, yylineno);
                            printf("assignment_operator: AND_ASSIGN\n");
                          }
	| XOR_ASSIGN      {
                            struct node_my *child_tmp=make_parent(XOR_ASSIGN_type, 0x00, -1, yylineno);
                            $$=make_parent(assignment_operator_type, child_tmp, 9, yylineno);
                            printf("assignment_operator: XOR_ASSIGN\n");
                          }
	| OR_ASSIGN       { 
                            struct node_my *child_tmp=make_parent(OR_ASSIGN_type, 0x00, -1, yylineno);
                            $$=make_parent(assignment_operator_type, child_tmp, 10, yylineno);
                            printf("assignment_operator: OR_ASSIGN\n");
                          }
	;

expression
	: assignment_expression                 {
                                                  $$=make_parent(expression_type, $1, 0, yylineno);
                                                  printf("expression: assignment_expression\n");
                                                }
	| expression ',' assignment_expression  {
                                                  add_child($1, $3);
                                                  $$=$1;
                                                  printf("expression: expression ',' assignment_expression\n");
                                                }
	;

constant_expression
	: conditional_expression	{
                                          $$=make_parent(constant_expression_type, $1, 0, yylineno);
                                          printf("constant_expression: conditional_expression\n");
                                        }/* with constraints */             
	;

declaration
	: declaration_specifiers ';'                       {
                                                             $$=make_parent(declaration_type, $1, 0, yylineno);
                                                             printf("declaration: declaration_specifiers ';'\n");
                                                           }
	| declaration_specifiers init_declarator_list ';'  {
                                                             //printf("557 line node_number: %d\n", node_number);
                                                             $$=make_parent(declaration_type, $1, 1, yylineno);
                                                             make_brother($1, $2);
                                                             /*
                                                             int typedef_node_index=return_index_from_tree_by_type($1, TYPEDEF_type);
                                                             if(typedef_node_index!=-1)
                                                             {
                                                                 int identifier_node_index=return_index_from_tree_by_type($2, not_know_type);
                                                                 if(identifier_node_index!=-1)
                                                                 {
                                                                     printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
                                                                     symbol_table[node_table[identifier_node_index]->node_symbol_index]->smbl_type=TYPEDEF_NAME_type;
                                                                 }
                                                             }
                                                             */
                                                             printf("declaration: declaration_specifiers init_declarator_list ';'\n");
                                                           }
	| static_assert_declaration                        {
                                                             $$=make_parent(declaration_type, $1, 2, yylineno);
                                                             printf("declaration: static_assert_declaration\n");
                                                           }
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers {
                                                           add_child_front($2, $1);
                                                           $$=$2;
                                                           //$$=make_parent(declaration_specifiers_type, node_number, $1, 0);
                                                           //make_brother($1, $2);
                                                           /*
                                                           if($1->node_inrule_num==0)
                                                           {
                                                               int identifier_index=return_index_from_tree_by_type($2, not_know_type);
                                                               if(identifier_index!=-1)
                                                               {
                                                                   symbol_table[node_table[identifier_index]->node_symbol_index]->smbl_type=TYPEDEF_NAME_type;
                                                               }
                                                           }
                                                           */
                                                           printf("declaration_specifiers: storage_class_specifier declaration_specifiers\n");
                                                         }
	| storage_class_specifier                        {
                                                           $$=make_parent(declaration_specifiers_type, $1, 1, yylineno);
                                                           printf("declaration_specifiers: storage_class_specifier\n");
                                                         }
	| type_specifier declaration_specifiers          {
                                                           add_child_front($2, $1);
                                                           $$=$2;
                                                           //$$=make_parent(declaration_specifiers_type, node_number, $1, 2);
                                                           //make_brother($1, $2);
                                                           
                                                           printf("declaration_specifiers: type_specifier declaration_specifiers\n");
                                                         }
	| type_specifier                                 {
                                                           $$=make_parent(declaration_specifiers_type, $1, 3, yylineno);
                                                           printf("declaration_specifiers: type_specifier\n");
                                                         }
	| type_qualifier declaration_specifiers          {
                                                           //$$=make_parent(declaration_specifiers_type, node_number, $1, 4);
                                                           //make_brother($1, $2);
                                                           add_child_front($2, $1);
                                                           $$=$2;
                                                           printf("declaration_specifiers: type_qualifier declaration_specifier\n");
                                                         }
	| type_qualifier                                 {
                                                           $$=make_parent(declaration_specifiers_type, $1, 5, yylineno);
                                                           printf("declaration_specifiers: type_qualifier\n");
                                                         }
	| function_specifier declaration_specifiers      {
                                                           //$$=make_parent(declaration_specifiers_type, node_number, $1, 6);
                                                           //make_brother($1, $2);
                                                           add_child_front($2, $1);
                                                           $$=$2;
                                                           printf("declaration_specifiers: function_specifier declaration_specifier\n");
                                                         }
	| function_specifier                             {
                                                           $$=make_parent(declaration_specifiers_type, $1, 7, yylineno);
                                                           printf("declaration_specifiers: function_specifier\n");
                                                         }
	| alignment_specifier declaration_specifiers     {
                                                           //$$=make_parent(declaration_specifiers_type, node_number, $1, 8);
                                                           //make_brother($1, $2);
                                                           add_child_front($2, $1);
                                                           $$=$2;
                                                           printf("declaration_specifiers: alignment_specifier declaration_specifiers\n");
                                                         }
	| alignment_specifier                            {
                                                           $$=make_parent(declaration_specifiers_type, $1, 9, yylineno);
                                                           printf("declaration_specifiers: alignemnt_specifier\n");
                                                         }
	;

init_declarator_list
	: init_declarator                           {
                                                      $$=make_parent(init_declarator_list_type, $1, 0, yylineno);
                                                      printf("init_declarator_list: init_declarator\n");
                                                    }
	| init_declarator_list ',' init_declarator  {
                                                      $$=$1;
                                                      add_child($1, $3);
                                                      printf("init_declarator_list: init_declarator_list ',' init_declarator\n");
                                                    }
	;

init_declarator
	: declarator '=' initializer     {
                                           $$=make_parent(init_declarator_type, $1, 0, yylineno);
                                           make_brother($1, $3);
                                           printf("init_declarator: declarator '=' initializer\n");
                                         }
	| declarator                     {
                                           $$=make_parent(init_declarator_type, $1, 1, yylineno);
                                           printf("init_declarator: declarator\n");
                                         }
	;

storage_class_specifier
	: TYPEDEF	 {
                           //struct node_my *child_tmp=make_parent(TYPEDEF_type, node_number, 0x00, -1);
                           $$=make_parent(storage_class_specifier_type, 0x00, 0, yylineno);
                           printf("storage_class_specifier: TYPEDEF\n");
                         }/* identifiers must be flagged as TYPEDEF_NAME */             
	| EXTERN         {
                           //struct node_my *child_tmp=make_parent(EXTERN_type, node_number, 0x00, -1);
                           $$=make_parent(storage_class_specifier_type, 0x00, 1, yylineno);
                           printf("storage_class_specifier: EXTERN\n");
                         }
	| STATIC         {
                           //struct node_my *child_tmp=make_parent(STATIC_type, node_number, 0x00, -1);
                           $$=make_parent(storage_class_specifier_type, 0x00, 2, yylineno);
                           printf("storage_class_specifier: STATIC\n");
                         }
	| THREAD_LOCAL   {
                           //struct node_my *child_tmp=make_parent(THREAD_LOCAL_type, node_number, 0x00, -1);
                           $$=make_parent(storage_class_specifier_type, 0x00, 3, yylineno);
                           printf("storage_class_specifier: THREAD_LOCAL\n");
                         }
	| AUTO           {
                           //struct node_my *child_tmp=make_parent(AUTO_type, node_number, 0x00, -1);
                           $$=make_parent(storage_class_specifier_type, 0x00, 4, yylineno);
                           printf("storage_class_specifier: AUTO\n");
                         }
	| REGISTER       {
                           //struct node_my *child_tmp=make_parent(REGISTER_type, node_number, 0x00, -1);
                           $$=make_parent(storage_class_specifier_type, 0x00, 5, yylineno);
                           printf("storage_class_specifier: REGISTER\n");
                         }
	;

type_specifier
	: VOID                       {
                                       //struct node_my *child_tmp=make_parent(VOID_type, node_number, 0x00, -1);
                                       $$=make_parent(type_specifier_type, 0x00, 0, yylineno);
                                       printf("type_specifier: VOID\n");
                                     }
	| CHAR                       {
                                       //struct node_my *child_tmp=make_parent(CHAR_type, node_number, 0x00, -1);
                                       $$=make_parent(type_specifier_type, 0x00, 1, yylineno);
                                       printf("type_specifier: CHAR\n");
                                     }
	| SHORT                      {
                                       //struct node_my *child_tmp=make_parent(SHORT_type, node_number, 0x00, -1);
                                       $$=make_parent(type_specifier_type, 0x00, 2, yylineno);
                                       printf("type_specifier: SHORT\n");
                                     }
	| INT                        {
                                       //struct node_my *child_tmp=make_parent(INT_type, node_number, 0x00, -1);
                                       $$=make_parent(type_specifier_type, 0x00, 3, yylineno);
                                       printf("type_specifier: INT\n");
                                     }
	| LONG                       {
                                       //struct node_my *child_tmp=make_parent(LONG_type, node_number, 0x00, -1);
                                       $$=make_parent(type_specifier_type, 0x00, 4, yylineno);
                                       printf("type_specifier: LONG\n");
                                     }
	| FLOAT                      {
                                       //struct node_my *child_tmp=make_parent(FLOAT_type, node_number, 0x00, -1);
                                       $$=make_parent(type_specifier_type, 0x00, 5, yylineno);
                                       printf("type_specifier: FLOAT\n");
                                     }
	| DOUBLE                     {
                                       //struct node_my *child_tmp=make_parent(DOUBLE_type, node_number, 0x00, -1);
                                       $$=make_parent(type_specifier_type, 0x00, 6, yylineno);
                                       printf("type_specifier: DOUBLE\n");
                                     }
	| SIGNED                     {
                                       //struct node_my *child_tmp=make_parent(SIGNED_type, node_number, 0x00, -1);
                                       $$=make_parent(type_specifier_type, 0x00, 7, yylineno);
                                       printf("type_specifier: SIGNED\n");
                                     }
	| UNSIGNED                   {
                                       //struct node_my *child_tmp=make_parent(UNSIGNED_type, node_number, 0x00, -1);
                                       $$=make_parent(type_specifier_type, 0x00, 8, yylineno);
                                       printf("type_specifier: UNSIGNED\n");
                                     }
	| BOOL                       {
                                       //struct node_my *child_tmp=make_parent(BOOL_type, node_number, 0x00, -1);
                                       printf("type_specifier: BOOL\n");
                                       $$=make_parent(type_specifier_type, 0x00, 9, yylineno);
                                     }
	| COMPLEX                    {
                                       //struct node_my *child_tmp=make_parent(COMPLEX_type, node_number, 0x00, -1);
                                       $$=make_parent(type_specifier_type, 0x00, 10, yylineno);
                                       printf("type_specifier: COMPLEX\n");
                                     }
	| IMAGINARY	  	     {
                                       //struct node_my *child_tmp=make_parent(IMAGINARY_type, node_number, 0x00, -1);
                                       $$=make_parent(type_specifier_type, 0x00, 11, yylineno);
                                       printf("type_specifier: IMAGINARY\n");
                                     }/* non-mandated extension */
	| atomic_type_specifier      {
                                       $$=make_parent(type_specifier_type, $1, 12, yylineno);
                                       printf("type_specifier: atomic_type_specifier\n");
                                     }
	| struct_or_union_specifier  {
                                       $$=make_parent(type_specifier_type, $1, 13, yylineno);
                                       printf("type_specifier: struc_or_union_specifer\n");
                                     }
	| enum_specifier             {
                                       $$=make_parent(type_specifier_type, $1, 14, yylineno);
                                       printf("type_specifier: enum_specifer\n");
                                     }
	| TYPEDEF_NAME		     {
                                       //struct node_my *child_tmp=make_parent(TYPEDEF_NAME_type, node_number, 0x00, -1);
                                       $$=make_parent(type_specifier_type, 0x00, 15, yylineno);
                                       printf("type_specifier: TYPEDEF_NAME\n");
                                     }/* after it has been defined as such */
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'             {
                                                                        $$=make_parent(struct_or_union_specifier_type, $1, 0, yylineno);
                                                                        make_brother($1, $3);
                                                                        printf("struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'\n");
                                                                      }
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}'  {
                                                                        $$=make_parent(struct_or_union_specifier_type, $1, 1, yylineno);
                                                                        make_brother($1, $2);
                                                                        make_brother($2, $4);
                                                                        printf("struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'\n");
                                                                      }
	| struct_or_union IDENTIFIER                                  {
                                                                        $$=make_parent(struct_or_union_specifier_type, $1, 2, yylineno);
                                                                        make_brother($1, $2);
                                                                        printf("struct_or_union_specifier: struct_or_union IDENTIFIER\n");
                                                                      }
	;

struct_or_union
	: STRUCT        {
                          //struct node_my *child_tmp=make_parent(STRUCT_type, node_number, 0x00, -1);
                          $$=make_parent(struct_or_union_type, 0x00, 0, yylineno);
                          printf("struct_or_union: STRUCT\n");
                        }
	| UNION         {
                          //struct node_my *child_tmp=make_parent(UNION_type, node_number, 0x00, -1);
                          $$=make_parent(struct_or_union_type, 0x00, 1, yylineno);
                          printf("struct_or_union: UNION\n");
                        }
	;

struct_declaration_list
	: struct_declaration                          {
                                                        $$=make_parent(struct_declaration_list_type, $1, 0, yylineno);
                                                        printf("struct_declaration_list: struct_declaration\n");
                                                      }
	| struct_declaration_list struct_declaration  {
                                                        add_child($1, $2);
                                                        $$=$1;
                                                        printf("struct_declaration_list: struct_declaration_list struct_declaration\n");
                                                      }
	;             

struct_declaration
	: specifier_qualifier_list ';'	                        {
                                                                  $$=make_parent(struct_declaration_type, $1, 0, yylineno);
                                                                  printf("struct_declaration: specifier_qualifier_list ';'\n");
                                                                }/* for anonymous struct/union */
	| specifier_qualifier_list struct_declarator_list ';'   {
                                                                  $$=make_parent(struct_declaration_type, $1, 1, yylineno);
                                                                  make_brother($1, $2);
                                                                  printf("struct_declaration: specifier_qualifier_list struct_declarator_list ';'\n");
                                                                }
	| static_assert_declaration                             {
                                                                  $$=make_parent(struct_declaration_type, $1, 2, yylineno);
                                                                  printf("struct_declaration: static_assert_declaration\n");
                                                                }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {
                                                    add_child_front($2, $1);
                                                    $$=$2;
                                                    printf("specifier_qualifier_list: type_specifier specifier_qualifier_list\n");
                                                  }
	| type_specifier                          {
                                                    $$=make_parent(specifier_qualifier_list_type, $1, 1, yylineno);
                                                    printf("specifier_qualifier_list: type_specifier\n");
                                                  }
	| type_qualifier specifier_qualifier_list {
                                                    add_child_front($2, $1);
                                                    $$=$2;
                                                    printf("specifier_qualifier_list: type_qualifier specifier_qualifier_list\n");
                                                  }
	| type_qualifier                          {
                                                    $$=make_parent(specifier_qualifier_list_type, $1, 3, yylineno);
                                                    printf("specifier_qualifier_list: type_qualifier\n");
                                                  }
	;

struct_declarator_list
	: struct_declarator                              {
                                                           $$=make_parent(struct_declarator_list_type, $1, 0, yylineno);
                                                           printf("struct_declarator_list: struct_declarator\n");
                                                         }
	| struct_declarator_list ',' struct_declarator   {
                                                           add_child($1, $3);
                                                           printf("struct_declarator_list: struct_declarator_list ',' struct_declarator\n");
                                                         }
	;

struct_declarator
	: ':' constant_expression             {
                                                $$=make_parent(struct_declarator_type, $2, 0, yylineno);
                                                printf("struct_declarator: ':' constant_expression\n");
                                              }
	| declarator ':' constant_expression  {
                                                $$=make_parent(struct_declarator_type, $1, 1, yylineno);
                                                make_brother($1, $3);
                                                printf("struct_declarator: declarator ':' constant_expression\n");
                                              }
	| declarator                          {
                                                $$=make_parent(struct_declarator_type, $1, 2, yylineno);
                                                printf("struct_declarator: declarator\n");
                                              }
	;

enum_specifier
	: ENUM '{' enumerator_list '}'                 {
                                                         $$=make_parent(enum_specifier_type, $3, 0, yylineno);
                                                         node_symbol_type_to_ENUMERATION_CONSTANT_type($3);
                                                         printf("enum_specifier: ENUM '{' enumerator_list '}'\n");
                                                       }
	| ENUM '{' enumerator_list ',' '}'             {
                                                         $$=make_parent(enum_specifier_type, $3, 1, yylineno);
                                                         node_symbol_type_to_ENUMERATION_CONSTANT_type($3);
                                                         printf("enum_specifier: ENUM '{' enumerator_list ',' '}'\n");
                                                       }
	| ENUM IDENTIFIER '{' enumerator_list '}'      {
                                                         $$=make_parent(enum_specifier_type, $2, 2, yylineno);
                                                         make_brother($2, $4);
                                                         node_symbol_type_to_ENUMERATION_CONSTANT_type($4);
                                                         node_symbol_type_to_enum_type($2);
                                                         printf("enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'\n");
                                                       }
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'  {
                                                         $$=make_parent(enum_specifier_type, $2, 3, yylineno);
                                                         make_brother($2, $4);
                                                         node_symbol_type_to_ENUMERATION_CONSTANT_type($4);
                                                         node_symbol_type_to_enum_type($2);
                                                         printf("enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'\n");
                                                       }
	| ENUM IDENTIFIER                              {
                                                         $$=make_parent(enum_specifier_type, $2, 4, yylineno);
                                                         node_symbol_type_to_enum_type($2);
                                                         printf("enum_specifier: ENUM IDENTIFIER\n");
                                                       }
	;

enumerator_list
	: enumerator                        {
                                              $$=make_parent(enumerator_list_type, $1, 0, yylineno);
                                              printf("enumrator_list: enumerator\n");
                                            }
	| enumerator_list ',' enumerator    {
                                              add_child($1, $3);
                                              $$=$1;
                                              printf("enumrator_list: enumerator_list ',' enumerator\n");
                                            }
	;

enumerator	/* identifiers must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant '=' constant_expression  {
                                                          $$=make_parent(enumerator_type, $1, 0, yylineno);
                                                          make_brother($1, $3);
                                                          printf("enumerator: enumerator_constant '=' constant_expression\n");
                                                        }
	| enumeration_constant                          {
                                                          $$=make_parent(enumerator_type, $1, 1, yylineno);
                                                          printf("enumerator_constant\n");
                                                        }
	;

atomic_type_specifier
	: ATOMIC '(' type_name ')'             {
                                                 $$=make_parent(atomic_type_specifier_type, $3, 0, yylineno);
                                                 printf("atomic_type_specifier: ATOMIC '(' type_name ')'\n");
                                               }
	;

type_qualifier
	: CONST       {
                        //struct node_my *child_tmp=make_parent(CONST_type, node_number, 0x00, -1);
                        $$=make_parent(type_qualifier_type, 0x00, 0, yylineno);
                        printf("type_qualifier: CONST\n");
                      }
	| RESTRICT    {
                        //struct node_my *child_tmp=make_parent(RESTRICT_type, node_number, 0x00, -1);
                        $$=make_parent(type_qualifier_type, 0x00, 1, yylineno);
                        printf("type_qualifier: RESTRICT\n");
                      }
	| VOLATILE    {
                        //struct node_my *child_tmp=make_parent(VOLATILE_type, node_number, 0x00, -1);
                        $$=make_parent(type_qualifier_type, 0x00, 2, yylineno);
                        printf("type_qualifier: VOLATILE\n");
                      }
	| ATOMIC      {
                        //struct node_my *child_tmp=make_parent(ATOMIC_type, node_number, 0x00, -1);
                        $$=make_parent(type_qualifier_type, 0x00, 3, yylineno);
                        printf("type_qualifier: ATOMIC\n");
                      }
	;

function_specifier
	: INLINE         {
                           //struct node_my *child_tmp=make_parent(INLINE_type, node_number, 0x00, -1);
                           $$=make_parent(function_specifier_type, 0x00, 0, yylineno);
                           printf("function_specifer: INLINE\n");
                         }
	| NORETURN       {
                           //struct node_my *child_tmp=make_parent(NORETURN_type, node_number, 0x00, -1);
                           $$=make_parent(function_specifier_type, 0x00, 1, yylineno);
                           printf("function_specifer: NORETURN\n");
                         }
	;

alignment_specifier
	: ALIGNAS '(' type_name ')'             {
                                                  $$=make_parent(alignment_specifier_type, $3, 0, yylineno);
                                                  printf("alignment_specifer: ALIGNAS '(' type_name ')'\n");
                                                }
	| ALIGNAS '(' constant_expression ')'   {
                                                  $$=make_parent(alignment_specifier_type, $3, 1, yylineno);
                                                  printf("alignment_specifer: ALIGNAS '(' constant_expression ')'\n");
                                                }
	;

declarator
	: pointer direct_declarator {
                                      $$=make_parent(declarator_type, $1, 0, yylineno);
                                      make_brother($1, $2);
                                      printf("declarator: pointer direct_declarator\n");
                                    } 
	| direct_declarator         {
                                      $$=make_parent(declarator_type, $1, 1, yylineno);
                                      printf("declarator: direct_declarator\n");
                                    }
	;

direct_declarator
	: IDENTIFIER                                                                 {
                                                                                       $$=make_parent(direct_declarator_type, $1, 0, yylineno);
                                                                                       printf("direct_declarator: IDENTIFIER\n");
                                                                                     }
	| '(' declarator ')'                                                         {
                                                                                       $$=make_parent(direct_declarator_type, $2, 1, yylineno);
                                                                                       printf("direct_declarator: '(' declarator ')'\n");
                                                                                     }
	| direct_declarator '[' ']'                                                  {
                                                                                       $$=make_parent(direct_declarator_type, $1, 2, yylineno);
                                                                                       printf("direct_declarator: direct_declarator '[' ']'\n");
                                                                                     }
	| direct_declarator '[' '*' ']'                                              {
                                                                                       $$=make_parent(direct_declarator_type, $1, 3, yylineno);
                                                                                       printf("direct_declarator: direct_declarator '[' '*' ']'\n");
                                                                                     }
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']' {
                                                                                       $$=make_parent(direct_declarator_type, $1, 4, yylineno);
                                                                                       make_brother($1, $4);
                                                                                       make_brother($4, $5);
                                                                                       printf("direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'\n");
                                                                                     }
	| direct_declarator '[' STATIC assignment_expression ']'                     {
                                                                                       $$=make_parent(direct_declarator_type, $1, 5, yylineno);
                                                                                       make_brother($1, $4);
                                                                                       printf("direct_declarator: direct_declarator '[' STATIC assignment_expression ']'\n");
                                                                                     }
	| direct_declarator '[' type_qualifier_list '*' ']'                          {
                                                                                       $$=make_parent(direct_declarator_type, $1, 6, yylineno);
                                                                                       make_brother($1, $3);
                                                                                       printf("direct_declarator: direct_declarator '[' type_qualifier_list '*'']' \n");
                                                                                     }
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']' {
                                                                                       $$=make_parent(direct_declarator_type, $1, 7, yylineno);
                                                                                       make_brother($1, $3);
                                                                                       make_brother($3, $5);
                                                                                       printf("direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'\n");
                                                                                     }
	| direct_declarator '[' type_qualifier_list assignment_expression ']'        {
                                                                                       $$=make_parent(direct_declarator_type, $1, 8, yylineno);
                                                                                       make_brother($1, $3);
                                                                                       make_brother($3, $4);
                                                                                       printf("direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'\n");
                                                                                     }
	| direct_declarator '[' type_qualifier_list ']'                              {
                                                                                       $$=make_parent(direct_declarator_type, $1, 9, yylineno); 
                                                                                       make_brother($1, $3); 
                                                                                       printf("direct_declarator: direct_declarator '[' type_qualifier_list ']'\n");
                                                                                     }
	| direct_declarator '[' assignment_expression ']'                            {
                                                                                       $$=make_parent(direct_declarator_type, $1, 10, yylineno);
                                                                                       make_brother($1, $3);
                                                                                       printf("direct_declarator: direct_declarator '[' assignment_expression ']'\n");
                                                                                     }
	| direct_declarator '(' parameter_type_list ')'                              {
                                                                                       $$=make_parent(direct_declarator_type, $1, 11, yylineno);
                                                                                       make_brother($1, $3);
                                                                                       printf("direct_declarator: direct_declarator '(' parameter_type_list ')'\n");
                                                                                     }
	| direct_declarator '(' ')'                                                  {
                                                                                       $$=make_parent(direct_declarator_type, $1, 12, yylineno);
                                                                                       printf("direct_declarator: direct_declarator '(' ')'\n");
                                                                                     }
	| direct_declarator '(' identifier_list ')'                                  {
                                                                                       $$=make_parent(direct_declarator_type, $1, 13, yylineno);
                                                                                       make_brother($1, $3);
                                                                                       printf("direct_declarator: direct_declarator '(' identifier_list ')'\n");
                                                                                     }
	;

pointer
	: '*' type_qualifier_list pointer     {
                                                $$=make_parent(pointer_type, $2, 0, yylineno);
                                                make_brother($2, $3);
                                                printf("pointer: '*' type_qualifier_list pointer\n");
                                              }
	| '*' type_qualifier_list             {
                                                $$=make_parent(pointer_type, $2, 1, yylineno);
                                                printf("pointer: '*' type_qualifier_list\n");
                                              }
	| '*' pointer                         {
                                                $$=make_parent(pointer_type, $2, 2, yylineno);
                                                printf("pointer: '*' pointer\n");
                                              }
	| '*'                                 {
                                                $$=make_parent(pointer_type, 0x00, 3, yylineno);
                                                printf("pointer: '*'\n");
                                              }
	;

type_qualifier_list
	: type_qualifier                        {
                                                  $$=make_parent(type_qualifier_list_type, $1, 0, yylineno);
                                                  printf("type_qualifier_list: type_qualifier\n");
                                                }
	| type_qualifier_list type_qualifier    {
                                                  add_child($1, $2);
                                                  $$=$1;
                                                  printf("type_qualifier_list: type_qualifier_list type_qualifier\n");
                                                }
	;


parameter_type_list
	: parameter_list ',' ELLIPSIS      {
                                             $$=make_parent(parameter_type_list_type, $1, 0, yylineno);
                                             //make_brother($1, $3);
                                             printf("parameter_type_list: parameter_list ',' ELLIPSIS\n");
                                           }
	| parameter_list                   {
                                             $$=make_parent(parameter_type_list_type, $1, 1, yylineno);
                                             printf("parameter_type_list: parameter_list\n");
                                           }
	;

parameter_list
	: parameter_declaration                      {
                                                       $$=make_parent(parameter_list_type, $1, 0, yylineno);
                                                       printf("parameter_list: parameter_declaration\n");
                                                     }
	| parameter_list ',' parameter_declaration   {
                                                       add_child($1, $3);
                                                       $$=$1;
                                                       printf("parameter_list: parameter_list ',' parameter_declaration\n");
                                                     }
	;

parameter_declaration
	: declaration_specifiers declarator             {
                                                          $$=make_parent(parameter_declaration_type, $1, 0, yylineno);
                                                          make_brother($1, $2);
                                                          printf("parameter_declaration: declaration_specifiers declarator\n");
                                                        }
	| declaration_specifiers abstract_declarator    {
                                                          $$=make_parent(parameter_declaration_type, $1, 1, yylineno);
                                                          make_brother($1, $2);
                                                          printf("parameter_declaration: declaration_specifiers abstract_declarator\n");
                                                        }
	| declaration_specifiers                        {
                                                          $$=make_parent(parameter_declaration_type, $1, 2, yylineno);
                                                          printf("parameter_declaration: declaration_specifiers\n");
                                                        }
	;

identifier_list
	: IDENTIFIER                       {
                                             $$=make_parent(identifier_list_type, $1, 0, yylineno);
                                             printf("identifier_list: IDENTIFIER\n");
                                           }
	| identifier_list ',' IDENTIFIER   {
                                             $$=make_parent(identifier_list_type, $1, 1, yylineno);
                                             make_brother($1, $3);
                                             printf("identifier_list: identifier_list ',' IDENTIFIER\n");
                                           }
	;

type_name
	: specifier_qualifier_list abstract_declarator {
                                                         $$=make_parent(type_name_type, $1, 0, yylineno);
                                                         make_brother($1, $2);
                                                         printf("type_name: specifier_qualifier_list abstract_declarator\n");
                                                       }
	| specifier_qualifier_list                     {
                                                         $$=make_parent(type_name_type, $1, 1, yylineno);
                                                         printf("type_name: specifier_qualifier_list\n");
                                                       }
	;

abstract_declarator
	: pointer direct_abstract_declarator     {
                                                   $$=make_parent(abstract_declarator_type, $1, 0, yylineno);
                                                   make_brother($1, $2);
                                                   printf("abstract_declarator: pointer direct_abstract_declarator\n");
                                                 }
	| pointer                                {
                                                   $$=make_parent(abstract_declarator_type, $1, 1, yylineno);
                                                   printf("abstract_declarator: pointer\n");
                                                 }
	| direct_abstract_declarator             {
                                                   $$=make_parent(abstract_declarator_type, $1, 2, yylineno);
                                                   printf("abstract_declarator: direct_abstract_declarator\n");
                                                 }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'        {
                                               $$=make_parent(direct_abstract_declarator_type, $2, 0, yylineno);
                                               printf("direct_abstract_declarator: '(' abstract_declarator ')'\n");
                                             }
	| '[' ']'                            {
                                               $$=make_parent(direct_abstract_declarator_type, 0x00, 1, yylineno);
                                               printf("direct_abstract_declarator: '[' ']'\n");
                                             }
	| '[' '*' ']'                        {
                                               $$=make_parent(direct_abstract_declarator_type, 0x00, 2, yylineno);
                                               printf("direct_abstract_declarator: '[' '*' ']'\n");
                                             }
	| '[' STATIC type_qualifier_list assignment_expression ']'   {
                                                                       $$=make_parent(direct_abstract_declarator_type, $3, 3, yylineno);
                                                                       make_brother($3, $4);
                                                                       printf("direct_abstract_declarator: '[' STATIC type_qualifier_list assignment_expression ']'\n");
                                                                     }
	| '[' STATIC assignment_expression ']'                       {
                                                                       $$=make_parent(direct_abstract_declarator_type, $3, 4, yylineno);
                                                                       printf("direct_abstract_declarator: '[' STATIC assignment_expression ']'\n");
                                                                     }
	| '[' type_qualifier_list STATIC assignment_expression ']'   {
                                                                       $$=make_parent(direct_abstract_declarator_type, $2, 5, yylineno);
                                                                       make_brother($2, $4);
                                                                       printf("direct_abstract_declarator: '[' type_qualifier_list STATIC assignment_expression ']'\n");
                                                                     }
	| '[' type_qualifier_list assignment_expression ']'          {
                                                                       $$=make_parent(direct_abstract_declarator_type, $2, 6, yylineno);
                                                                       make_brother($2, $3);
                                                                       printf("direct_abstract_declarator: '[' type_qualifier_list assignment_expression ']'\n");
                                                                     }
	| '[' type_qualifier_list ']'                   {
                                                          $$=make_parent(direct_abstract_declarator_type, $2, 7, yylineno);
                                                          printf("direct_abstract_declarator: '[' type_qualifier_list ']'\n");
                                                        }
	| '[' assignment_expression ']'                 {
                                                          $$=make_parent(direct_abstract_declarator_type, $2, 8, yylineno);
                                                          printf("direct_abstract_declarator: '[' assignment_expression ']'\n");
                                                        }
	| direct_abstract_declarator '[' ']'            {
                                                          $$=make_parent(direct_abstract_declarator_type, $1, 9, yylineno);
                                                          printf("direct_abstract_declarator: direct_abstract_declarator '['  ']'\n");
                                                        }
	| direct_abstract_declarator '[' '*' ']'        {
                                                          $$=make_parent(direct_abstract_declarator_type, $1, 10, yylineno);
                                                          printf("direct_abstract_declarator: direct_abstract_declarator '[' '*' ']'\n");
                                                        }
	| direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'   {
                                                                                                  $$=make_parent(direct_abstract_declarator_type, $1, 11, yylineno);
                                                                                                  make_brother($1, $4);
                                                                                                  make_brother($4, $5);
                                                                                                  printf("direct_abstract_declarator: direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'\n");
                                                                                                }
	| direct_abstract_declarator '[' STATIC assignment_expression ']'                       {
                                                                                                  $$=make_parent(direct_abstract_declarator_type, $1, 12, yylineno);
                                                                                                  make_brother($1, $4);
                                                                                                  printf("direct_abstract_declarator: direct_abstract_declarator '[' STATIC assignment_expression ']'\n");
                                                                                                }
	| direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'          {
                                                                                                  $$=make_parent(direct_abstract_declarator_type, $1, 13, yylineno);
                                                                                                  make_brother($1, $3);
                                                                                                  make_brother($3, $4);
                                                                                                  printf("direct_abstract_declarator: direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'\n");
                                                                                                }
	| direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'   {
                                                                                                  $$=make_parent(direct_abstract_declarator_type, $1, 14, yylineno);
                                                                                                  make_brother($1, $3);
                                                                                                  make_brother($3, $5);
                                                                                                  printf("direct_abstract_declarator: direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'\n");
                                                                                                }
	| direct_abstract_declarator '[' type_qualifier_list ']'    {
                                                                      $$=make_parent(direct_abstract_declarator_type, $1, 15, yylineno);
                                                                      make_brother($1, $3);
                                                                      printf("direct_abstract_declarator: direct_abstract_declarator '[' type_qualifier_list ']'\n");
                                                                    }
	| direct_abstract_declarator '[' assignment_expression ']'  {
                                                                      $$=make_parent(direct_abstract_declarator_type, $1, 16, yylineno);
                                                                      make_brother($1, $3);
                                                                      printf("direct_abstract_declarator: direct_abstract_declarator '[' assignment_expression ']'\n");
                                                                    }
	| '(' ')'                              {
                                                 $$=make_parent(direct_abstract_declarator_type, 0x00, 17, yylineno);
                                                 printf("direct_abstract_declarator: '(' ')'\n");
                                               }
	| '(' parameter_type_list ')'          {
                                                 $$=make_parent(direct_abstract_declarator_type, $2, 18, yylineno);
                                                 printf("direct_abstract_declarator: '(' parameter_type_list ')'\n");
                                               }
	| direct_abstract_declarator '(' ')'   {
                                                 $$=make_parent(direct_abstract_declarator_type, $1, 19, yylineno);
                                                 printf("direct_abstract_declarator: direct_abstract_declarator '(' ')'\n");
                                               }
	| direct_abstract_declarator '(' parameter_type_list ')'  {
                                                                    $$=make_parent(direct_abstract_declarator_type, $1, 20, yylineno);
                                                                    make_brother($1, $3);
                                                                    printf("direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'\n");
                                                                  }
	;

initializer
	: '{' initializer_list '}'       {
                                           $$=make_parent(initializer_type, $2, 0, yylineno);
                                           printf("initializer: '{' initializer_list '}'\n");
                                         }
	| '{' initializer_list ',' '}'   {
                                           $$=make_parent(initializer_type, $2, 1, yylineno);
                                           printf("initializer: '{' initializer_list ',' '}'\n");
                                         }
	| assignment_expression          {
                                           $$=make_parent(initializer_type, $1, 2, yylineno);
                                           printf("initializer: assignment_expression\n");
                                           //printf("node_number: %d\n", node_number);
                                         }            
	;

initializer_list
	: designation initializer     {
                                        $$=make_parent(initializer_list_type, $1, 0, yylineno);
                                        make_brother($1, $2);
                                        printf("initializer_list: designation initializer\n");
                                      }
	| initializer                 {
                                        $$=make_parent(initializer_list_type, $1, 1, yylineno);
                                        printf("initializer_list: initializer\n");
                                      }
	| initializer_list ',' designation initializer {
                                                         add_child($1, $3);
                                                         add_child($1, $4);
                                                         $$=$1;
                                                         printf("initializer_list: initializer_list ',' designation initializer\n");
                                                       }
	| initializer_list ',' initializer             {
                                                         add_child($1, $3);
                                                         $$=$1;
                                                         printf("initializer_list: initializer_list ',' initializer\n");
                                                       }
	;

designation
	: designator_list '='             {
                                            $$=make_parent(designation_type, $1, 0, yylineno);
                                            printf("designation: designator_list '='\n");
                                          }
	;

designator_list
	: designator                        {
                                              $$=make_parent(designator_list_type, $1, 0, yylineno);
                                              printf("designator_list: designator\n");
                                            }
	| designator_list designator        {
                                              add_child($1, $2);
                                              $$=$1;
                                              printf("designator_list: designator_list designator\n");
                                            }
	;

designator
	: '[' constant_expression ']'  {
                                         $$=make_parent(designator_type, $2, 0, yylineno);
                                         printf("designator: '[' constant_expression ']'\n");
                                       }
	| '.' IDENTIFIER               {
                                         $$=make_parent(designator_type, $2, 1, yylineno);
                                         printf("designator: '.' IDENTIFIER\n");
                                       }
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';' {
                                                                             $$=make_parent(static_assert_declaration_type, $3, 0, yylineno);
                                                                             make_brother($3, $5);
                                                                             printf("static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'\n");
                                                                           }
	;

statement
	: labeled_statement             {
                                          $$=make_parent(statement_type, $1, 0, yylineno);
                                          printf("statement: labeled_statement\n");
                                        }
	| compound_statement            {
                                          $$=make_parent(statement_type, $1, 1, yylineno);
                                          printf("statement: compound_statement\n");
                                        }
	| expression_statement          {
                                          $$=make_parent(statement_type, $1, 2, yylineno);
                                          printf("statement: expression_statement\n");
                                        }
	| selection_statement           {
                                          $$=make_parent(statement_type, $1, 3, yylineno);
                                          printf("statement: selection_statement\n");
                                        }
	| iteration_statement           {
                                          $$=make_parent(statement_type, $1, 4, yylineno);
                                          printf("statement: iteration_statement\n");
                                        }
	| jump_statement                {
                                          $$=make_parent(statement_type, $1, 5, yylineno);
                                          printf("statement: jump_statement\n");
                                        }
	;

labeled_statement
	: IDENTIFIER ':' statement                 {
                                                     $$=make_parent(labeled_statement_type, $1, 0, yylineno);
                                                     make_brother($1, $3);
                                                     printf("labeled_statement: IDENTIFIER ':' statement\n");
                                                   }
	| CASE constant_expression ':' statement   {
                                                     $$=make_parent(labeled_statement_type, $2, 1, yylineno);
                                                     make_brother($2, $4);
                                                     printf("labeled_statement: CASE constant_expression ':' statement\n");
                                                   }
	| DEFAULT ':' statement                    {
                                                     $$=make_parent(labeled_statement_type, $3, 2, yylineno);
                                                     printf("labeled_statement: DEFAULT ':' statement\n");
                                                   }
	;

compound_statement
	: '{' '}'                      {
                                         $$=make_parent(compound_statement_type, 0x00, 0, yylineno);
                                         give_compound_id($$);
                                         printf("compound_statement: '{' '}'\n");
                                       }
	| '{'  block_item_list '}'     {
                                         $$=make_parent(compound_statement_type, $2, 1, yylineno);
                                         give_compound_id($$);
                                         printf("compound_statement(id:%d): '{' block_item_list '}'\n", my_state.node_number);
                                       }
	;           

block_item_list
	: block_item                    {
                                          $$=make_parent(block_item_list_type, $1, 0, yylineno);
                                          printf("block_item_list: block_item\n");
                                        }
	| block_item_list block_item    {
                                          add_child($1, $2);
                                          $$=$1;
                                          printf("block_item_list: block_item_list block_item\n");
                                        }
	;

block_item
	: declaration     {
                            $$=make_parent(block_item_type, $1, 0, yylineno);
                            printf("block_item: declaration\n");
                          }
	| statement       {
                            $$=make_parent(block_item_type, $1, 1, yylineno);
                            printf("block_item: statement\n");
                          }
	;

expression_statement
	: ';'                {
                               $$=make_parent(expression_statement_type, 0x00, 0, yylineno);
                               printf("expression_statement: ';'\n");
                             }
	| expression ';'     {
                               $$=make_parent(expression_statement_type, $1, 1, yylineno);
                               printf("expression_statement: expression ';'\n");
                             }
	;

selection_statement
	: IF '(' expression ')' statement ELSE statement  {
                                                            $$=make_parent(selection_statement_type, $3, 0, yylineno);
                                                            make_brother($3, $5);
                                                            make_brother($5, $7);
                                                            printf("selection_statement: IF '(' expression ')' statement ELSE statement\n");
                                                          }
	| IF '(' expression ')' statement                 {
                                                            $$=make_parent(selection_statement_type, $3, 1, yylineno);
                                                            make_brother($3, $5);
                                                            printf("selection_statement: IF '(' expression ')' statement\n");
                                                          }
	| SWITCH '(' expression ')' statement             {
                                                            $$=make_parent(selection_statement_type, $3, 2, yylineno);
                                                            make_brother($3, $5);
                                                            printf("selection_statement: SWITCH '(' expression ')' statement\n");
                                                          }
	;

iteration_statement
	: WHILE '(' expression ')' statement             {
                                                           $$=make_parent(iteration_statement_type, $3, 0, yylineno);
                                                           make_brother($3, $5);
                                                           printf("iteration_statement: WHILE '(' expression ')' statement\n");
                                                         }
	| DO statement WHILE '(' expression ')' ';'      {
                                                           $$=make_parent(iteration_statement_type, $2, 1, yylineno);
                                                           make_brother($2, $5);
                                                           printf("iteration_statement: DO  statement WHILE '(' expression ')'\n");
                                                         }
	| FOR '(' expression_statement expression_statement ')' statement                {
                                                                                           $$=make_parent(iteration_statement_type, $3, 2, yylineno);
                                                                                           make_brother($3, $4);
                                                                                           make_brother($4, $6);
                                                                                           printf("iteration_statement: FOR '(' expression_statement expression_statement ')' statement\n");
                                                                                         }
	| FOR '(' expression_statement expression_statement expression ')' statement     {
                                                                                           $$=make_parent(iteration_statement_type, $3, 3, yylineno);
                                                                                           make_brother($3, $4);
                                                                                           make_brother($4, $5);
                                                                                           make_brother($5, $7);
                                                                                           printf("iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement\n");
                                                                                         }
	| FOR '(' declaration expression_statement ')' statement             {
                                                                               $$=make_parent(iteration_statement_type, $3, 4, yylineno);
                                                                               make_brother($3, $4);
                                                                               make_brother($4, $6);
                                                                               printf("iteration_statement: FOR '(' declaration expression_statement ')' statement\n");
                                                                             }
	| FOR '(' declaration expression_statement expression ')' statement  {
                                                                               $$=make_parent(iteration_statement_type, $3, 4, yylineno);
                                                                               make_brother($3, $4);
                                                                               make_brother($4, $5);
                                                                               make_brother($5, $7);
                                                                               printf("iteration_statement: FOR '(' declaration expression_statement expression ')' statement\n");
                                                                             }
	;

jump_statement
	: GOTO IDENTIFIER ';'   {
                                  $$=make_parent(jump_statement_type, $2, 0, yylineno);
                                  printf("jump_statement: GOTO IDENTIFIER ';'\n");
                                }
	| CONTINUE ';'          {
                                  $$=make_parent(jump_statement_type, 0x00, 1, yylineno);
                                  printf("jump_statement: CONTINUE ';'\n");
                                }
	| BREAK ';'             {
                                  $$=make_parent(jump_statement_type, 0x00, 2, yylineno);
                                  printf("jump_statement: BREAK ';'\n");
                                }
	| RETURN ';'            {
                                  $$=make_parent(jump_statement_type, 0x00, 3, yylineno);
                                  printf("jump_statement: RETURN ';'\n");
                                }
	| RETURN expression ';' {
                                  $$=make_parent(jump_statement_type, $2, 4, yylineno);
                                  printf("jump_statement: RETURN expression ';'\n");
                                }
	;

translation_unit
	: external_declaration                   {
                                                   //printf("line:1478 node_number: %d\n", node_number);
                                                   $$=make_parent(translation_unit_type, $1, 0, yylineno);
                                                   my_state.translation_unit_node=$$;
                                                   //translation_unit_table[translation_unit_number]=$$;
                                                   //printf("%s\n", node_type_str[$$->node_type]);
                                                   //printf("line1518%s\n", node_type_str[translation_unit_type]);
       
                                                   //translation_unit_number+=1;
                                                   printf("-------------------------translation_unit: external_declaration\n");
                                                   //printf("%s -------------------------translation_unit: external_declaration\n", node_type_str[not_know_type]);
                                                   //print_node_table();
                                                 }             
	| translation_unit external_declaration  {
                                                   //printf("line:1484 node_number: %d\n", node_number);
                                                   add_child($1, $2);
                                                   $$=$1;
                                                   printf("=========================translation_unit: translation_unit external_declaration\n");
                                                   //print_node_table();
                                                 }
	;

external_declaration
	: function_definition     {
                                    $$=make_parent(external_declaration_type, $1, 0, yylineno);
                                    //printf("cbison.y:1624 start\n");
                                    smbl_function_definition($1->node_index);    //20150515   key
                                    //printf("cbison.y:1624 end\n");
                                    //external_declaration_table[external_declaration_number]=$$;
                                    //external_declaration_number+=1;
                                    printf("external_declaration: function_definition\n");
                                  }
	| declaration             {
                                    //printf("line:1497 node_number: %d\n", node_number);
                                    $$=make_parent(external_declaration_type, $1, 1, yylineno);
                                    //external_declaration_table[external_declaration_number]=$$;
                                    //external_declaration_number+=1;
                                    //deal_declaration($1->node_index);    /20150515
                                    printf("external_declaration: declaration\n");
                                  }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement   {
                                                                                    $$=make_parent(function_definition_type, $1, 0, yylineno);
                                                                                    make_brother($1, $2);
                                                                                    make_brother($2, $3);
                                                                                    make_brother($3, $4);
                                                                                    //smbl_function_definition(-1);
                                                                                    printf("function_defination: declaration_specifiers declarator declaration_lsit compound_statement\n");
                                                                                  }
	| declaration_specifiers declarator compound_statement                    {
                                                                                    //test
                                                                                    //deal_declaration_specifiers($1->node_index);
                                                                                    $$=make_parent(function_definition_type, $1, 1, yylineno);
                                                                                    make_brother($1, $2);
                                                                                    make_brother($2, $3);
                                                                                    //smbl_function_definition(-1);
                                                                                    printf("function_defination: declaration_specifiers declarator compound_statement\n");
                                                                                  }

declaration_list
	: declaration                        {
                                               $$=make_parent(declaration_list_type, $1, 0, yylineno);
                                               printf("declaration_list: declaration\n");
                                             }            
	| declaration_list declaration       {
                                               add_child($1, $2);
                                               $$=$1;
                                               printf("declaration_list: declaration_list declaration\n");
                                             }
	;

%%
#include <stdio.h>

void yyerror(const char *s)
{
    fflush(stdout);
    fprintf(stderr, "*** %s\n", s);
}




int main(int argc, char **argv)
{
    

    extern FILE *yyin;
    deal_arg(argc, argv);
    printf("before initialize compiler state\n");
    initialize_compiler_state(0, 0);    
    printf("after  initialize compiler state\n");
    print_compiler_state();


    /*
    FILE *fd=fopen(argv[1], "r");
    dot_fd=open("out.dot", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    printf("dot_fd: %d\n", dot_fd);
    char *dot_start="digraph G{\n";
    int write_num=write(dot_fd, dot_start, strlen(dot_start));
    printf("write_num: %d\n", write_num);
    yyin=fd;
    */
    yyin=my_state.c_file_fd;

    yyparse();
    print_node_table();
    //print_translation_unit_table(); 
    //print_external_declaration_table();
    
    preorder_traversal_node_table(my_state.translation_unit_node->node_id, 0);

    /*
    char *dot_stop="}\n";
    write(dot_fd, dot_stop, strlen(dot_stop));
    close(dot_fd);
    */
 
    print_symbol_table();

    print_scope_list();
    print_scope_stack();    
  
    print_declaration_specifiers_table();
    print_declarator_table();
    print_direct_declarator_table();
    print_compound_statement_table();

    print_block_item_table();

    print_declaration_table();
    print_init_declarator_table();
    print_initializer_table();
    print_initializer_list_table();
    print_initializer_list_one_table();

    //---------------------20150401 start---
    print_statement_table();
    print_labeled_statement_table();
    print_expression_statement_table();
    print_selection_statement_table();
    print_iteration_statement_table();
    print_jump_statement_table();
    print_expression_table();
    print_assignment_expression_table();
    print_conditional_expression_table();   //: ?
    print_unary_expression_table();        
    print_logical_or_expression_table();    // ||
    print_logical_and_expression_table();   // &&
    print_inclusive_or_expression_table();  // |;
    print_exclusive_or_expression_table();  // ^;
    print_and_expression_table(); // &   
    print_equality_expression_table(); //
    print_relational_expression_table(); //  > < >= <=
    print_shift_expression_table(); //  >> <<
    print_additive_expression_table(); //  >> <<
    print_multiplicative_expression_table();  //* / %
    print_cast_expression_table();  //* / %
    print_unary_expression_table();  //* / %
    print_postfix_expression_table();  //* / %
    print_primary_expression_table();  //* / %
    print_IDENTIFIER_table();

    print_struct_or_union_specifier_table();

    print_parameter_declaration_table();
    print_function_definition_table();


    print_symbol_a_table();  
    print_instruction_table();  

    //---------------------20150401 end  ---


    destroy_compiler_state();

    return 0;
}


