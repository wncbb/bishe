objects=cbison.tab.o lex.yy.o lib/compiler_state.o lib/error.o lib/deal_arg.o lib/scope.o \
lib/node/node.o lib/node/node_tree.o lib/node/node_type.o \
lib/symbol/symbol.o lib/symbol/smbl_function_definition.o lib/symbol/deal_instruction.o lib/symbol/instruction_type.o\
#lib/semantic/declaration_specifiers.o


myCompiler.out: $(objects)
	gcc -o myCompiler.out $(objects)

cbison.tab.c cbison.tab.h: cbison.y
	bison -d cbison.y
lex.yy.c: clex.l
	flex clex.l

cbison.tab.o: cbison.tab.c cbison.tab.h
	gcc -c cbison.tab.c
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lib/compiler_state.o: lib/compiler_state.c lib/compiler_state.h
	gcc -c -o lib/compiler_state.o lib/compiler_state.c
lib/deal_arg.o: lib/deal_arg.c lib/deal_arg.h
	gcc -c -o lib/deal_arg.o lib/deal_arg.c
lib/error.o: lib/error.c lib/error.h
	gcc -c -o lib/error.o lib/error.c
lib/scope.o: lib/scope.c lib/scope.h
	gcc -c -o lib/scope.o lib/scope.c

lib/node/node.o: lib/node/node.c lib/node/node.h
	gcc -c -o lib/node/node.o lib/node/node.c
lib/node/node_tree.o: lib/node/node_tree.c lib/node/node_tree.h
	gcc -c -o lib/node/node_tree.o lib/node/node_tree.c
lib/node/node_type.o: lib/node/node_type.c lib/node/node_type.h
	gcc -c -o lib/node/node_type.o lib/node/node_type.c

lib/symbol/symbol.o: lib/symbol/symbol.c lib/symbol/symbol.h
	gcc -c -o lib/symbol/symbol.o lib/symbol/symbol.c
lib/symbol/smbl_function_definition.o: lib/symbol/smbl_function_definition.c lib/symbol/smbl_function_definition.h
	gcc -c -o lib/symbol/smbl_function_definition.o lib/symbol/smbl_function_definition.c
lib/symbol/deal_instruction.o: lib/symbol/deal_instruction.c lib/symbol/deal_instruction.h
	gcc -c -o lib/symbol/deal_instruction.o lib/symbol/deal_instruction.c
lib/symbol/instruction_type.o: lib/symbol/instruction_type.c lib/symbol/instruction_type.h
	gcc -c -o lib/symbol/instruction_type.o lib/symbol/instruction_type.c

#lib/semantic/declaration_specifiers.o: lib/semantic/declaration_specifiers.c lib/semantic/declaration_specifiers.h
#	gcc -c -o lib/semantic/declaration_specifiers.o lib/semantic/declaration_specifiers.c


.PHONY: clean
clean:
	-rm myCompiler.out $(objects)

.PHONY: myclean
myclean:
	-rm -f cbison.tab.c cbison.tab.h lex.yy.c $(objects) 


