#include "header.h"

/**
* _len - function that returns number of elements
* @stack: header of stack
* Return: number of elements in the stack
*/

size_t _len(const stack_t *stack)
{
	int count = 0;

	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

/**
* _add - adds the top two elements
* @stack: header
* @line_number: elements
*/

void _add(stack_t **stack, unsigned int line_number)
{
	int lenght;
	int tmp, sum;
	lenght = _len((*stack));
	if (lenght < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	sum = tmp + (*stack)->next->n;
	(*stack)->next->n = sum;
	_pop(stack, line_number);
}

void stack_init(stack_t **stack)
{
	(*stack)->prev = NULL;
	(*stack)->next = NULL;
}

void stack_destroy(stack_t **stack)
{
	stack_t *tmp;
	stack_t *current = (*stack);

	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
