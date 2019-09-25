#include "header.h"

void check_token(char *token1, char *token2, stack_t **stack)
{
	int tok2;
	instruction_t array[] = {
			{"push", _push},
			{"pall", _pall},
			{NULL, NULL}
			};
	int i = 0;
	while(i < 2)
	{
		if(strcmp(array[i].opcode, token1) == 0)
		{
			/*printf("hola\n");*/
			if (token2 != NULL)
				tok2 = atoi(token2);
			array[i].f(&(*stack), tok2);
		}
		i++;
	}
}
