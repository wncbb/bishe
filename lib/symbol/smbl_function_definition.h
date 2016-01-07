
#ifndef SMBL_FUNCTION_DEFINITION_H
#define SMBL_FUNCTION_DEFINITION_H




/*
 * parameter_list:
 *                0. parameter_list , ELLIPSIS
 *                1. parameter_list
 */
struct parameter_list_infor{
  int index;
  int node_index;
  int category;
  int child_num;
  int first_child;
};


/*
 * paramter_declaration:
 *                      0.declaration_specifiers declarator
 *                      1.declaration_specifiers abstract_declarator
 *                      2.declaration_spscifiers
 */
struct parameter_declaration_infor{
  int index;
  int node_index;
  int category;
  int data1_index; 
  int data2_index; 
  int next_sibling;
};




/*
struct_or_union_specifier:
                          0. struct_or_union { struct_declaration_list }
                          1. struct_or_union IDENTIFIER { struct_declaration_list }
                          2. struct_or_union IDENTIFIER
*/
struct struct_or_union_specifier_infor{
    int index;
    int node_index;
    int category;
    int data1_index; //IDENTIFIER
    int data2_index; //struct_declaration_list
};







struct list_node{
    int data;
    struct list_node * next;
};

struct IDENTIFIER_infor{
    int index;
    int node_num;
    int node_index;
    struct list_node * node_ptr;
    int smbl_num;
    struct list_node * smbl_ptr;
    int symbol_a_index;
    char *smbl_name;
    int declaration_specifiers_index;
};



struct storage_class_specifier_infor{
    /*
    none ---------------------------- 0(default, depend on the scope)
    TYPEDEF(typedef) ---------------- 1
    EXTERN(extern) ------------------ 2
    STATIC(static) ------------------ 3
    THREAD_LOCAL(thread_local) ------ 4
    AUTO(auto) ---------------------- 5
    REGISTER(register) -------------- 6
    */    


    unsigned int value;
};


struct type_specifier_infor{
    /*
    none -----------------------------  0
    void -----------------------------  1
    bool -----------------------------  2
   
    signed   char --------------------  3
    unsigned char --------------------  4
  
    signed   short int ---------------  5
    unsigned short int ---------------  6
    signed   int ---------------------  7
    unsigned int ---------------------  8
    signed   long int ----------------  9
    unsigned long int ---------------- 10
    signed   long long int ----------- 11
    unsigned long long int ----------- 12

    float ---------------------------- 13
    double --------------------------- 14
    long double ---------------------- 15
 
    complex -------------------------- 16
    imaginary ------------------------ 17
    atomic_type_specifier ------------ 18
    struct_or_union_specifier -------- 19
    
    enum_specifier ------------------- 20

    TYPEDEF_NAME --------------------- 21
    */
    /*
    RIGHT 
    1st 4bit:
     0 0x0000_0000 defalut
     1 0x0000_0001 void
     2 0x0000_0002 char
     3 0x0000_0003 int 
     4 0x0000_0004 float
     5 0x0000_0005 double
     6 0x0000_0006 bool
     7 0x0000_0007 complex
     8 0x0000_0008 imaginary
     9 0x0000_0009 atomic_type_specifier
    10 0x0000_000a struct_or_union_specifier
    11 0x0000_000b enum_specifier
    12 0x0000_000c TYPEDEF_NAME

    2nd 2bit:
     0 0x0000_0000 signed
     1 0x0000_0010 unsigned

    3rd 2bit:
     0 0x0000_0000 default 
     1 0x0000_0020 short
     2 0x0000_0040 long
     3 0x0000_0080 long long
 
    4rd 24bit:
     index

    */

    unsigned int value;
};


struct type_qualifier_infor
{
    /*
    none ------------------- 0x0000_0000
    those below could coexist
    const ------------------ 0x0000_0001
    restrict --------------- 0x0000_0010
    volatile --------------- 0x0000_0100
    atomic ----------------- 0x0000_1000
    */
    unsigned int value;
};

struct function_specifier_infor
{
    /*
    none ----------------- 0(default)
    those below can coexist
    INLINE(inline) ------- 0x0000_0001
    NORETURN(noreturn) --- 0x0000_0010
    */
    unsigned int value;
};

struct alignment_specifier_infor{
    /*
    not used yet
    alignment_specifier:
    : ALIGNAS (type name)
    | ALIGNAS (constant expression)
    */
    unsigned int value;    

};


struct declaration_specifiers_infor{
    int index;
    struct storage_class_specifier_infor scs_1;
    struct type_specifier_infor ts_2; 
    struct type_qualifier_infor tq_3;
    struct function_specifier_infor fs_4;
    struct alignment_specifier_infor as_5;
};

struct function_defintion_infor{
    unsigned int declaration_specifiers_index;
    unsigned int declarator_index;
};

struct direct_declarator_one_infor{
    int category;  
    //IDENTIFIER ---------------- 0
    //(declarator) -------------- 1
    //[] -------------------------------------- 2
    //[*] ------------------------------------- 3
    //[STATIC type_qualifier_list assignment_expression] ------- 4
    //[STATIC assignment_expression] --------------------------- 5
    //[type_qualifier_list *] ---------------------------------- 6
    //[type_qualifier_list STATIC assignment_expression] ------- 7
    //[type_qualifier_list assignment_expression] -------------- 8
    //[type_qualifier_list] -----  9
    //[assignment_expression] --- 10
    //(parameter_type_list) ----- 11
    //() ------------------------ 12
    //(identifier_list) --------- 13
    
    int index1;
    int index2;
    struct direct_declarator_one_infor * next;
};

struct direct_declarator_infor{
    int index;
    
    int is_IDENTIFIER;
    //true  IDENTIFIER node index
    //false declarator node index

    int node_index; 
    //node index

    int number; //pointer numbers 
    //pointer[] numbers

    struct direct_declarator_one_infor * next;
};


struct block_item_infor{
    int index;
    int node_index;
    int is_statement; //0--declaration   1--statement
    int data_index;  //declaration or statement's table index
    int child_index;  //declaration or statement's node index
    struct block_item_infor * next;
};

struct compound_statement_infor{
    int index;
    int node_index;
    int block_item_num;
    struct block_item_infor * next;
};
//------------------------------------------------------------


struct initializer_list_one_infor{
    int index;
    int designation_node_index;
    int initializer_node_index;
    int designation_index;  //infor index
    int initializer_index;  //infor index
    struct initializer_list_one_infor *next;
};



/*
initializer_list:
    0 designation initializer
    1 initializer
    2 initializer_list ',' designation initializer
    3 initializer_list ',' initializer
actually, it's
    initializer  
    or
    designation initializer
*/
struct initializer_list_infor{
    int index;
    int node_index;
    unsigned int initializer_list_one_num;  //initializer  or designation initializer
    struct initializer_list_one_infor *next;
};


/*
initializer:
   0 {initializer_list}
   1 {initializer_list, }
   2 assignment_expression
*/
struct initializer_infor{
    int index;
    int node_index;  //index of the node
    int is_assignment_expression;  //0:initializer_list  1:assignment_expression
    int data_index;  //initializer_list or assignment_expression's index
    

};

struct init_declarator_infor{    //skip init_declarator_list
    int index;
    int node_index;
    int declarator_index;   //declarator
    int initializer_index;  //initializer
    struct init_declarator_infor * next;
};

struct declaration_infor{
    int index;
    int node_index; //declaration'sn node index

    int declaration_specifiers_index;
    int static_assert_declaration_index;

    int init_declarator_num;
    struct init_declarator_infor *next;
};

struct declarator_infor{
    int index;
    int node_index;
    int pointer_index;
    int direct_declarator_index;
};
//------------------------------------------20150327 start ----------

struct statement_infor{
    int index;
    int node_index;
    int category;
    int data_index;
};

struct jump_statement_infor{
    int index;
    int node_index;
    int category;
    int data_index;
};

struct iteration_statement_infor{
    int index;
    int node_index;
    int category;
    int data1_index;
    int data2_index;
    int data3_index;
    int data4_index;
};


struct selection_statement_infor{
    int index;
    int node_index;
    int category;
    int data1_index; //expression
    int data2_index; //statement
    int data3_index; //statement
};

struct labeled_statement_infor{
    int index;
    int node_index;
    int category;
    int data1_index;  //IDENTIFIER OR constant_expression or statement 
    int data2_index;  //statement
};

struct expression_statement_infor{
    int index;
    int node_index;
    int category;
    int data_index;
};

struct expression_infor{
    int index;
    int node_index;
    int data_num;
    int data_index; //first expression index
};

struct assignment_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index; //unary_expression or conditional_expression
    int data2_index; //assignment_expression
    int next_index;  
};

struct conditional_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index;  //logical_or_expression
    int data2_index;  //expression
    int data3_index;  //conditional_expression
};

struct logical_or_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index; //logical_or_expression or logical_and_expression
    int data2_index; //logical_and_expression
};

struct logical_and_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index; //logical_and_expression or inclusive_or_expression
    int data2_index; //inclusive_or_expression
};

struct inclusive_or_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index; //inclusive_or_expression or exclusive_or_expression
    int data2_index; //exclusive_or_expression
};

struct exclusive_or_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index; //exclusive_or_expression or and_expression
    int data2_index; //and_expression
};

struct and_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index; //and_expression or equality_expression
    int data2_index; //equality_expression
};

struct equality_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index; //equalifty_expression or relational_expression
    int data2_index; //relational_expression
};

struct relational_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index;  //relational_expression or shift_expression
    int data2_index;  //shift_expression
};

struct shift_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index; //shift_expression or additive_expression
    int data2_index; //additive_expression
};

struct additive_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index;   //addicitive_expreesion or multiplicative_expression
    int data2_index;   //multiplicative_expression
};

struct multiplicative_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index;  //multiplicative_expression  or cast_expression
    int data2_index;  //cast_expression
};

struct cast_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index;
    int data2_index;
};

struct unary_expression_infor{
    int index;
    int node_index;
    int category;
    int data_index;
};

struct postfix_expression_infor{
    int index;
    int node_index;
    int category;
    int data1_index;
    int data2_index;
};



struct primary_expression_infor{
    int index;
    int node_index;
    int category;
    int data_index;
};

struct function_definition_infor{
    int index;
    int node_index;
    int category;
    int data1_index; //declaration_specifiers
    int data2_index; //declarator
    int data3_index; //declaration_list
    int data4_index; //compound_statement
};







//------------------------------------------20150327 end ------------





//--------------------------------------------------------------


#endif


//----------------------------------------------------------------
int print_function_definition_infor(int index);
int print_function_definition_table();

int print_struct_or_union_specifier_infor(int index);
int print_struct_or_union_specifier_table();

int print_block_item_infor2(int index);
int print_block_item_table();

int print_initializer_list_one_infor(int index);
int print_initializer_list_one_table();

int print_initializer_list_infor(int index);
int print_initializer_list_table();

int print_initializer_infor(int index);
int print_initializer_table();

int print_declarator_infor(int index);
int print_declarator_table();

int print_declaration_infor(int index);
int print_declaration_table();

int print_init_declarator_table();
int print_init_declarator_infor();

int add_init_declarator_table_num();
int add_declaration_table_num();
struct init_declarator_infor * deal_init_declarator(int node_index);

struct init_declarator_infor* deal_init_declarator_list(int node_index);
int deal_static_assert_declaration(int node_index);
int deal_declaration(int node_index);
//----------------------------------------------------------------


int add_block_item_table_num();
int add_initializer_list_one_table_num();
int add_initializer_list_table_num();
int add_initializer_table_num();
int add_declaration_specifiers_table_num();
int add_direct_declarator_num();
int add_declaration_specifiers_num();


int print_direct_declarator(int index);
int print_direct_declarator_table();

int print_block_item_infor(struct block_item_infor * next);
int print_compound_statement_infor(int index);
int print_compound_statement_table();

int deal_initializer(int node_index);

int deal_compound_statement(int node_index);

int deal_direct_declarator_one(int node_index);
int deal_direct_declarator(int node_index);



int smbl_function_definition(int node_index);

int deal_declarator(int node_index);

int print_declaration_specifiers_table();
int print_declaration_specifiers_infor(int index);
int deal_declaration_specifiers(int node_index);

int print_storage_class_specifier(unsigned int value);
unsigned int deal_storage_class_specifier(int node_index, unsigned int value);

int print_type_specifier(unsigned int value);
unsigned int deal_type_specifier(int node_index, unsigned int value);

int print_type_qualifier(unsigned int value);
unsigned int deal_type_qualifier(int node_index, unsigned int value);

int print_function_specifier(unsigned int value);
unsigned int deal_function_specifier(int node_index, unsigned int value);

unsigned int deal_alignment_specifier(int node_index, unsigned int value);


int print_type_specifier(unsigned int data);

//--------------------20150328 start---------------------------

int  add_statement_table_num();
int deal_statement(int node_index);

int  add_jump_statement_table_num();
int deal_jump_statement(int node_index);

int  add_iteration_statement_table_num();
int deal_iteration_statement(int node_index);

int  add_selection_statement_table_num();
int deal_selection_statement(int node_index);

int  add_labeled_statement_table_num();
int deal_labeled_statement(int node_index);

int  add_expression_statement_table_num();
int deal_expression_statement(int node_index);

int  add_expression_table_num();
int deal_expression(int node_index);

int  add_assignment_expression_table_num();
int deal_assignment_expression(int node_index);

int  add_conditional_expression_table_num();
int deal_conditional_expression(int node_index);

int  add_logical_or_expression_table_num();
int deal_logical_or_expression(int node_index);

int  add_logical_and_expression_table_num();
int deal_logical_and_expression(int node_index);

int  add_inclusive_or_expression_table_num();
int deal_inclusive_or_expression(int node_index);

int  add_exclusive_or_expression_table_num();
int deal_exclusive_or_expression(int node_index);

int  add_and_expression_table_num();
int deal_and_expression(int node_index);

int  add_equality_expression_table_num();
int deal_equality_expression(int node_index);

int  add_relational_expression_table_num();
int deal_relational_expression(int node_index);

int  add_shift_expression_table_num();
int deal_shift_expression(int node_index);

int  add_additive_expression_table_num();
int deal_additive_expression(int node_index);

int  add_multiplicative_expression_table_num();
int deal_multiplicative_expression(int node_index);

int  add_cast_expression_table_num();
int deal_cast_expression(int node_index);

int  add_unary_expression_table_num();
int deal_unary_expression(int node_index);

int  add_postfix_expression_table_num();
int deal_postfix_expression(int node_index);

int  add_primary_expression_table_num();
int deal_primary_expression(int node_index);

int  add_struct_or_union_specifier();
int deal_struct_or_union_specifier(int node_index);


//--------------------20150328 end  ---------------------------

int deal_IDENTIFIER(int node_index, int type);
int print_IDENTIFIER_infor(int index);
int print_IDENTIFIER_table();


int add_function_definition_table_num();
int add_function_definition_infor(int node_index, int category, int data1_index, int data2_index, int data3_index, int data4_index);

//2016
int deal_parameter_type_list(int node_index);
int deal_parameter_list(int node_index);
int deal_parameter_declaration(int node_index);

int add_parameter_list_table_num();
int make_parameter_list_infor(int node_index);

int print_paramter_declaration_infor();
int print_paramter_declaration_table();
int add_parameter_declaration_table_num();
int make_parameter_declaration_infor(int node_index);









