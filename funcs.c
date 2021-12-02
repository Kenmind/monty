#include "monty.h"

/**
 * _push - adds node at the beginning of a stack_t list
 * @stack: pointer to head of stack
 * @x: line number
 */

void _push(stack_t **stack, unsigned int x)
{
	stack_t *node = NULL;
	char *num;
	(void)x;

	if (traverse->input[1] == NULL)
		printf("Error\n");/*handle_errors(ERROR_PUSH);*/
	else
		num = traverse->input[1];
	if (_isDigit(num) == TRUE)
	{
		node = malloc(sizeof(stack_t));
		if (node == NULL)
			printf("Error in malloc\n");/*handle_errors(ERROR_MALLOC);*/
	}
	else
		printf("Error pushing\n");/*handle_errors(ERROR_PUSH);*/

	node->n = atoi(num);
	if (traverse->order == LIFO)
		_lifo(stack, node);
	else
		_fifo(stack, node);
}

/**
 * _pall - prints all elements of the stack
 * @stack: pointer to head of stack
 * @x: line number
 * Return: void
 */

void _pall(stack_t **stack, unsigned int x)
{
	stack_t *copy;
	(void)x;

	for (copy = *stack; copy; copy = copy->next)
		printf("%d\n", copy->n);
}

/**
 * _pint - prints the number of the head node
 * @stack: the stack
 * @x: line number
 * Return: void
 */

void _pint(stack_t **stack, unsigned int x)
{
	(void)x;

	if (!stack || !*stack)
		_error(ERROR_PINT);

	printf("%d\n", (*stack)->n);
}

/**
 * _pop - pops the top element off the stack
 * @stack: pointer to head of stack (linked list)
 * @x: line number
 *
 */

void _pop(stack_t **stack, unsigned int x)
{
	stack_t *next;
	(void)x;

	if (*stack == NULL)
		_error(ERROR_POP);
	else if ((*stack)->next != NULL)
	{
		next = (*stack)->next;
		next->prev = NULL;
		free(*stack);
		*stack = next;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * _swap - swaps top two elements
 * @stack: the stack
 * @x: the line number
 * Return: void
 */

void _swap(stack_t **stack, unsigned int x)
{
	int temp;
	(void)x;

	if (!stack || !*stack || !(*stack)->next)
		_error(ERROR_SWAP);

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
