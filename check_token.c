#include "header.h"

int check_token(char *token1)
{
	int i = 0;
	char *array_upcode[] = {"push", "pall", "pint", "pop", "swap", "add", "nop"};
	/*int (*func_upcode[]) (char *) = { &push_func, &pall_func, &pint_func,
				&pop_func, &swap_func, &add_func, &nop_func};*/
	while(i < 7)
	{
		if(strcmp(array_upcode[i],token1) == 0)
		{
			printf("hola\n");
		}
		else
			printf("chao\n");
		i++;
	}
return (1);
}
