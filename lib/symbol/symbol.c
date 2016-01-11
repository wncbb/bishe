#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbol.h"
#include "smbl_function_definition.h"
#include "../error.h"
#include "../node/node_type.h"
#include "../node/node.h"

//come from ../../cbison.c
extern struct compiler_state my_state;

//come from ../node/node_type.c
extern char *node_type_str[];

int str_len(char *ptr)
{
	int i;
	for(i=0; ptr[i]!=0x00; i++)
	{}
	return i;
}
int str_copy(char *s, char *d, int length)
{
	int i; 
	for(i=0; i<length; i++)
	{
		d[i]=s[i];	
	}
	d[i]=0x00;
	return 0;
}

struct symbol_my* add_symbol(char *input_yytext_ptr, int line_num, int symbol_type)
{
    //printf("in add_symbol start\n");
    if(my_state.symbol_table[my_state.symbol_number]==0x00)
    {
        
        //printf("in add_symbol 1\n");
        my_state.symbol_table[my_state.symbol_number]=(struct symbol_my *)malloc(sizeof(struct symbol_my));
        //printf("in add_symbol 2\n");
        if(my_state.symbol_table[my_state.symbol_number]==0x00)
        {
            snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/symbol/symbol.c add_symbol function wrong! malloc error!");
            my_state.error_int=30101;
            error_quit();
            return 0;
        }
        //my_state.symbol_number+=1;  
    }
    else
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/symbol/symbol.c add_symbol function wrong! symbol_number error!\n");
        my_state.error_int=30102;
        error_quit();
        return 0; 
    }
    //printf("in add_symbol 3\n");

    int symbol_index=my_state.symbol_number;
    //printf("in add_symbol 14\n");
    //printf("symbol_index:%d my_state.symbol_table[symbol_index]:%x\n", symbol_index, my_state.symbol_table[symbol_index]);
    my_state.symbol_table[symbol_index]->smbl_id=my_state.symbol_number;
    //printf("in add_symbol 24\n");
    char *tmp=malloc(str_len(input_yytext_ptr)+1);
    //printf("in add_symbol 34\n");
    str_copy(input_yytext_ptr, tmp, str_len(input_yytext_ptr));
    //printf("in add_symbol 44\n");
    my_state.symbol_table[symbol_index]->smbl_name=tmp;
    //printf("in add_symbol 54\n");
    my_state.symbol_table[symbol_index]->smbl_name_len=str_len(input_yytext_ptr);

    //printf("in add_symbol 64\n");
    my_state.symbol_table[symbol_index]->smbl_type=symbol_type;

    my_state.symbol_table[symbol_index]->smbl_line_num=line_num;
    
    my_state.symbol_table[symbol_index]->smbl_in_which_node=my_state.node_number;	
    
    my_state.symbol_number+=1;  


    //printf("in add_symbol end\n");
    return my_state.symbol_table[symbol_index];
}
int print_symbol(struct symbol_my *ptr)
{
    printf("smbl_id: %u smbl_name: %s smbl_line_num: %d smbl_type: %s(%d) line_num:%d\n", ptr->smbl_id, ptr->smbl_name, ptr->smbl_line_num, node_type_str[ptr->smbl_type], ptr->smbl_type, ptr->smbl_line_num);
}

int print_symbol_all_infor(struct symbol_my * smbl_ptr)
{
    printf("id(%d):",            smbl_ptr->smbl_id);
    printf("name(%s):",          smbl_ptr->smbl_name);
    printf("name_len(%d):",      smbl_ptr->smbl_name_len);
    printf("type(%s[%d]):",      node_type_str[smbl_ptr->smbl_type], smbl_ptr->smbl_type);
    printf("file(%s):",          smbl_ptr->smbl_file);
    printf("file_len(%d):",      smbl_ptr->smbl_file_len);
    printf("line_num:(%d):",     smbl_ptr->smbl_line_num);
    printf("in_which_node(%d):", smbl_ptr->smbl_in_which_node);
    printf("\n");

    return 0;
}


int print_symbol_table()
{
    int i;
    printf("---------------------symbol_table:\n");
    for(i=0; my_state.symbol_table[i]!=0x00; i++)
    {
        //print_symbol(my_state.symbol_table[i]);
        print_symbol_all_infor(my_state.symbol_table[i]);
    }
    printf("---------------------symbol_table!\n");
    return 0;
	
}

int symbol_a_table_num_add()
{
    my_state.symbol_a_table_num+=1;
    return my_state.symbol_a_table_num;
}

int symbol_a_add(int action_scope, int node_index)
{
    printf("todd0111c node_index%d\n", node_index);
    struct symbol_a_infor * infor_ptr=(struct symbol_a_infor *)malloc(sizeof(struct symbol_a_infor));
    int cur_infor_index=my_state.symbol_a_table_num;
    infor_ptr->index=cur_infor_index;
    my_state.symbol_a_table[cur_infor_index]=infor_ptr;
    //my_state.symbol_a_table_num+=1;
    symbol_a_table_num_add();
    infor_ptr->node_index=node_index;
    infor_ptr->declaration_specifiers_index=-1;
    infor_ptr->IDENTIFIER_index=-1;
    infor_ptr->smbl_name=NULL;
    infor_ptr->line_num=my_state.node_table[node_index]->node_line_num;
    infor_ptr->s_type=0;
    infor_ptr->pointer_index=-1;
    infor_ptr->array_dimension=0;
    infor_ptr->every_dimension=NULL;
    infor_ptr->taint_m=0;
    infor_ptr->taint_src=infor_ptr->index;
    infor_ptr->action_scope=action_scope;
/*
    if(my_state.need_taint_file==1)
    {
      infor_ptr->taint_m=is_taint(infor_ptr->smbl_name, infor_ptr->line_num);
    }
*/
    return cur_infor_index;
}

int alter_symbol_a_action_scope(int index, int action_scope)
{
    struct symbol_a_infor *ptr=my_state.symbol_a_table[index];
    ptr->action_scope=action_scope;
    return index;
}

int alter_symbol_a_s_type(int index, int s_type)
{
    struct symbol_a_infor *ptr=my_state.symbol_a_table[index];
    ptr->s_type=s_type;
    return index;
}
int alter_symbol_a_taint_m(int index, int taint_m)
{
    struct symbol_a_infor *ptr=my_state.symbol_a_table[index];
    ptr->taint_m=taint_m;
    return index;
}


int symbol_a_find_part1(char *name, int action_scope)
{
  int ret=-1;
  int i=0;
  //printf("todd0112 a\n");
  for(i=0; i<my_state.symbol_a_table_num && my_state.symbol_a_table[i]!=0x00 ; ++i)
  {
    if(my_state.symbol_a_table[i]->smbl_name==NULL)
    {
      continue;
    }
    //printf("todd0112 b %d name:%s my_state.symbol_a_table[%d]->smbl_name:%s\n", i, name, i, my_state.symbol_a_table[i]->smbl_name);
    if((0==strcmp(name, my_state.symbol_a_table[i]->smbl_name))&&(action_scope==my_state.symbol_a_table[i]->action_scope))
    {
      ret=i;
      break;
    }
    //printf("todd0112 c %d\n", i);
  }
  return ret;
}

int symbol_a_find_part2(int node_index)
{
  int ret=-1;
  struct node_my *node_my_tmp=my_state.node_table[node_index];
  int action_scope=node_my_tmp->node_compound_id;
  while(1)
  {
    if(node_my_tmp->node_parent!=-1)
    {
      node_my_tmp=my_state.node_table[node_my_tmp->node_parent];
    }
    else
    {
      break;
    }
    if(node_my_tmp->node_compound_id!=action_scope)
    {
      ret=node_my_tmp->node_index;
      break;
    }
  }
  return ret;
}

int symbol_a_find(char *name, int action_scope, int node_index)
{
  int ret=-1;
  int i=0;
  struct node_my *node_my_tmp=my_state.node_table[node_index];
  while(1)
  {
    //printf("todd0111 a %s %d\n", name, action_scope);
    ret=symbol_a_find_part1(name, action_scope);
    //printf("todd0111 b\n");
    if(ret!=-1)
    {
      break;
    }
    node_index=symbol_a_find_part2(node_index);
    if(node_index!=-1)
    {
      node_my_tmp=my_state.node_table[node_index];
      action_scope=node_my_tmp->node_compound_id;
    }
    else
    {
      break;
    }
     
  }

  return ret;

/*
  int ret=-1;
  int i=0;

  int symbol_a_index[NEST_DEPTH];
  int symbol_a_action_scope[NEST_DEPTH];
  int array_count=0;

  int parent_node_index=node_index;
  struct node_my * parent_node_ptr=my_state.node_table[parent_node_index];
  int parent_action_scope=-1;

  for(i=0; i<NEST_DEPTH; ++i)
  {
      symbol_a_index[i]=-1;
      symbol_a_action_scope[NEST_DEPTH]=-1;
  }

  struct symbol_a_infor * cur_infor_ptr=NULL;
  printf("symbol_a_find: %d\n", my_state.symbol_a_table_num);
  for(i=0; i<my_state.symbol_a_table_num; ++i)
  {
    cur_infor_ptr=my_state.symbol_a_table[i];
    printf("0512ned_str_name:%s\n", name);
    printf("cur_str_name:%s\n", cur_infor_ptr->smbl_name);
    if( 0==strcmp(cur_infor_ptr->smbl_name, name) )
    {
        if(action_scope==cur_infor_ptr->action_scope)
        {
            ret=i;
            break;
        }
        else
        {
            symbol_a_index[array_count]=cur_infor_ptr->index;
            symbol_a_action_scope[array_count]=cur_infor_ptr->action_scope;
            ++array_count;
        }
    }
  }
  if(ret==-1)
  {
      if(array_count==0)
      {
          printf("%s:%d symbol_a_find func: symbol NOT FOUND !\n", __FILE__, __LINE__);
      }
      else
      {
          while(1)
          {
              parent_node_index=ret_next_action_scope_node(parent_node_index);
              if(parent_node_index!=-1)
              {
                  parent_node_ptr  =my_state.node_table[parent_node_index];
                  parent_action_scope=parent_node_ptr->node_compound_id;
                  for(i=0; i<array_count; ++i)
                  {
                      if(symbol_a_action_scope[i]==parent_action_scope)
                      {
                          ret=symbol_a_index[i];
                          break;
                      }
                  }
              }
              else
              {
                  printf("%s:%d symbol_a_find func: symbol NOT FOUND !\n", __FILE__, __LINE__);
                  break;
              }

          }
      }
  }
*/
}

int ret_next_action_scope_node(int node_index)
{
    //int node_index=my_state.symbol_a_table[symbol_a_index]->node_index;
    int ret=-1;
    struct node_my * node_ptr=my_state.node_table[node_index];
    int parent_node_index=node_ptr->node_parent;
    int action_scope=node_ptr->node_compound_id;
    struct node_my * parent_node_ptr=NULL;
    while(parent_node_index!=-1)
    {
        parent_node_ptr=my_state.node_table[parent_node_index];
        if(parent_node_ptr->node_compound_id!=action_scope)
        {
            ret=parent_node_index;
            break;
        }
        parent_node_index=parent_node_ptr->node_parent;
    }
    return ret;
}


int print_symbol_a_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= symbol_a_table                           =\n");
    printf(    "============================================\n");
    printf("symbol_a_table_num:%d\n", my_state.symbol_a_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.symbol_a_table_num; ++i)
    {
        print_symbol_a_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n");
    return 0;
}

int print_symbol_a_infor(int index)
{
    struct symbol_a_infor * infor_ptr=my_state.symbol_a_table[index];
    if(infor_ptr!=NULL)
    {
        printf("index:%d declaration_specifiers_index:%d IDENTIFIER_index:%d symbol_name:***%s(line_num:%d)*** action_scope:%d s_type(variable:0 struct:1 function:2):%d \
        \npointer_index:%d array_dimension:%d \n", infor_ptr->index, infor_ptr->declaration_specifiers_index, \
        infor_ptr->IDENTIFIER_index, infor_ptr->smbl_name, infor_ptr->line_num, infor_ptr->action_scope, infor_ptr->s_type, infor_ptr->pointer_index, infor_ptr->array_dimension);
        printf("taint_m:%d taint_src:%d\n", infor_ptr->taint_m, infor_ptr->taint_src);
        printf("node_index:%d \n", infor_ptr->node_index);
        int i=0;
        struct symbol_a_dms * dms_ptr=infor_ptr->next;
        for(i=0; i<infor_ptr->mod_num; ++i)
        {
            printf("--seq:%d category:%d index1:%d index2:%d\n", dms_ptr->seq, dms_ptr->category, dms_ptr->index1, dms_ptr->index2);
            dms_ptr=dms_ptr->next;
        }
    }
    else
    {
        printf("NULL\n");
    }
    return index;
}

int is_in_taint_file(char *name, int line_num)
{
  int i=0;
  int ret=0;
  for(i=0; i<my_state.taint_num; ++i)
  {
    //printf("1123: %s %s %d\n", my_state.taint_name_array[i], name, i);
    if((0==strcmp(my_state.taint_name_array[i], name))&&(my_state.taint_line_array[i]==line_num))
    {
      ret=my_state.taint_level_array[i];
 
      break;
    }
  }
  return ret;
}






