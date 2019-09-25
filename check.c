#include "header.h"

void check(char *token1, char *token2)
{
	int i;
	instruction_t array[] = {{"push", &_push}, {"pall", &_pall}};

	(void)token2;
	for (i = 0; i < 2; i++)
	{
		if (strcmp(token1, array[i].opcode) == 0)
			printf("Encontro: %s\n", token1);
	}
}
