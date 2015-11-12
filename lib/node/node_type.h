#ifndef NODE_TYPE_H
#define NODE_TYPE_H
enum note_type_enum {
    not_know_type,    //--------------------------  0              
//a:
    ADD_ASSIGN_type,//----------------------------  1
    AND_ASSIGN_type,//----------------------------  2
    abstract_declarator_type,   //----------------  3
    additive_expression_type,   //----------------  4
    alignment_specifier_type,   //----------------  5
    and_expression_type,  //----------------------  6
    argument_expression_list_type, //-------------  7
    assignment_expression_type,  //---------------  8
    assignment_operator_type,  //-----------------  9
    atomic_type_specifier_type,  //--------------- 10

//b:
    block_item_list_type,  //--------------------- 11
    block_item_type,  //-------------------------- 12

//c:
    cast_expression_type,  //--------------------- 13
    compound_statement_type,  //------------------ 14
    conditional_expression_type,  //-------------- 15
    constant_expression_type,  //----------------- 16
    constant_type,  //---------------------------- 17

//d:
    DEFAULT_type,  //----------------------------- 18
    DIV_ASSIGN_type,  //-------------------------- 19
    declaration_list_type,  //-------------------- 20
    declaration_specifiers_type,  //-------------- 21
    declaration_type,  //------------------------- 22
    declarator_type,  //-------------------------- 23
    designation_type,  //------------------------- 24
    designator_list_type,  //--------------------- 25
    designator_type,  //-------------------------- 26
    direct_abstract_declarator_type,  //---------- 27
    direct_declarator_type,  //------------------- 28
    
//e:
    ENUMERATION_CONSTANT_type,  //---------------- 29
    EQU_ASSIGN_type,  //-------------------------- 30
    enum_specifier_type, //----------------------- 31
    enumeration_constant_type, //----------------- 32
    enumerator_list_type,  //--------------------- 33
    enumerator_type,  //-------------------------- 34

    equality_expression_type,  //----------------- 35
    exclusive_or_expression_type,  //------------- 36
   
    expression_statement_type,  //---------------- 37
    expression_type,  //-------------------------- 38
    external_declaration_type,  //---------------- 39

//f:
    FUNC_NAME_type,  //--------------------------- 40
    F_CONSTANT_type,  //-------------------------- 41
    function_definition_type,  //----------------- 42
    function_specifier_type,  //------------------ 43

//g:
    GENERIC_type,  //----------------------------- 44
    generic_assoc_list_type,  //------------------ 45
    generic_association_type,  //----------------- 46
    generic_selection_type,  //------------------- 47

//h:

//i:
    I_CONSTANT_type,  //-------------------------- 48
    IDENTIFIER_type,  //-------------------------- 49
    IMAGINARY_type,  //--------------------------- 50
    identifier_list_type,  //--------------------- 51
    inclusive_or_expression_type,  //------------- 52
    init_declarator_list_type,  //---------------- 53
    init_declarator_type,  //--------------------- 54
    initializer_list_type,  //-------------------- 55
    initializer_type,  //------------------------- 56
    iteration_statement_type,  //----------------- 57
    
//j:

    jump_statement_type,  //---------------------- 58

//k:

//l:
    LEFT_ASSIGN_type,  //------------------------- 59
    labeled_statement_type,  //------------------- 60
    logical_and_expression_type,  //-------------- 61
    logical_or_expression_type,  //--------------- 62

//m:
    MOD_ASSIGN_type,  //-------------------------- 63
    MUL_ASSIGN_type,  //-------------------------- 64
    multiplicative_expression_type,  //----------- 65

//n:

//o:
    OR_ASSIGN_type,  //--------------------------- 66

//p:
    parameter_declaration_type,  //--------------- 67
    parameter_list_type,  //---------------------- 68
    parameter_type_list_type,  //----------------- 69
    pointer_type,  //----------------------------- 70
    postfix_expression_type,  //------------------ 71
    primary_expression_type,  //------------------ 72

//q:

//r:
    RIGHT_ASSIGN_type,  //------------------------ 73
    relational_expression_type,  //--------------- 74

//s: 
    STRING_LITERAL_type,  //---------------------- 75
    SUB_ASSIGN_type,  //-------------------------- 76
    selection_statement_type,  //----------------- 77
    shift_expression_type,  //-------------------- 78
    specifier_qualifier_list_type,  //------------ 79
    statement_type,  //--------------------------- 80
    static_assert_declaration_type,  //----------- 81
    storage_class_specifier_type,  //------------- 82
    string_type,  //------------------------------ 83
    struct_declaration_list_type,  //------------- 84
    struct_declaration_type,  //------------------ 85
    struct_declarator_list_type,  //-------------- 86
    struct_declarator_type,  //------------------- 87
    struct_or_union_specifier_type,  //----------- 88
    struct_or_union_type,  //--------------------- 89
    
//t:
    TYPEDEF_NAME_type,  //------------------------ 90
    translation_unit_type,  //-------------------- 91
    type_name_type,  //--------------------------- 92
    type_qualifier_list_type,  //----------------- 93
    type_qualifier_type,  //---------------------- 94
    type_specifier_type,  //---------------------- 95

//u:
    unary_expression_type,  //-------------------- 96
    unary_operator_type,  //---------------------- 97

//v:

//w:

//x:
    XOR_ASSIGN_type,  //-------------------------- 98

//y:

//z:
    AUTO_type,  //-------------------------------- 99
    BREAK_type, //--------------------------------100
    CASE_type,  //--------------------------------101
    CHAR_type,  //--------------------------------102
    CONST_type, //--------------------------------103
    CONTINUE_type,  //----------------------------104
//    DEFAULT_type,
    DO_type,  //----------------------------------105
    DO_WHILE_type,  //----------------------------106
    DOUBLE_type,  //------------------------------107
    ELSE_type,    //------------------------------108
    ENUM_type,    //------------------------------109
    EXTERN_type,  //------------------------------110
    FLOAT_type,   //------------------------------111
    FOR_type,     //------------------------------112
    GOTO_type,    //------------------------------113
    IF_type,      //------------------------------114
    INLINE_type,  //------------------------------115
    INT_type,     //------------------------------116
    LONG_type,    //------------------------------117
    REGISTER_type,//------------------------------118
    RESTRICT_type,//------------------------------119
    RETURN_type,  //------------------------------120
    SHORT_type,   //------------------------------121
    SIGNED_type,  //------------------------------122
    SIZEOF_type,  //------------------------------123
    STATIC_type,  //------------------------------124
    STRUCT_type,  //------------------------------125
    SWITCH_type,  //------------------------------126
    TYPEDEF_type, //------------------------------127
    UNION_type,   //------------------------------128
    UNSIGNED_type,//------------------------------129
    VOID_type,    //------------------------------130
    VOLATILE_type,//------------------------------131
    WHILE_type,   //------------------------------132
    ALIGNAS_type, //------------------------------133
    ALIGNOF_type, //------------------------------134
    ATOMIC_type,  //------------------------------135
    BOOL_type,    //------------------------------136
    COMPLEX_type, //------------------------------137
    NORETURN_type,//------------------------------138
    STATIC_ASSERT_type,//-------------------------139
    THREAD_LOCAL_type, //-------------------------140
    //FUNC_NAME_type,

    enum_type, //---------------------------------141
    enum_variable_type, //------------------------142

    function_name_type, //------------------------143    

};


#endif







