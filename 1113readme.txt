need taint, name:2.taint
before initialize compiler state
81818181: node_table:0x7ff7cebb7010
81818181: symbol_table:0x7ff7ceb36010
lib/compiler_state.c:151 0x157e250
after  initialize compiler state
================compiler_state start===================
c_file_str:2.c
symbol_max_number:65536
symbol_number:0
node_max_number:65536
node_number:0
need_dot_file:0 
need_taint_file:1 2.taint
start taint_source_information start:  ===================
line_num:4 name:a level:12
stop  taint_source_information strop   ===================
taint_num:1
need_infor:0
symbol_table:0x157e250
node_table:0x7ff7cebb7010
declaration_secifiers_table:0x157e250
================compiler_state end ====================
type_specifier: INT
!!!main
291:yylineno:2
check_identifier end
declaration_specifiers: type_specifier
direct_declarator: IDENTIFIER
direct_declarator: direct_declarator '(' ')'
stack: 1 0 
declarator: direct_declarator
type_specifier: INT
!!!a
291:yylineno:4
check_identifier end
declaration_specifiers: type_specifier
direct_declarator: IDENTIFIER
declarator: direct_declarator
!!!12
constant: I_CONSTANT
primary_expression: constant
postfix_expression: primary_expression
unary_expression: postfix_expression
cast_expression: unary_expression
multiplicative_expression: cast_expression
additive_expression: multiplicative_expression
shift_expression: additive_expression
relational_expression: shift_expression
equality_expression: relational_expression
and_expression: equality_expression
exclusive_or_expression: and_expression
inclusive_or_expression: exclusive_or_expression
logical_and_expression: inclusive_or_expression
logical_or_expression: logical_and_expression
conditional_expression: logical_or_expression
assignment_expression: conditional_expression
initializer: assignment_expression
init_declarator: declarator '=' initializer
init_declarator_list: init_declarator
declaration: declaration_specifiers init_declarator_list ';'
block_item: declaration
block_item_list: block_item
type_specifier: INT
!!!b
291:yylineno:5
check_identifier end
declaration_specifiers: type_specifier
direct_declarator: IDENTIFIER
declarator: direct_declarator
!!!13
constant: I_CONSTANT
primary_expression: constant
postfix_expression: primary_expression
unary_expression: postfix_expression
cast_expression: unary_expression
multiplicative_expression: cast_expression
additive_expression: multiplicative_expression
shift_expression: additive_expression
relational_expression: shift_expression
equality_expression: relational_expression
and_expression: equality_expression
exclusive_or_expression: and_expression
inclusive_or_expression: exclusive_or_expression
logical_and_expression: inclusive_or_expression
logical_or_expression: logical_and_expression
conditional_expression: logical_or_expression
assignment_expression: conditional_expression
initializer: assignment_expression
init_declarator: declarator '=' initializer
init_declarator_list: init_declarator
declaration: declaration_specifiers init_declarator_list ';'
block_item: declaration
block_item_list: block_item_list block_item
type_specifier: INT
!!!c
291:yylineno:6
check_identifier end
declaration_specifiers: type_specifier
direct_declarator: IDENTIFIER
declarator: direct_declarator
init_declarator: declarator
init_declarator_list: init_declarator
declaration: declaration_specifiers init_declarator_list ';'
block_item: declaration
block_item_list: block_item_list block_item
!!!c
291:yylineno:7
check_identifier end
primary_expression: IDENTIFIER
postfix_expression: primary_expression
unary_expression: postfix_expression
assignment_operator: '='
!!!a
291:yylineno:7
check_identifier end
primary_expression: IDENTIFIER
postfix_expression: primary_expression
unary_expression: postfix_expression
cast_expression: unary_expression
multiplicative_expression: cast_expression
additive_expression: multiplicative_expression
!!!b
291:yylineno:7
check_identifier end
primary_expression: IDENTIFIER
postfix_expression: primary_expression
unary_expression: postfix_expression
cast_expression: unary_expression
multiplicative_expression: cast_expression
additive_expression: additive_expression '+' multiplicative_expression
shift_expression: additive_expression
relational_expression: shift_expression
equality_expression: relational_expression
and_expression: equality_expression
exclusive_or_expression: and_expression
inclusive_or_expression: exclusive_or_expression
logical_and_expression: inclusive_or_expression
logical_or_expression: logical_and_expression
conditional_expression: logical_or_expression
assignment_expression: conditional_expression
assignment_expression: unary_expression assignment_operator assignment_expression
expression: assignment_expression
expression_statement: expression ';'
statement: expression_statement
block_item: statement
block_item_list: block_item_list block_item
type_specifier: INT
!!!m
291:yylineno:9
check_identifier end
declaration_specifiers: type_specifier
direct_declarator: IDENTIFIER
declarator: direct_declarator
!!!c
291:yylineno:9
check_identifier end
primary_expression: IDENTIFIER
postfix_expression: primary_expression
unary_expression: postfix_expression
cast_expression: unary_expression
multiplicative_expression: cast_expression
additive_expression: multiplicative_expression
!!!13
constant: I_CONSTANT
primary_expression: constant
postfix_expression: primary_expression
unary_expression: postfix_expression
cast_expression: unary_expression
multiplicative_expression: cast_expression
additive_expression: additive_expression '+' multiplicative_expression
shift_expression: additive_expression
relational_expression: shift_expression
equality_expression: relational_expression
and_expression: equality_expression
exclusive_or_expression: and_expression
inclusive_or_expression: exclusive_or_expression
logical_and_expression: inclusive_or_expression
logical_or_expression: logical_and_expression
conditional_expression: logical_or_expression
assignment_expression: conditional_expression
initializer: assignment_expression
init_declarator: declarator '=' initializer
init_declarator_list: init_declarator
declaration: declaration_specifiers init_declarator_list ';'
block_item: declaration
block_item_list: block_item_list block_item
type_specifier: INT
!!!n
291:yylineno:10
check_identifier end
declaration_specifiers: type_specifier
direct_declarator: IDENTIFIER
declarator: direct_declarator
!!!m
291:yylineno:10
check_identifier end
primary_expression: IDENTIFIER
postfix_expression: primary_expression
unary_expression: postfix_expression
cast_expression: unary_expression
multiplicative_expression: cast_expression
additive_expression: multiplicative_expression
!!!12
constant: I_CONSTANT
primary_expression: constant
postfix_expression: primary_expression
unary_expression: postfix_expression
cast_expression: unary_expression
multiplicative_expression: cast_expression
additive_expression: additive_expression '+' multiplicative_expression
shift_expression: additive_expression
relational_expression: shift_expression
equality_expression: relational_expression
and_expression: equality_expression
exclusive_or_expression: and_expression
inclusive_or_expression: exclusive_or_expression
logical_and_expression: inclusive_or_expression
logical_or_expression: logical_and_expression
conditional_expression: logical_or_expression
assignment_expression: conditional_expression
initializer: assignment_expression
init_declarator: declarator '=' initializer
init_declarator_list: init_declarator
declaration: declaration_specifiers init_declarator_list ';'
block_item: declaration
block_item_list: block_item_list block_item
stack: 0 
compound_statement(id:178): '{' block_item_list '}'
function_defination: declaration_specifiers declarator compound_statement
deal_type_specifier node_inrule_num 3
haha node_type 28
haha2 inrule_num:12
haha2 inrule_num:0
3949
IDENTIFIER: main node_type:49 node_inrule_num:-1 node_parent:3 node_parent_inrule_num:0 node_parent_type:28 node_brother_seq:0
0513a
infor_ptr->node_ptr=0x15d8420
infor_ptr->node_ptr=0x15d8420
infor_ptr->smbl_ptr=0x15d8440
infor_ptr->smbl_ptr=0x15d8440
3089
haha49
227a:177
111
333 0
222
0401 : is declaration
0318: 32
deal_type_specifier node_inrule_num 3
right!!!
haha node_type 28
haha2 inrule_num:0
3949
IDENTIFIER: a node_type:49 node_inrule_num:-1 node_parent:9 node_parent_inrule_num:0 node_parent_type:28 node_brother_seq:0
0513a
infor_ptr->node_ptr=0x15d85d0
infor_ptr->node_ptr=0x15d85d0
infor_ptr->smbl_ptr=0x15d85f0
infor_ptr->smbl_ptr=0x15d85f0
3089
haha49
node_index:29
888
node_index:29
999
0512xxx:symbol_a_table_num 1
1123: a a 0
333 1
0401 : is declaration
0318: 32
deal_type_specifier node_inrule_num 3
right!!!
haha node_type 28
haha2 inrule_num:0
3949
IDENTIFIER: b node_type:49 node_inrule_num:-1 node_parent:38 node_parent_inrule_num:0 node_parent_type:28 node_brother_seq:0
0513a
infor_ptr->node_ptr=0x15d87d0
infor_ptr->node_ptr=0x15d87d0
infor_ptr->smbl_ptr=0x15d87f0
infor_ptr->smbl_ptr=0x15d87f0
3089
haha49
node_index:58
888
node_index:58
999
0512xxx:symbol_a_table_num 2
1123: a b 0
333 2
0401 : is declaration
0318: 32
deal_type_specifier node_inrule_num 3
right!!!
haha node_type 28
haha2 inrule_num:0
3949
IDENTIFIER: c node_type:49 node_inrule_num:-1 node_parent:66 node_parent_inrule_num:0 node_parent_type:28 node_brother_seq:0
0513a
infor_ptr->node_ptr=0x15d89d0
infor_ptr->node_ptr=0x15d89d0
infor_ptr->smbl_ptr=0x15d89f0
infor_ptr->smbl_ptr=0x15d89f0
3089
haha49
0512xxx:symbol_a_table_num 3
1123: a c 0
333 3
0401 : is statement
deal_statement:1055 inrule_num:2 node_index:105
deal_expression_statement 0403
0513bb
3949
IDENTIFIER: c node_type:49 node_inrule_num:-1 node_parent:73 node_parent_inrule_num:0 node_parent_type:72 node_brother_seq:0
0513a
0513xxx
4161: 2
c
0512xxx
infor_ptr->node_ptr=0x15d8bc0
infor_ptr->node_ptr=0x15d8bc0
infor_ptr->smbl_ptr=0x15d8be0
infor_ptr->smbl_ptr=0x15d8be0
0513bb
3949
IDENTIFIER: a node_type:49 node_inrule_num:-1 node_parent:79 node_parent_inrule_num:0 node_parent_type:72 node_brother_seq:0
0513a
0513xxx
4161: 0
a
0512xxx
infor_ptr->node_ptr=0x15d8e70
infor_ptr->node_ptr=0x15d8e70
infor_ptr->smbl_ptr=0x15d8e90
infor_ptr->smbl_ptr=0x15d8e90
0513bb
3949
IDENTIFIER: b node_type:49 node_inrule_num:-1 node_parent:86 node_parent_inrule_num:0 node_parent_type:72 node_brother_seq:0
0513a
0513xxx
4161: 1
b
0512xxx
infor_ptr->node_ptr=0x15d8fa0
infor_ptr->node_ptr=0x15d8fa0
infor_ptr->smbl_ptr=0x15d8fc0
infor_ptr->smbl_ptr=0x15d8fc0

0515x1 1

0515x1 0
0518 expression_node_index:103
333 4
0401 : is declaration
0318: 32
deal_type_specifier node_inrule_num 3
right!!!
haha node_type 28
haha2 inrule_num:0
3949
IDENTIFIER: m node_type:49 node_inrule_num:-1 node_parent:110 node_parent_inrule_num:0 node_parent_type:28 node_brother_seq:0
0513a
infor_ptr->node_ptr=0x15d9130
infor_ptr->node_ptr=0x15d9130
infor_ptr->smbl_ptr=0x15d9150
infor_ptr->smbl_ptr=0x15d9150
3089
haha49
node_index:137
888
node_index:137
999
0512xxx:symbol_a_table_num 4
1123: a m 0
333 5
0401 : is declaration
0318: 32
deal_type_specifier node_inrule_num 3
right!!!
haha node_type 28
haha2 inrule_num:0
3949
IDENTIFIER: n node_type:49 node_inrule_num:-1 node_parent:145 node_parent_inrule_num:0 node_parent_type:28 node_brother_seq:0
0513a
infor_ptr->node_ptr=0x15d9330
infor_ptr->node_ptr=0x15d9330
infor_ptr->smbl_ptr=0x15d9350
infor_ptr->smbl_ptr=0x15d9350
3089
haha49
node_index:172
888
node_index:172
999
0512xxx:symbol_a_table_num 5
1123: a n 0
343b:0 block_item_num:6
0521r:0 57
701a:0
701a:1
343a:0
0521r:1 56
0521:aaa 0
0521abc:0
0515aa 0

0514a

0514b
0521r:2 55
01519
0521abc:1
0515aa 1

0514a

0514r1  1 0

0514c1 0

0514l1 0

0514a1 0

0514i1 0

0514e1 0

0514n1 0

0514q1 0

0514o1 0

0514t1 0
20150515b:0
20150515a:0
20150515b:1

0514v1

0514u1
0521r:3 55
01519

0514u2

0514u3

0514v2

0514u1
0521r:4 55
01519

0514u2

0514u3
0521r:5 49

0514t2

0514o2

0514q2

0514n2

0514e2

0514i2

0514a2

0514l2

0514c2

0514r2

0514c
0521r:6 11

0514c
0521:aaa
0521c: start_ins_index:end_ins_index  1:6
657a:1
external_declaration: function_definition
-------------------------translation_unit: external_declaration
----------print_node_table:
node_index node_parent node_child_num node_type_str node_symbol_index node_line_num node_compound_id
id(0):type(type_specifier_type[95]):index(0):parent(2):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(3):symbol_index([3]):infor_index(-1):line_num(2):compound_id(0):

id(1):type(IDENTIFIER_type[49]):index(1):parent(3):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(main[0]):infor_index(-1):line_num(2):compound_id(0):

id(2):type(declaration_specifiers_type[21]):index(2):parent(178):left_brother(-1):right_brother(5):brother_num(2):brother_seq(0):first_child(0):child_num(1):inrule_num(3):symbol_index([3]):infor_index(-1):line_num(2):compound_id(0):

id(3):type(direct_declarator_type[28]):index(3):parent(4):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(1):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(2):compound_id(0):

id(4):type(direct_declarator_type[28]):index(4):parent(5):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(3):child_num(1):inrule_num(12):symbol_index([12]):infor_index(-1):line_num(2):compound_id(0):

id(5):type(declarator_type[23]):index(5):parent(178):left_brother(2):right_brother(177):brother_num(3):brother_seq(1):first_child(4):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(3):compound_id(0):

id(6):type(type_specifier_type[95]):index(6):parent(8):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(3):symbol_index([3]):infor_index(-1):line_num(4):compound_id(177):

id(7):type(IDENTIFIER_type[49]):index(7):parent(9):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(a[1]):infor_index(-1):line_num(4):compound_id(177):

id(8):type(declaration_specifiers_type[21]):index(8):parent(32):left_brother(-1):right_brother(31):brother_num(2):brother_seq(0):first_child(6):child_num(1):inrule_num(3):symbol_index([3]):infor_index(-1):line_num(4):compound_id(177):

id(9):type(direct_declarator_type[28]):index(9):parent(10):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(7):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(10):type(declarator_type[23]):index(10):parent(30):left_brother(-1):right_brother(29):brother_num(2):brother_seq(0):first_child(9):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(4):compound_id(177):

id(11):type(I_CONSTANT_type[48]):index(11):parent(12):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(12[2]):infor_index(-1):line_num(4):compound_id(177):

id(12):type(constant_type[17]):index(12):parent(13):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(11):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(13):type(primary_expression_type[72]):index(13):parent(14):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(12):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(4):compound_id(177):

id(14):type(postfix_expression_type[71]):index(14):parent(15):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(13):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(15):type(unary_expression_type[96]):index(15):parent(16):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(14):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(16):type(cast_expression_type[13]):index(16):parent(17):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(15):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(17):type(multiplicative_expression_type[65]):index(17):parent(18):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(16):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(18):type(additive_expression_type[4]):index(18):parent(19):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(17):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(19):type(shift_expression_type[78]):index(19):parent(20):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(18):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(20):type(relational_expression_type[74]):index(20):parent(21):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(19):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(21):type(equality_expression_type[35]):index(21):parent(22):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(20):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(22):type(and_expression_type[6]):index(22):parent(23):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(21):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(23):type(exclusive_or_expression_type[36]):index(23):parent(24):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(22):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(24):type(inclusive_or_expression_type[52]):index(24):parent(25):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(23):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(25):type(logical_and_expression_type[61]):index(25):parent(26):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(24):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(26):type(logical_or_expression_type[62]):index(26):parent(27):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(25):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(27):type(conditional_expression_type[15]):index(27):parent(28):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(26):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(28):type(assignment_expression_type[8]):index(28):parent(29):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(27):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(29):type(initializer_type[56]):index(29):parent(30):left_brother(10):right_brother(-1):brother_num(2):brother_seq(1):first_child(28):child_num(1):inrule_num(2):symbol_index([2]):infor_index(-1):line_num(4):compound_id(177):

id(30):type(init_declarator_type[54]):index(30):parent(31):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(10):child_num(2):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(31):type(init_declarator_list_type[53]):index(31):parent(32):left_brother(8):right_brother(-1):brother_num(2):brother_seq(1):first_child(30):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(32):type(declaration_type[22]):index(32):parent(33):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(8):child_num(2):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(4):compound_id(177):

id(33):type(block_item_type[12]):index(33):parent(34):left_brother(-1):right_brother(62):brother_num(2):brother_seq(0):first_child(32):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(34):type(block_item_list_type[11]):index(34):parent(177):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(33):child_num(6):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(4):compound_id(177):

id(35):type(type_specifier_type[95]):index(35):parent(37):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(3):symbol_index([3]):infor_index(-1):line_num(5):compound_id(177):

id(36):type(IDENTIFIER_type[49]):index(36):parent(38):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(b[3]):infor_index(-1):line_num(5):compound_id(177):

id(37):type(declaration_specifiers_type[21]):index(37):parent(61):left_brother(-1):right_brother(60):brother_num(2):brother_seq(0):first_child(35):child_num(1):inrule_num(3):symbol_index([3]):infor_index(-1):line_num(5):compound_id(177):

id(38):type(direct_declarator_type[28]):index(38):parent(39):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(36):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(39):type(declarator_type[23]):index(39):parent(59):left_brother(-1):right_brother(58):brother_num(2):brother_seq(0):first_child(38):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(5):compound_id(177):

id(40):type(I_CONSTANT_type[48]):index(40):parent(41):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(13[4]):infor_index(-1):line_num(5):compound_id(177):

id(41):type(constant_type[17]):index(41):parent(42):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(40):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(42):type(primary_expression_type[72]):index(42):parent(43):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(41):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(5):compound_id(177):

id(43):type(postfix_expression_type[71]):index(43):parent(44):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(42):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(44):type(unary_expression_type[96]):index(44):parent(45):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(43):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(45):type(cast_expression_type[13]):index(45):parent(46):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(44):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(46):type(multiplicative_expression_type[65]):index(46):parent(47):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(45):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(47):type(additive_expression_type[4]):index(47):parent(48):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(46):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(48):type(shift_expression_type[78]):index(48):parent(49):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(47):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(49):type(relational_expression_type[74]):index(49):parent(50):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(48):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(50):type(equality_expression_type[35]):index(50):parent(51):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(49):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(51):type(and_expression_type[6]):index(51):parent(52):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(50):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(52):type(exclusive_or_expression_type[36]):index(52):parent(53):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(51):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(53):type(inclusive_or_expression_type[52]):index(53):parent(54):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(52):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(54):type(logical_and_expression_type[61]):index(54):parent(55):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(53):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(55):type(logical_or_expression_type[62]):index(55):parent(56):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(54):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(56):type(conditional_expression_type[15]):index(56):parent(57):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(55):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(57):type(assignment_expression_type[8]):index(57):parent(58):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(56):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(58):type(initializer_type[56]):index(58):parent(59):left_brother(39):right_brother(-1):brother_num(2):brother_seq(1):first_child(57):child_num(1):inrule_num(2):symbol_index([2]):infor_index(-1):line_num(5):compound_id(177):

id(59):type(init_declarator_type[54]):index(59):parent(60):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(39):child_num(2):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(60):type(init_declarator_list_type[53]):index(60):parent(61):left_brother(37):right_brother(-1):brother_num(2):brother_seq(1):first_child(59):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(61):type(declaration_type[22]):index(61):parent(62):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(37):child_num(2):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(5):compound_id(177):

id(62):type(block_item_type[12]):index(62):parent(34):left_brother(33):right_brother(71):brother_num(3):brother_seq(1):first_child(61):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(5):compound_id(177):

id(63):type(type_specifier_type[95]):index(63):parent(65):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(3):symbol_index([3]):infor_index(-1):line_num(6):compound_id(177):

id(64):type(IDENTIFIER_type[49]):index(64):parent(66):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(c[5]):infor_index(-1):line_num(6):compound_id(177):

id(65):type(declaration_specifiers_type[21]):index(65):parent(70):left_brother(-1):right_brother(69):brother_num(2):brother_seq(0):first_child(63):child_num(1):inrule_num(3):symbol_index([3]):infor_index(-1):line_num(6):compound_id(177):

id(66):type(direct_declarator_type[28]):index(66):parent(67):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(64):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(6):compound_id(177):

id(67):type(declarator_type[23]):index(67):parent(68):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(66):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(6):compound_id(177):

id(68):type(init_declarator_type[54]):index(68):parent(69):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(67):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(6):compound_id(177):

id(69):type(init_declarator_list_type[53]):index(69):parent(70):left_brother(65):right_brother(-1):brother_num(2):brother_seq(1):first_child(68):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(6):compound_id(177):

id(70):type(declaration_type[22]):index(70):parent(71):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(65):child_num(2):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(6):compound_id(177):

id(71):type(block_item_type[12]):index(71):parent(34):left_brother(62):right_brother(106):brother_num(4):brother_seq(2):first_child(70):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(6):compound_id(177):

id(72):type(IDENTIFIER_type[49]):index(72):parent(73):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(c[6]):infor_index(-1):line_num(7):compound_id(177):

id(73):type(primary_expression_type[72]):index(73):parent(74):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(72):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(74):type(postfix_expression_type[71]):index(74):parent(75):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(73):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(75):type(unary_expression_type[96]):index(75):parent(102):left_brother(-1):right_brother(77):brother_num(2):brother_seq(0):first_child(74):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(76):type(EQU_ASSIGN_type[30]):index(76):parent(77):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index([-1]):infor_index(-1):line_num(7):compound_id(177):

id(77):type(assignment_operator_type[9]):index(77):parent(102):left_brother(75):right_brother(101):brother_num(3):brother_seq(1):first_child(76):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(78):type(IDENTIFIER_type[49]):index(78):parent(79):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(a[7]):infor_index(-1):line_num(7):compound_id(177):

id(79):type(primary_expression_type[72]):index(79):parent(80):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(78):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(80):type(postfix_expression_type[71]):index(80):parent(81):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(79):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(81):type(unary_expression_type[96]):index(81):parent(82):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(80):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(82):type(cast_expression_type[13]):index(82):parent(83):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(81):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(83):type(multiplicative_expression_type[65]):index(83):parent(84):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(82):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(84):type(additive_expression_type[4]):index(84):parent(91):left_brother(-1):right_brother(90):brother_num(2):brother_seq(0):first_child(83):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(85):type(IDENTIFIER_type[49]):index(85):parent(86):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(b[8]):infor_index(-1):line_num(7):compound_id(177):

id(86):type(primary_expression_type[72]):index(86):parent(87):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(85):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(87):type(postfix_expression_type[71]):index(87):parent(88):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(86):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(88):type(unary_expression_type[96]):index(88):parent(89):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(87):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(89):type(cast_expression_type[13]):index(89):parent(90):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(88):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(90):type(multiplicative_expression_type[65]):index(90):parent(91):left_brother(84):right_brother(-1):brother_num(2):brother_seq(1):first_child(89):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(91):type(additive_expression_type[4]):index(91):parent(92):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(84):child_num(2):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(7):compound_id(177):

id(92):type(shift_expression_type[78]):index(92):parent(93):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(91):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(93):type(relational_expression_type[74]):index(93):parent(94):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(92):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(94):type(equality_expression_type[35]):index(94):parent(95):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(93):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(95):type(and_expression_type[6]):index(95):parent(96):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(94):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(96):type(exclusive_or_expression_type[36]):index(96):parent(97):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(95):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(97):type(inclusive_or_expression_type[52]):index(97):parent(98):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(96):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(98):type(logical_and_expression_type[61]):index(98):parent(99):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(97):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(99):type(logical_or_expression_type[62]):index(99):parent(100):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(98):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(100):type(conditional_expression_type[15]):index(100):parent(101):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(99):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(101):type(assignment_expression_type[8]):index(101):parent(102):left_brother(77):right_brother(-1):brother_num(3):brother_seq(2):first_child(100):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(102):type(assignment_expression_type[8]):index(102):parent(103):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(75):child_num(3):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(7):compound_id(177):

id(103):type(expression_type[38]):index(103):parent(104):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(102):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(7):compound_id(177):

id(104):type(expression_statement_type[37]):index(104):parent(105):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(103):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(7):compound_id(177):

id(105):type(statement_type[80]):index(105):parent(106):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(104):child_num(1):inrule_num(2):symbol_index([2]):infor_index(-1):line_num(7):compound_id(177):

id(106):type(block_item_type[12]):index(106):parent(34):left_brother(71):right_brother(141):brother_num(5):brother_seq(3):first_child(105):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(7):compound_id(177):

id(107):type(type_specifier_type[95]):index(107):parent(109):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(3):symbol_index([3]):infor_index(-1):line_num(9):compound_id(177):

id(108):type(IDENTIFIER_type[49]):index(108):parent(110):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(m[9]):infor_index(-1):line_num(9):compound_id(177):

id(109):type(declaration_specifiers_type[21]):index(109):parent(140):left_brother(-1):right_brother(139):brother_num(2):brother_seq(0):first_child(107):child_num(1):inrule_num(3):symbol_index([3]):infor_index(-1):line_num(9):compound_id(177):

id(110):type(direct_declarator_type[28]):index(110):parent(111):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(108):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(111):type(declarator_type[23]):index(111):parent(138):left_brother(-1):right_brother(137):brother_num(2):brother_seq(0):first_child(110):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(9):compound_id(177):

id(112):type(IDENTIFIER_type[49]):index(112):parent(113):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(c[10]):infor_index(-1):line_num(9):compound_id(177):

id(113):type(primary_expression_type[72]):index(113):parent(114):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(112):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(114):type(postfix_expression_type[71]):index(114):parent(115):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(113):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(115):type(unary_expression_type[96]):index(115):parent(116):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(114):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(116):type(cast_expression_type[13]):index(116):parent(117):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(115):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(117):type(multiplicative_expression_type[65]):index(117):parent(118):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(116):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(118):type(additive_expression_type[4]):index(118):parent(126):left_brother(-1):right_brother(125):brother_num(2):brother_seq(0):first_child(117):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(119):type(I_CONSTANT_type[48]):index(119):parent(120):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(13[11]):infor_index(-1):line_num(9):compound_id(177):

id(120):type(constant_type[17]):index(120):parent(121):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(119):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(121):type(primary_expression_type[72]):index(121):parent(122):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(120):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(9):compound_id(177):

id(122):type(postfix_expression_type[71]):index(122):parent(123):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(121):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(123):type(unary_expression_type[96]):index(123):parent(124):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(122):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(124):type(cast_expression_type[13]):index(124):parent(125):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(123):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(125):type(multiplicative_expression_type[65]):index(125):parent(126):left_brother(118):right_brother(-1):brother_num(2):brother_seq(1):first_child(124):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(126):type(additive_expression_type[4]):index(126):parent(127):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(118):child_num(2):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(9):compound_id(177):

id(127):type(shift_expression_type[78]):index(127):parent(128):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(126):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(128):type(relational_expression_type[74]):index(128):parent(129):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(127):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(129):type(equality_expression_type[35]):index(129):parent(130):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(128):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(130):type(and_expression_type[6]):index(130):parent(131):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(129):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(131):type(exclusive_or_expression_type[36]):index(131):parent(132):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(130):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(132):type(inclusive_or_expression_type[52]):index(132):parent(133):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(131):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(133):type(logical_and_expression_type[61]):index(133):parent(134):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(132):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(134):type(logical_or_expression_type[62]):index(134):parent(135):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(133):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(135):type(conditional_expression_type[15]):index(135):parent(136):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(134):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(136):type(assignment_expression_type[8]):index(136):parent(137):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(135):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(137):type(initializer_type[56]):index(137):parent(138):left_brother(111):right_brother(-1):brother_num(2):brother_seq(1):first_child(136):child_num(1):inrule_num(2):symbol_index([2]):infor_index(-1):line_num(9):compound_id(177):

id(138):type(init_declarator_type[54]):index(138):parent(139):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(111):child_num(2):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(139):type(init_declarator_list_type[53]):index(139):parent(140):left_brother(109):right_brother(-1):brother_num(2):brother_seq(1):first_child(138):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(140):type(declaration_type[22]):index(140):parent(141):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(109):child_num(2):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(9):compound_id(177):

id(141):type(block_item_type[12]):index(141):parent(34):left_brother(106):right_brother(176):brother_num(6):brother_seq(4):first_child(140):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(9):compound_id(177):

id(142):type(type_specifier_type[95]):index(142):parent(144):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(3):symbol_index([3]):infor_index(-1):line_num(10):compound_id(177):

id(143):type(IDENTIFIER_type[49]):index(143):parent(145):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(n[12]):infor_index(-1):line_num(10):compound_id(177):

id(144):type(declaration_specifiers_type[21]):index(144):parent(175):left_brother(-1):right_brother(174):brother_num(2):brother_seq(0):first_child(142):child_num(1):inrule_num(3):symbol_index([3]):infor_index(-1):line_num(10):compound_id(177):

id(145):type(direct_declarator_type[28]):index(145):parent(146):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(143):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(146):type(declarator_type[23]):index(146):parent(173):left_brother(-1):right_brother(172):brother_num(2):brother_seq(0):first_child(145):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(10):compound_id(177):

id(147):type(IDENTIFIER_type[49]):index(147):parent(148):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(m[13]):infor_index(-1):line_num(10):compound_id(177):

id(148):type(primary_expression_type[72]):index(148):parent(149):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(147):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(149):type(postfix_expression_type[71]):index(149):parent(150):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(148):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(150):type(unary_expression_type[96]):index(150):parent(151):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(149):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(151):type(cast_expression_type[13]):index(151):parent(152):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(150):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(152):type(multiplicative_expression_type[65]):index(152):parent(153):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(151):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(153):type(additive_expression_type[4]):index(153):parent(161):left_brother(-1):right_brother(160):brother_num(2):brother_seq(0):first_child(152):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(154):type(I_CONSTANT_type[48]):index(154):parent(155):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(-1):child_num(0):inrule_num(-1):symbol_index(12[14]):infor_index(-1):line_num(10):compound_id(177):

id(155):type(constant_type[17]):index(155):parent(156):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(154):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(156):type(primary_expression_type[72]):index(156):parent(157):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(155):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(10):compound_id(177):

id(157):type(postfix_expression_type[71]):index(157):parent(158):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(156):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(158):type(unary_expression_type[96]):index(158):parent(159):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(157):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(159):type(cast_expression_type[13]):index(159):parent(160):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(158):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(160):type(multiplicative_expression_type[65]):index(160):parent(161):left_brother(153):right_brother(-1):brother_num(2):brother_seq(1):first_child(159):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(161):type(additive_expression_type[4]):index(161):parent(162):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(153):child_num(2):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(10):compound_id(177):

id(162):type(shift_expression_type[78]):index(162):parent(163):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(161):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(163):type(relational_expression_type[74]):index(163):parent(164):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(162):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(164):type(equality_expression_type[35]):index(164):parent(165):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(163):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(165):type(and_expression_type[6]):index(165):parent(166):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(164):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(166):type(exclusive_or_expression_type[36]):index(166):parent(167):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(165):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(167):type(inclusive_or_expression_type[52]):index(167):parent(168):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(166):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(168):type(logical_and_expression_type[61]):index(168):parent(169):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(167):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(169):type(logical_or_expression_type[62]):index(169):parent(170):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(168):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(170):type(conditional_expression_type[15]):index(170):parent(171):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(169):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(171):type(assignment_expression_type[8]):index(171):parent(172):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(170):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(172):type(initializer_type[56]):index(172):parent(173):left_brother(146):right_brother(-1):brother_num(2):brother_seq(1):first_child(171):child_num(1):inrule_num(2):symbol_index([2]):infor_index(-1):line_num(10):compound_id(177):

id(173):type(init_declarator_type[54]):index(173):parent(174):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(146):child_num(2):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(174):type(init_declarator_list_type[53]):index(174):parent(175):left_brother(144):right_brother(-1):brother_num(2):brother_seq(1):first_child(173):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(175):type(declaration_type[22]):index(175):parent(176):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(144):child_num(2):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(10):compound_id(177):

id(176):type(block_item_type[12]):index(176):parent(34):left_brother(141):right_brother(-1):brother_num(6):brother_seq(5):first_child(175):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(10):compound_id(177):

id(177):type(compound_statement_type[14]):index(177):parent(178):left_brother(5):right_brother(-1):brother_num(3):brother_seq(2):first_child(34):child_num(1):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(12):compound_id(177):

id(178):type(function_definition_type[42]):index(178):parent(179):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(2):child_num(3):inrule_num(1):symbol_index([1]):infor_index(-1):line_num(12):compound_id(0):

id(179):type(external_declaration_type[39]):index(179):parent(180):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(178):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(12):compound_id(0):

id(180):type(translation_unit_type[91]):index(180):parent(-1):left_brother(-1):right_brother(-1):brother_num(1):brother_seq(0):first_child(179):child_num(1):inrule_num(0):symbol_index([0]):infor_index(-1):line_num(12):compound_id(0):

----------print_node_table!
+translation_unit_type node_id:180 child_number:1 inrule_num:0 line_num:12
 +external_declaration_type node_id:179 child_number:1 inrule_num:0 line_num:12
  +function_definition_type node_id:178 child_number:3 inrule_num:1 line_num:12
   +declaration_specifiers_type node_id:2 child_number:1 inrule_num:3 line_num:2
    +type_specifier_type node_id:0 child_number:0 inrule_num:3 line_num:2
   +declarator_type node_id:5 child_number:1 inrule_num:1 line_num:3
    +direct_declarator_type node_id:4 child_number:1 inrule_num:12 line_num:2
     +direct_declarator_type node_id:3 child_number:1 inrule_num:0 line_num:2
      +IDENTIFIER_type node_id:1 child_number:0 inrule_num:-1 line_num:2
   +compound_statement_type node_id:177 child_number:1 inrule_num:1 line_num:12
    +block_item_list_type node_id:34 child_number:6 inrule_num:0 line_num:4
     +block_item_type node_id:33 child_number:1 inrule_num:0 line_num:4
      +declaration_type node_id:32 child_number:2 inrule_num:1 line_num:4
       +declaration_specifiers_type node_id:8 child_number:1 inrule_num:3 line_num:4
        +type_specifier_type node_id:6 child_number:0 inrule_num:3 line_num:4
       +init_declarator_list_type node_id:31 child_number:1 inrule_num:0 line_num:4
        +init_declarator_type node_id:30 child_number:2 inrule_num:0 line_num:4
         +declarator_type node_id:10 child_number:1 inrule_num:1 line_num:4
          +direct_declarator_type node_id:9 child_number:1 inrule_num:0 line_num:4
           +IDENTIFIER_type node_id:7 child_number:0 inrule_num:-1 line_num:4
         +initializer_type node_id:29 child_number:1 inrule_num:2 line_num:4
          +assignment_expression_type node_id:28 child_number:1 inrule_num:0 line_num:4
           +conditional_expression_type node_id:27 child_number:1 inrule_num:0 line_num:4
            +logical_or_expression_type node_id:26 child_number:1 inrule_num:0 line_num:4
             +logical_and_expression_type node_id:25 child_number:1 inrule_num:0 line_num:4
              +inclusive_or_expression_type node_id:24 child_number:1 inrule_num:0 line_num:4
               +exclusive_or_expression_type node_id:23 child_number:1 inrule_num:0 line_num:4
                +and_expression_type node_id:22 child_number:1 inrule_num:0 line_num:4
                 +equality_expression_type node_id:21 child_number:1 inrule_num:0 line_num:4
                  +relational_expression_type node_id:20 child_number:1 inrule_num:0 line_num:4
                   +shift_expression_type node_id:19 child_number:1 inrule_num:0 line_num:4
                    +additive_expression_type node_id:18 child_number:1 inrule_num:0 line_num:4
                     +multiplicative_expression_type node_id:17 child_number:1 inrule_num:0 line_num:4
                      +cast_expression_type node_id:16 child_number:1 inrule_num:0 line_num:4
                       +unary_expression_type node_id:15 child_number:1 inrule_num:0 line_num:4
                        +postfix_expression_type node_id:14 child_number:1 inrule_num:0 line_num:4
                         +primary_expression_type node_id:13 child_number:1 inrule_num:1 line_num:4
                          +constant_type node_id:12 child_number:1 inrule_num:0 line_num:4
                           +I_CONSTANT_type node_id:11 child_number:0 inrule_num:-1 line_num:4
     +block_item_type node_id:62 child_number:1 inrule_num:0 line_num:5
      +declaration_type node_id:61 child_number:2 inrule_num:1 line_num:5
       +declaration_specifiers_type node_id:37 child_number:1 inrule_num:3 line_num:5
        +type_specifier_type node_id:35 child_number:0 inrule_num:3 line_num:5
       +init_declarator_list_type node_id:60 child_number:1 inrule_num:0 line_num:5
        +init_declarator_type node_id:59 child_number:2 inrule_num:0 line_num:5
         +declarator_type node_id:39 child_number:1 inrule_num:1 line_num:5
          +direct_declarator_type node_id:38 child_number:1 inrule_num:0 line_num:5
           +IDENTIFIER_type node_id:36 child_number:0 inrule_num:-1 line_num:5
         +initializer_type node_id:58 child_number:1 inrule_num:2 line_num:5
          +assignment_expression_type node_id:57 child_number:1 inrule_num:0 line_num:5
           +conditional_expression_type node_id:56 child_number:1 inrule_num:0 line_num:5
            +logical_or_expression_type node_id:55 child_number:1 inrule_num:0 line_num:5
             +logical_and_expression_type node_id:54 child_number:1 inrule_num:0 line_num:5
              +inclusive_or_expression_type node_id:53 child_number:1 inrule_num:0 line_num:5
               +exclusive_or_expression_type node_id:52 child_number:1 inrule_num:0 line_num:5
                +and_expression_type node_id:51 child_number:1 inrule_num:0 line_num:5
                 +equality_expression_type node_id:50 child_number:1 inrule_num:0 line_num:5
                  +relational_expression_type node_id:49 child_number:1 inrule_num:0 line_num:5
                   +shift_expression_type node_id:48 child_number:1 inrule_num:0 line_num:5
                    +additive_expression_type node_id:47 child_number:1 inrule_num:0 line_num:5
                     +multiplicative_expression_type node_id:46 child_number:1 inrule_num:0 line_num:5
                      +cast_expression_type node_id:45 child_number:1 inrule_num:0 line_num:5
                       +unary_expression_type node_id:44 child_number:1 inrule_num:0 line_num:5
                        +postfix_expression_type node_id:43 child_number:1 inrule_num:0 line_num:5
                         +primary_expression_type node_id:42 child_number:1 inrule_num:1 line_num:5
                          +constant_type node_id:41 child_number:1 inrule_num:0 line_num:5
                           +I_CONSTANT_type node_id:40 child_number:0 inrule_num:-1 line_num:5
     +block_item_type node_id:71 child_number:1 inrule_num:0 line_num:6
      +declaration_type node_id:70 child_number:2 inrule_num:1 line_num:6
       +declaration_specifiers_type node_id:65 child_number:1 inrule_num:3 line_num:6
        +type_specifier_type node_id:63 child_number:0 inrule_num:3 line_num:6
       +init_declarator_list_type node_id:69 child_number:1 inrule_num:0 line_num:6
        +init_declarator_type node_id:68 child_number:1 inrule_num:1 line_num:6
         +declarator_type node_id:67 child_number:1 inrule_num:1 line_num:6
          +direct_declarator_type node_id:66 child_number:1 inrule_num:0 line_num:6
           +IDENTIFIER_type node_id:64 child_number:0 inrule_num:-1 line_num:6
     +block_item_type node_id:106 child_number:1 inrule_num:1 line_num:7
      +statement_type node_id:105 child_number:1 inrule_num:2 line_num:7
       +expression_statement_type node_id:104 child_number:1 inrule_num:1 line_num:7
        +expression_type node_id:103 child_number:1 inrule_num:0 line_num:7
         +assignment_expression_type node_id:102 child_number:3 inrule_num:1 line_num:7
          +unary_expression_type node_id:75 child_number:1 inrule_num:0 line_num:7
           +postfix_expression_type node_id:74 child_number:1 inrule_num:0 line_num:7
            +primary_expression_type node_id:73 child_number:1 inrule_num:0 line_num:7
             +IDENTIFIER_type node_id:72 child_number:0 inrule_num:-1 line_num:7
          +assignment_operator_type node_id:77 child_number:1 inrule_num:0 line_num:7
           +EQU_ASSIGN_type node_id:76 child_number:0 inrule_num:-1 line_num:7
          +assignment_expression_type node_id:101 child_number:1 inrule_num:0 line_num:7
           +conditional_expression_type node_id:100 child_number:1 inrule_num:0 line_num:7
            +logical_or_expression_type node_id:99 child_number:1 inrule_num:0 line_num:7
             +logical_and_expression_type node_id:98 child_number:1 inrule_num:0 line_num:7
              +inclusive_or_expression_type node_id:97 child_number:1 inrule_num:0 line_num:7
               +exclusive_or_expression_type node_id:96 child_number:1 inrule_num:0 line_num:7
                +and_expression_type node_id:95 child_number:1 inrule_num:0 line_num:7
                 +equality_expression_type node_id:94 child_number:1 inrule_num:0 line_num:7
                  +relational_expression_type node_id:93 child_number:1 inrule_num:0 line_num:7
                   +shift_expression_type node_id:92 child_number:1 inrule_num:0 line_num:7
                    +additive_expression_type node_id:91 child_number:2 inrule_num:1 line_num:7
                     +additive_expression_type node_id:84 child_number:1 inrule_num:0 line_num:7
                      +multiplicative_expression_type node_id:83 child_number:1 inrule_num:0 line_num:7
                       +cast_expression_type node_id:82 child_number:1 inrule_num:0 line_num:7
                        +unary_expression_type node_id:81 child_number:1 inrule_num:0 line_num:7
                         +postfix_expression_type node_id:80 child_number:1 inrule_num:0 line_num:7
                          +primary_expression_type node_id:79 child_number:1 inrule_num:0 line_num:7
                           +IDENTIFIER_type node_id:78 child_number:0 inrule_num:-1 line_num:7
                     +multiplicative_expression_type node_id:90 child_number:1 inrule_num:0 line_num:7
                      +cast_expression_type node_id:89 child_number:1 inrule_num:0 line_num:7
                       +unary_expression_type node_id:88 child_number:1 inrule_num:0 line_num:7
                        +postfix_expression_type node_id:87 child_number:1 inrule_num:0 line_num:7
                         +primary_expression_type node_id:86 child_number:1 inrule_num:0 line_num:7
                          +IDENTIFIER_type node_id:85 child_number:0 inrule_num:-1 line_num:7
     +block_item_type node_id:141 child_number:1 inrule_num:0 line_num:9
      +declaration_type node_id:140 child_number:2 inrule_num:1 line_num:9
       +declaration_specifiers_type node_id:109 child_number:1 inrule_num:3 line_num:9
        +type_specifier_type node_id:107 child_number:0 inrule_num:3 line_num:9
       +init_declarator_list_type node_id:139 child_number:1 inrule_num:0 line_num:9
        +init_declarator_type node_id:138 child_number:2 inrule_num:0 line_num:9
         +declarator_type node_id:111 child_number:1 inrule_num:1 line_num:9
          +direct_declarator_type node_id:110 child_number:1 inrule_num:0 line_num:9
           +IDENTIFIER_type node_id:108 child_number:0 inrule_num:-1 line_num:9
         +initializer_type node_id:137 child_number:1 inrule_num:2 line_num:9
          +assignment_expression_type node_id:136 child_number:1 inrule_num:0 line_num:9
           +conditional_expression_type node_id:135 child_number:1 inrule_num:0 line_num:9
            +logical_or_expression_type node_id:134 child_number:1 inrule_num:0 line_num:9
             +logical_and_expression_type node_id:133 child_number:1 inrule_num:0 line_num:9
              +inclusive_or_expression_type node_id:132 child_number:1 inrule_num:0 line_num:9
               +exclusive_or_expression_type node_id:131 child_number:1 inrule_num:0 line_num:9
                +and_expression_type node_id:130 child_number:1 inrule_num:0 line_num:9
                 +equality_expression_type node_id:129 child_number:1 inrule_num:0 line_num:9
                  +relational_expression_type node_id:128 child_number:1 inrule_num:0 line_num:9
                   +shift_expression_type node_id:127 child_number:1 inrule_num:0 line_num:9
                    +additive_expression_type node_id:126 child_number:2 inrule_num:1 line_num:9
                     +additive_expression_type node_id:118 child_number:1 inrule_num:0 line_num:9
                      +multiplicative_expression_type node_id:117 child_number:1 inrule_num:0 line_num:9
                       +cast_expression_type node_id:116 child_number:1 inrule_num:0 line_num:9
                        +unary_expression_type node_id:115 child_number:1 inrule_num:0 line_num:9
                         +postfix_expression_type node_id:114 child_number:1 inrule_num:0 line_num:9
                          +primary_expression_type node_id:113 child_number:1 inrule_num:0 line_num:9
                           +IDENTIFIER_type node_id:112 child_number:0 inrule_num:-1 line_num:9
                     +multiplicative_expression_type node_id:125 child_number:1 inrule_num:0 line_num:9
                      +cast_expression_type node_id:124 child_number:1 inrule_num:0 line_num:9
                       +unary_expression_type node_id:123 child_number:1 inrule_num:0 line_num:9
                        +postfix_expression_type node_id:122 child_number:1 inrule_num:0 line_num:9
                         +primary_expression_type node_id:121 child_number:1 inrule_num:1 line_num:9
                          +constant_type node_id:120 child_number:1 inrule_num:0 line_num:9
                           +I_CONSTANT_type node_id:119 child_number:0 inrule_num:-1 line_num:9
     +block_item_type node_id:176 child_number:1 inrule_num:0 line_num:10
      +declaration_type node_id:175 child_number:2 inrule_num:1 line_num:10
       +declaration_specifiers_type node_id:144 child_number:1 inrule_num:3 line_num:10
        +type_specifier_type node_id:142 child_number:0 inrule_num:3 line_num:10
       +init_declarator_list_type node_id:174 child_number:1 inrule_num:0 line_num:10
        +init_declarator_type node_id:173 child_number:2 inrule_num:0 line_num:10
         +declarator_type node_id:146 child_number:1 inrule_num:1 line_num:10
          +direct_declarator_type node_id:145 child_number:1 inrule_num:0 line_num:10
           +IDENTIFIER_type node_id:143 child_number:0 inrule_num:-1 line_num:10
         +initializer_type node_id:172 child_number:1 inrule_num:2 line_num:10
          +assignment_expression_type node_id:171 child_number:1 inrule_num:0 line_num:10
           +conditional_expression_type node_id:170 child_number:1 inrule_num:0 line_num:10
            +logical_or_expression_type node_id:169 child_number:1 inrule_num:0 line_num:10
             +logical_and_expression_type node_id:168 child_number:1 inrule_num:0 line_num:10
              +inclusive_or_expression_type node_id:167 child_number:1 inrule_num:0 line_num:10
               +exclusive_or_expression_type node_id:166 child_number:1 inrule_num:0 line_num:10
                +and_expression_type node_id:165 child_number:1 inrule_num:0 line_num:10
                 +equality_expression_type node_id:164 child_number:1 inrule_num:0 line_num:10
                  +relational_expression_type node_id:163 child_number:1 inrule_num:0 line_num:10
                   +shift_expression_type node_id:162 child_number:1 inrule_num:0 line_num:10
                    +additive_expression_type node_id:161 child_number:2 inrule_num:1 line_num:10
                     +additive_expression_type node_id:153 child_number:1 inrule_num:0 line_num:10
                      +multiplicative_expression_type node_id:152 child_number:1 inrule_num:0 line_num:10
                       +cast_expression_type node_id:151 child_number:1 inrule_num:0 line_num:10
                        +unary_expression_type node_id:150 child_number:1 inrule_num:0 line_num:10
                         +postfix_expression_type node_id:149 child_number:1 inrule_num:0 line_num:10
                          +primary_expression_type node_id:148 child_number:1 inrule_num:0 line_num:10
                           +IDENTIFIER_type node_id:147 child_number:0 inrule_num:-1 line_num:10
                     +multiplicative_expression_type node_id:160 child_number:1 inrule_num:0 line_num:10
                      +cast_expression_type node_id:159 child_number:1 inrule_num:0 line_num:10
                       +unary_expression_type node_id:158 child_number:1 inrule_num:0 line_num:10
                        +postfix_expression_type node_id:157 child_number:1 inrule_num:0 line_num:10
                         +primary_expression_type node_id:156 child_number:1 inrule_num:1 line_num:10
                          +constant_type node_id:155 child_number:1 inrule_num:0 line_num:10
                           +I_CONSTANT_type node_id:154 child_number:0 inrule_num:-1 line_num:10
---------------------symbol_table:
id(0):name(main):name_len(4):type(not_know_type[0]):file((null)):file_len(0):line_num:(2):in_which_node(1):
id(1):name(a):name_len(1):type(not_know_type[0]):file((null)):file_len(0):line_num:(4):in_which_node(7):
id(2):name(12):name_len(2):type(I_CONSTANT_type[48]):file((null)):file_len(0):line_num:(4):in_which_node(11):
id(3):name(b):name_len(1):type(not_know_type[0]):file((null)):file_len(0):line_num:(5):in_which_node(36):
id(4):name(13):name_len(2):type(I_CONSTANT_type[48]):file((null)):file_len(0):line_num:(5):in_which_node(40):
id(5):name(c):name_len(1):type(not_know_type[0]):file((null)):file_len(0):line_num:(6):in_which_node(64):
id(6):name(c):name_len(1):type(not_know_type[0]):file((null)):file_len(0):line_num:(7):in_which_node(72):
id(7):name(a):name_len(1):type(not_know_type[0]):file((null)):file_len(0):line_num:(7):in_which_node(78):
id(8):name(b):name_len(1):type(not_know_type[0]):file((null)):file_len(0):line_num:(7):in_which_node(85):
id(9):name(m):name_len(1):type(not_know_type[0]):file((null)):file_len(0):line_num:(9):in_which_node(108):
id(10):name(c):name_len(1):type(not_know_type[0]):file((null)):file_len(0):line_num:(9):in_which_node(112):
id(11):name(13):name_len(2):type(I_CONSTANT_type[48]):file((null)):file_len(0):line_num:(9):in_which_node(119):
id(12):name(n):name_len(1):type(not_know_type[0]):file((null)):file_len(0):line_num:(10):in_which_node(143):
id(13):name(m):name_len(1):type(not_know_type[0]):file((null)):file_len(0):line_num:(10):in_which_node(147):
id(14):name(12):name_len(2):type(I_CONSTANT_type[48]):file((null)):file_len(0):line_num:(10):in_which_node(154):
---------------------symbol_table!
1 has father 0
stack: 0 


============================================
= print declaration_specifiers_table       =
============================================
declaration_specifiers_table[0] start
index:0
storage_class_specifier none(0x00000000)
type_specifier(0x00000003): signed default int index(0)
type_qualifier(0x00000000): 
function_specifier(0x00000000): 
declaration_specifiers_table[0] end
--------------------------------------------
declaration_specifiers_table[1] start
index:1
storage_class_specifier none(0x00000000)
type_specifier(0x00000003): signed default int index(0)
type_qualifier(0x00000000): 
function_specifier(0x00000000): 
declaration_specifiers_table[1] end
--------------------------------------------
declaration_specifiers_table[2] start
index:2
storage_class_specifier none(0x00000000)
type_specifier(0x00000003): signed default int index(0)
type_qualifier(0x00000000): 
function_specifier(0x00000000): 
declaration_specifiers_table[2] end
--------------------------------------------
declaration_specifiers_table[3] start
index:3
storage_class_specifier none(0x00000000)
type_specifier(0x00000003): signed default int index(0)
type_qualifier(0x00000000): 
function_specifier(0x00000000): 
declaration_specifiers_table[3] end
--------------------------------------------
declaration_specifiers_table[4] start
index:4
storage_class_specifier none(0x00000000)
type_specifier(0x00000003): signed default int index(0)
type_qualifier(0x00000000): 
function_specifier(0x00000000): 
declaration_specifiers_table[4] end
--------------------------------------------
declaration_specifiers_table[5] start
index:5
storage_class_specifier none(0x00000000)
type_specifier(0x00000003): signed default int index(0)
type_qualifier(0x00000000): 
function_specifier(0x00000000): 
declaration_specifiers_table[5] end
--------------------------------------------






============================================
= declarator_table                         =
============================================
declarator_table_num:6
--------------------------------------------
index:0 node_index:5 pointer_index:-1 direct_declarator_index:0
--------------------------------------------
index:1 node_index:10 pointer_index:-1 direct_declarator_index:1
--------------------------------------------
index:2 node_index:39 pointer_index:-1 direct_declarator_index:2
--------------------------------------------
index:3 node_index:67 pointer_index:-1 direct_declarator_index:3
--------------------------------------------
index:4 node_index:111 pointer_index:-1 direct_declarator_index:4
--------------------------------------------
index:5 node_index:146 pointer_index:-1 direct_declarator_index:5
--------------------------------------------
--------------------------------------------



============================================
= print direct_declarator_table            =
============================================
index:0
is_IDENTIFIER:0
node_index:-1
number:2
0. category:12 index1:0 index2:0
1. category:0 index1:0 index2:0
--------------------------------------------
index:1
is_IDENTIFIER:0
node_index:-1
number:1
0. category:0 index1:1 index2:0
--------------------------------------------
index:2
is_IDENTIFIER:0
node_index:-1
number:1
0. category:0 index1:2 index2:0
--------------------------------------------
index:3
is_IDENTIFIER:0
node_index:-1
number:1
0. category:0 index1:3 index2:0
--------------------------------------------
index:4
is_IDENTIFIER:0
node_index:-1
number:1
0. category:0 index1:7 index2:0
--------------------------------------------
index:5
is_IDENTIFIER:0
node_index:-1
number:1
0. category:0 index1:8 index2:0
--------------------------------------------






============================================
= print compound_statement_table           =
============================================
index:0 node_index:177 block_item_num:6
is_statement:0 node_index:33 index:0
is_statement:0 node_index:62 index:1
is_statement:0 node_index:71 index:2
is_statement:1 node_index:106 index:3
is_statement:0 node_index:141 index:4
is_statement:0 node_index:176 index:5
--------------------------------------------






============================================
= block_item_table                         =
============================================
initializer_block_item_table_num:6
--------------------------------------------
index:0 node_index:33 is_statement:0 data_index:0 child_index:32 block_item_next_index:1
--------------------------------------------
index:1 node_index:62 is_statement:0 data_index:1 child_index:61 block_item_next_index:2
--------------------------------------------
index:2 node_index:71 is_statement:0 data_index:2 child_index:70 block_item_next_index:3
--------------------------------------------
index:3 node_index:106 is_statement:1 data_index:0 child_index:105 block_item_next_index:4
--------------------------------------------
index:4 node_index:141 is_statement:0 data_index:3 child_index:140 block_item_next_index:5
--------------------------------------------
index:5 node_index:176 is_statement:0 data_index:4 child_index:175 block_item_next_index:-1
--------------------------------------------
--------------------------------------------



============================================
= declaration_table                        =
============================================
declaration_table_num:5
--------------------------------------------
index:0 node_index:32 declaration_specifiers_index:1 static_assert_declaration_index:-1
         init_declarator_num:1 init_declarator_infor->next_id:0
--------------------------------------------
index:1 node_index:61 declaration_specifiers_index:2 static_assert_declaration_index:-1
         init_declarator_num:1 init_declarator_infor->next_id:1
--------------------------------------------
index:2 node_index:70 declaration_specifiers_index:3 static_assert_declaration_index:-1
         init_declarator_num:1 init_declarator_infor->next_id:2
--------------------------------------------
index:3 node_index:140 declaration_specifiers_index:4 static_assert_declaration_index:-1
         init_declarator_num:1 init_declarator_infor->next_id:3
--------------------------------------------
index:4 node_index:175 declaration_specifiers_index:5 static_assert_declaration_index:-1
         init_declarator_num:1 init_declarator_infor->next_id:4
--------------------------------------------
--------------------------------------------



============================================
= init_declarator_table                    =
============================================
init_declarator_table_num:5
--------------------------------------------
index:0 node_index:30 declarator_index:1 initializer_index:0 next:-1
--------------------------------------------
index:1 node_index:59 declarator_index:2 initializer_index:1 next:-1
--------------------------------------------
index:2 node_index:68 declarator_index:3 initializer_index:-1 next:-1
--------------------------------------------
index:3 node_index:138 declarator_index:4 initializer_index:2 next:-1
--------------------------------------------
index:4 node_index:173 declarator_index:5 initializer_index:3 next:-1
--------------------------------------------
--------------------------------------------



============================================
= initializer_table                        =
============================================
initializer_table_num:4
--------------------------------------------
index:0 node_index:29 is_assignment_expression:1 data_index:0
--------------------------------------------
index:1 node_index:58 is_assignment_expression:1 data_index:0
--------------------------------------------
index:2 node_index:137 is_assignment_expression:1 data_index:0
--------------------------------------------
index:3 node_index:172 is_assignment_expression:1 data_index:0
--------------------------------------------
--------------------------------------------



============================================
= initializer_list_table                   =
============================================
initializer_list_table_num:0
--------------------------------------------
--------------------------------------------



============================================
= initializer_list_one_table               =
============================================
initializer_list_one_table_num:0
--------------------------------------------
--------------------------------------------



============================================
= statement_table                          =
============================================
statement_table_num:1
--------------------------------------------
index:0 node_index:105 category:2 data_index:0 
--------------------------------------------
--------------------------------------------



============================================
= labeled_statement_table                  =
============================================
labeled_statement_table_num:0
--------------------------------------------
--------------------------------------------



============================================
= expression_statement_table               =
============================================
expression_statement_table_num:1
--------------------------------------------
index:0 node_index:104 data_index:0 
--------------------------------------------
--------------------------------------------



============================================
= selection_statement_table                =
============================================
selection_statement_table_num:0
--------------------------------------------
--------------------------------------------



============================================
= iteration_statement_table                =
============================================
iteration_statement_table_num:0
--------------------------------------------
--------------------------------------------



============================================
= jump_statement_table                     =
============================================
jump_statement_table_num:0
--------------------------------------------
--------------------------------------------



============================================
= expression_table                         =
============================================
expression_table_num:1
--------------------------------------------
index:0 node_index:103 data_num:1 data_index:0 
--------------------------------------------
--------------------------------------------



============================================
= assignment_expression_table              =
============================================
assignment_expression_table_num:2
--------------------------------------------
index:0 node_index:102 category:1 data1_index:0 data2_index:1 next_index:-1
--------------------------------------------
index:1 node_index:101 category:0 data1_index:0 data2_index:-1 next_index:-1
--------------------------------------------
--------------------------------------------



============================================
= conditional_expression_table             =
============================================
conditional_expression_table_num:1
--------------------------------------------
index:0 node_index:100 category:0 data1_index:0 data2_index:-1 data3_index:-1
--------------------------------------------
--------------------------------------------



============================================
= unary_expression_table                   =
============================================
unary_expression_table_num:3
--------------------------------------------
index:0 node_index:75 category:0 data_index:0 
--------------------------------------------
index:1 node_index:81 category:0 data_index:1 
--------------------------------------------
index:2 node_index:88 category:0 data_index:2 
--------------------------------------------
--------------------------------------------



============================================
= logical_or_expression_table              =
============================================
logical_or_expression_table_num:1
--------------------------------------------
index:0 node_index:99 category:0 data1_index:0 data2_index:-1
--------------------------------------------
--------------------------------------------



============================================
= logical_and_expression_table             =
============================================
logical_and_expression_table_num:1
--------------------------------------------
index:0 node_index:98 category:0 data1_index:0 data2_index:-1
--------------------------------------------
--------------------------------------------



============================================
= inclusive_or_expression_table            =
============================================
inclusive_or_expression_table_num:1
--------------------------------------------
index:0 node_index:97 category:0 data1_index:0 data2_index:-1
--------------------------------------------
--------------------------------------------



============================================
= exclusive_or_expression_table            =
============================================
exclusive_or_expression_table_num:1
--------------------------------------------
index:0 node_index:96 category:0 data1_index:0 data2_index:-1
--------------------------------------------
--------------------------------------------



============================================
= and_expression_table                     =
============================================
and_expression_table_num:1
--------------------------------------------
index:0 node_index:95 category:0 data1_index:0 data2_index:-1
--------------------------------------------
--------------------------------------------



============================================
= equality_expression_table                =
============================================
equality_expression_table_num:1
--------------------------------------------
index:0 node_index:94 category:0 data1_index:0 data2_index:-1
--------------------------------------------
--------------------------------------------



============================================
= relational_expression_table              =
============================================
relational_expression_table_num:1
--------------------------------------------
index:0 node_index:93 category:0 data1_index:0 data2_index:-1
--------------------------------------------
--------------------------------------------



============================================
= shift_expression_table                   =
============================================
shift_expression_table_num:1
--------------------------------------------
index:0 node_index:92 category:0 data1_index:0 data2_index:-1
--------------------------------------------
--------------------------------------------



============================================
= additive_expression_table                =
============================================
additive_expression_table_num:2
--------------------------------------------
index:0 node_index:91 category:1 data1_index:1 data2_index:1
--------------------------------------------
index:1 node_index:84 category:0 data1_index:0 data2_index:-1
--------------------------------------------
--------------------------------------------



============================================
= multiplicative_expression_table          =
============================================
multiplicative_expression_table_num:2
--------------------------------------------
index:0 node_index:83 category:0 data1_index:0 data2_index:-1
--------------------------------------------
index:1 node_index:90 category:0 data1_index:1 data2_index:-1
--------------------------------------------
--------------------------------------------



============================================
= cast_expression_table                    =
============================================
cast_expression_table_num:2
--------------------------------------------
index:0 node_index:82 category:0 data1_index:1 data2_index:-1
--------------------------------------------
index:1 node_index:89 category:0 data1_index:2 data2_index:-1
--------------------------------------------
--------------------------------------------



============================================
= unary_expression_table                   =
============================================
unary_expression_table_num:3
--------------------------------------------
index:0 node_index:75 category:0 data_index:0 
--------------------------------------------
index:1 node_index:81 category:0 data_index:1 
--------------------------------------------
index:2 node_index:88 category:0 data_index:2 
--------------------------------------------
--------------------------------------------



============================================
= postfix_expression_table                 =
============================================
postfix_expression_table_num:3
--------------------------------------------
index:0 node_index:74 category:0 data1_index:0 data2_index:-2
--------------------------------------------
index:1 node_index:80 category:0 data1_index:1 data2_index:-2
--------------------------------------------
index:2 node_index:87 category:0 data1_index:2 data2_index:-2
--------------------------------------------
--------------------------------------------



============================================
= primary_expression_table                 =
============================================
primary_expression_table_num:3
--------------------------------------------
index:0 node_index:73 category:0 data_index:4 
--------------------------------------------
index:1 node_index:79 category:0 data_index:5 
--------------------------------------------
index:2 node_index:86 category:0 data_index:6 
--------------------------------------------
--------------------------------------------



============================================
= IDENTIFIER_table                         =
============================================
IDENTIFIER_table_num:9
--------------------------------------------
index:0 node_num:1 smbl_num:1 node_index:1 symbol_a_index:-1
 node_id:1
 smbl_id:0
 smbl_name:main
--------------------------------------------
index:1 node_num:1 smbl_num:1 node_index:7 symbol_a_index:-1
declaration_specifiers_table[0] start
index:0
storage_class_specifier none(0x00000000)
type_specifier(0x00000003): signed default int index(0)
type_qualifier(0x00000000): 
function_specifier(0x00000000): 
declaration_specifiers_table[0] end
 node_id:7
 smbl_id:1
 smbl_name:a
--------------------------------------------
index:2 node_num:1 smbl_num:1 node_index:36 symbol_a_index:-1
declaration_specifiers_table[1] start
index:1
storage_class_specifier none(0x00000000)
type_specifier(0x00000003): signed default int index(0)
type_qualifier(0x00000000): 
function_specifier(0x00000000): 
declaration_specifiers_table[1] end
 node_id:36
 smbl_id:3
 smbl_name:b
--------------------------------------------
index:3 node_num:1 smbl_num:1 node_index:64 symbol_a_index:-1
declaration_specifiers_table[2] start
index:2
storage_class_specifier none(0x00000000)
type_specifier(0x00000003): signed default int index(0)
type_qualifier(0x00000000): 
function_specifier(0x00000000): 
declaration_specifiers_table[2] end
 node_id:64
 smbl_id:5
 smbl_name:c
--------------------------------------------
index:4 node_num:1 smbl_num:1 node_index:72 symbol_a_index:2
 node_id:72
 smbl_id:6
 smbl_name:c
--------------------------------------------
index:5 node_num:1 smbl_num:1 node_index:78 symbol_a_index:0
 node_id:78
 smbl_id:7
 smbl_name:a
--------------------------------------------
index:6 node_num:1 smbl_num:1 node_index:85 symbol_a_index:1
 node_id:85
 smbl_id:8
 smbl_name:b
--------------------------------------------
index:7 node_num:1 smbl_num:1 node_index:108 symbol_a_index:-1
declaration_specifiers_table[3] start
index:3
storage_class_specifier none(0x00000000)
type_specifier(0x00000003): signed default int index(0)
type_qualifier(0x00000000): 
function_specifier(0x00000000): 
declaration_specifiers_table[3] end
 node_id:108
 smbl_id:9
 smbl_name:m
--------------------------------------------
index:8 node_num:1 smbl_num:1 node_index:143 symbol_a_index:-1
declaration_specifiers_table[4] start
index:4
storage_class_specifier none(0x00000000)
type_specifier(0x00000003): signed default int index(0)
type_qualifier(0x00000000): 
function_specifier(0x00000000): 
declaration_specifiers_table[4] end
 node_id:143
 smbl_id:12
 smbl_name:n
--------------------------------------------
--------------------------------------------



============================================
= struct_or_union_specifier_table          =
============================================
struct_or_union_specifier_table_num:0
--------------------------------------------
--------------------------------------------



============================================
= function_definition_table                =
============================================
function_definition_table_num:1
--------------------------------------------
index:0 node_index:178 category:1 data1_index:0 data2_index:0 data3_index:-1 data4_index:0
--------------------------------------------
--------------------------------------------



============================================
= symbol_a_table                           =
============================================
symbol_a_table_num:6
--------------------------------------------
index:0 declaration_specifiers_index:1 IDENTIFIER_index:1 symbol_name:***a(line_num:4)*** action_scope:177 s_type(variable:0 struct:1 function:2):0         
pointer_index:-1 array_dimension:0 
taint_m:12 taint_src:0
--------------------------------------------
index:1 declaration_specifiers_index:2 IDENTIFIER_index:2 symbol_name:***b(line_num:5)*** action_scope:177 s_type(variable:0 struct:1 function:2):0         
pointer_index:-1 array_dimension:0 
taint_m:0 taint_src:1
--------------------------------------------
index:2 declaration_specifiers_index:3 IDENTIFIER_index:3 symbol_name:***c(line_num:6)*** action_scope:177 s_type(variable:0 struct:1 function:2):0         
pointer_index:-1 array_dimension:0 
taint_m:12 taint_src:0
--------------------------------------------
index:3 declaration_specifiers_index:4 IDENTIFIER_index:7 symbol_name:***m(line_num:9)*** action_scope:177 s_type(variable:0 struct:1 function:2):0         
pointer_index:-1 array_dimension:0 
taint_m:0 taint_src:3
--------------------------------------------
index:4 declaration_specifiers_index:5 IDENTIFIER_index:8 symbol_name:***n(line_num:10)*** action_scope:177 s_type(variable:0 struct:1 function:2):0         
pointer_index:-1 array_dimension:0 
taint_m:0 taint_src:4
--------------------------------------------
index:5 declaration_specifiers_index:-1 IDENTIFIER_index:-1 symbol_name:***(null)(line_num:7)*** action_scope:177 s_type(variable:0 struct:1 function:2):4         
pointer_index:-1 array_dimension:0 
taint_m:12 taint_src:0
--------------------------------------------
--------------------------------------------


============================================
= instruction_table                        =
============================================
instruction_table_num:7
--------------------------------------------
index:0 sequence:0 node_index:177 prev:0 next:0 ins_type:57 ins_set_num:1
line_num:12 inst_type:57 ins_ret:-1 ins_data1:-1 ins_data2:-1 ins_data3:-1 ins_taint_level:0 ins_taint_src:-1
instruction description: compound_statement_ins(57)
including 0 instruction: 1
--------------------------------------------
index:1 sequence:1 node_index:103 prev:0 next:0 ins_type:56 ins_set_num:1
line_num:7 inst_type:56 ins_ret:-1 ins_data1:1 ins_data2:6 ins_data3:-1 ins_taint_level:0 ins_taint_src:-1
instruction description: expression_ins(56)
including 0 instruction: 6
--------------------------------------------
index:2 sequence:2 node_index:72 prev:0 next:0 ins_type:55 ins_set_num:0
line_num:7 inst_type:55 ins_ret:2 ins_data1:2 ins_data2:-1 ins_data3:-1 ins_taint_level:0 ins_taint_src:2
instruction description: just_IDENTIFIER_ins(55)
--------------------------------------------
index:3 sequence:3 node_index:78 prev:0 next:0 ins_type:55 ins_set_num:0
line_num:7 inst_type:55 ins_ret:0 ins_data1:0 ins_data2:-1 ins_data3:-1 ins_taint_level:12 ins_taint_src:0
instruction description: just_IDENTIFIER_ins(55)
--------------------------------------------
index:4 sequence:4 node_index:85 prev:0 next:0 ins_type:55 ins_set_num:0
line_num:7 inst_type:55 ins_ret:1 ins_data1:1 ins_data2:-1 ins_data3:-1 ins_taint_level:0 ins_taint_src:1
instruction description: just_IDENTIFIER_ins(55)
--------------------------------------------
index:5 sequence:5 node_index:91 prev:0 next:0 ins_type:49 ins_set_num:0
line_num:7 inst_type:49 ins_ret:5 ins_data1:0 ins_data2:1 ins_data3:-1 ins_taint_level:12 ins_taint_src:0
instruction description: add1_op_ins(49)
--------------------------------------------
index:6 sequence:6 node_index:102 prev:0 next:0 ins_type:11 ins_set_num:0
line_num:7 inst_type:11 ins_ret:2 ins_data1:2 ins_data2:5 ins_data3:-1 ins_taint_level:12 ins_taint_src:0
instruction description: assignment_ins(11)
--------------------------------------------
--------------------------------------------

说明：
应为declaration还没有处理成instruction，因此int a=12不会被记录到instruction中，c=a+b, 首先处理c，因为此时c还未被标记为污点，所以指令index2的ins_taint_level为0；



