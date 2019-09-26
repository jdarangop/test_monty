#include "header.h"

void check_token(char *token1, unsigned int line_number, stack_t **stack)
{
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
			array[i].f(&(*stack), line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token1);
}

void check_argument(char *token, char *line_buf, FILE *fp, stack_t *stack, unsigned int line)
{
	int i = 0;

	while (token[i] != '\0')
	{
		if (token[i] > '0' && token[i] < '9')
		{
			i++;
			continue;
		}
		else if (token[i] == '-')
		{
			i++;
			continue;
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			free(line_buf);
			free_stack(stack);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
