#include "monty.h"

/**
 * _add - add two numbers from the top of that stack

 * @stack: the stack
 * @x: the line number
 * Return: none
 */

void _add(stack_t **stack, unsigned int x)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(x, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	_pop(stack, x);
}

/**
 * _nop - does nothing at all
 * @stack: the stack
 * @x: the line number
 * Return: void
 */

void _nop(stack_t **stack, unsigned int x)
{
	(void)stack;
	(void)x;
}

/**
 * _sub - subtracts the top element of the stack from the second top
 * @stack: the stack
 * @x: the line number
 * Return: void
 */

void _sub(stack_t **stack, unsigned int x)
{
	int difference;

	if (*stack == NULL || (*stack)->next == NULL)
		_error(ERROR_SUB);

	difference = (*stack)->next->n - (*stack)->n;

	_pop(stack, x);
	(*stack)->n = difference;
}

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: the stack
 * @x: the line number
 * Return: void
 */

void _div(stack_t **stack, unsigned int x)
{
	int quotient;

	if (*stack == NULL || (*stack)->next == NULL)
		_error(ERROR_DIV);

	if ((*stack)->n == 0)
		_error(ERROR_DIV_ZERO);

	quotient = (*stack)->next->n / (*stack)->n;

	_pop(stack, x);
	(*stack)->n = quotient;
}

/**
 * _mul - multiplies the second top element of the stack with the top
 * @stack: the stack
 * @x: the line number
 * Return: void
 */

void _mul(stack_t **stack, unsigned int x)
{
	int product;

	if (*stack == NULL || (*stack)->next == NULL)
		_error(ERROR_MUL);

	product = (*stack)->next->n * (*stack)->n;

	_pop(stack, x);
	(*stack)->n = product;
}
