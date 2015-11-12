
typedef struct _strcmp_value
{
	const char *string1;
	const char *string2;
}strcmp_value;

static int strcmp_call(void *opaque)
{
  	int read_err = 0;
  	int i = 0;
  	strcmp_value *scv=malloc(sizeof (strcmp_value));
  	if(tracepid == 0) 
	{
		return 0;
	}

  	read_reg(esp_reg, &esp);
  	read_reg(eip_reg, &eip);
  	read_err = read_mem(esp, 4, (unsigned char*)buf);
  	if (read_err) 
		return 0;

  	scv->string1=buf[1];
  	scv->string2=buf[2];
	
	char string_cmd[20];
	char string_list[20];

	bool read_cmd =read_mem(scv->string1, 20, (unsigned char*)string_cmd);
	bool read_list=read_mem(scv->string2, 20, (unsigned char*)string_list);

  	scv->hook_handle=hookapi_hook_return(buf[0], strcmp_ret, scv, sizeof(scv));
  	return 0;
}

static int strcmp_ret(void *opaque)
{
	int read_err = 0;
	strcmp_value *scv = (strcmp_value *)opaque;
	int eax = 0;
	hookapi_remove_hook(scv->hook_handle);
	read_reg(eax_reg, &eax);
	if (eax == 0 ) 
	{
    		WRITE ("stderr", "\tthe two strings are same!\n");
  	}
  	else 
	{
    		WRITE ("stderr", "\tthe two strings are not same %x!\n",eax);
  	}
	int tmp=1;
	write_reg(eax_reg,tmp);
  	if (scv)
        	free(scv);
  	return 0;

}













