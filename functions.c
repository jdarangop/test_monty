#include "header.h"

/**
 * add_dnodeint - Add a new node in the beginning of the list.
 * @head: Head of the list.
 * @n: Element into the node.
 * Return: Node added.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	/*if (new_node == NULL)
		return NULL;*/
	new_node->n = line_number;
	new_node->next = (*stack);
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * print_dlistint - Print all the elements in the list.
 * @h: head of the list.
 * Return: Number of nodes.
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
* _pint - print the value at the top of the stack
* @stack: head of the list.
* @line_number: element of the node
*/

void _pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if ((*stack) != NULL)
		printf("%d\n", (*stack)->n);
}

/**
* _pop - removes the top element of the stack
* @stack: head of the list
* @line_number: element of the node
*/

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *rm;
	(void)line_number;
	rm = (*stack);
	(*stack) = (*stack)->next;
	if(*stack)
	{
		(*stack)->prev = NULL;
		free(rm);
	}
}

/**
* _swap - swaps the top two elements of the stack
* @stack: head of the list
* @line_number: element of the node
*/

void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp;
	(void)line_number;
	tmp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = tmp;
}
