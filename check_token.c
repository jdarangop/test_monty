#include "header.h"

void check_token(char *token1, char *token2, stack_t **stack)
{
	int tok2;
	instruction_t array[] = {
			{"push", _push},
			{"pall", _pall},
			{"pint", _pint},
			{"pop", _pop},
			{"swap", _swap},
			{"add", _add},
			{NULL, NULL}
			};
	int i = 0;
	while(i < 6)
	{
		if(strcmp(array[i].opcode, token1) == 0)
		{
			/*printf("hola\n");*/
			if (token2 != NULL)
				tok2 = atoi(token2);
			stack_init(&(*stack));
			array[i].f(&(*stack), tok2);
			stack_destroy(stack_t &(*stack);
		}
		i++;
	}
}
