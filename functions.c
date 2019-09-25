#include "header.h"

/**
 * _push - Add a new elemtn to the stack.
 * @stack: Stack.
 * @line_number: Line number.
 * Return: void.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit (EXIT_FAILURE);
	}
	new_node->n = push_arg;
	new_node->next = (*stack);
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * _pall - Print all the elements in the stack.
 * @stack: Stack.
 * @line_number: Line number.
 * Return: void.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * free_stack - Free the stack.
 * @head: Head of the stack.
 * Return: void.
 */
void free_stack(stack_t *head)
{
	stack_t *next;

	if (head == NULL)
		return;
	next = head->next;
	while (head != NULL)
	{
		free(head);
		head = next;
		if (head != NULL)
			next = next->next;
	}
}
