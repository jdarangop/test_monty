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
