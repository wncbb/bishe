#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "deal_arg.h"

#include "compiler_state.h"


extern struct compiler_state my_state;

int use_infor()
{
    printf("--graph or -g dot_file_name\n");
    printf("--taint or -t taint_file_name\n");
    return 0;
}


// initialize 
int deal_arg(int argc, char **argv)
{
    //int need_dot_file=0;
    //char dot_file_str[FILE_NAME_LENGTH];    



    char * short_options="g:t:";  //: means need argv
    struct option long_options[]={
    {"graph", 1, NULL, 'g'},  // 1 means need argv, 0 means no argv, 2 means with or without argv are both ok.
    {"taint", 1, NULL, 't'},
    {      0, 0,    0,  0}
    };    

    int result=0;
    while(-1!=(result=getopt_long(argc, argv, short_options, long_options, NULL)))
    {
        switch(result)
        {
            case 'g':
                printf("need graph, name:%s\n", optarg);

                if(strlen(optarg)>(FILE_NAME_LENGTH-1))
                {
                    snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/deal_arg.c: dot file name was too long!");
                    my_state.error_int=10201;
                    //printf("dot file name was too long!\n");
                    error_quit();
                }
                my_state.need_dot_file=1;
                memcpy(my_state.dot_file_str, optarg, strlen(optarg));
                break;
            case 't':
                printf("need taint, name:%s\n", optarg);

                if(strlen(optarg)>(FILE_NAME_LENGTH-1))
                {
                    snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/deal_arg.c: taint file name was too long!");
                    my_state.error_int=10201;
                    //printf("dot file name was too long!\n");
                    error_quit();
                }
                my_state.need_taint_file=1;
                memcpy(my_state.taint_file_str, optarg, strlen(optarg));
                
                break;
            default:
                use_infor();
                break;
        }
    }
    char *c_file=argv[optind];
    if(c_file==NULL)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/deal_arg.c: need a c file for input!");
        my_state.error_int=10102;
        error_quit();
    }
    //printf("sizeof(c_file):%d strlen(c_file):%d\n", sizeof(c_file), strlen(c_file));
    //printf("c_file:%s\n", c_file);

    if(strlen(c_file)>(FILE_NAME_LENGTH-1))
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib_deal_arg.c: file name was too long!");
        my_state.error_int=10103;
        //printf("c file name was too long!\n");
        error_quit();
    }
    memcpy(my_state.c_file_str, c_file, strlen(c_file));

    return 0;
}

/*
int main(int argc, char ** argv)
{
    deal_arg(argc, argv);
    return 0;
}
*/




