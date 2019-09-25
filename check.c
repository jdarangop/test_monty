#include "header.h"

int check(char *token1, char *token2)
{
	instruction_t *array = {{"push", _push}, {"pall", _pop}};

	for (i = 0; i < 2; i++)
	{
		if (strcmp(token1, array[i]->opcode) == 0)
			printf("Encontro: %s\n", token1);
	}
}
