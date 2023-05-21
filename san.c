#include <stdio.h>
#include "monty.h"
#include <stdlib.h>

/**
 * swap - swaps the top two elements of the stack.
 * @stack: a double pointer to the top of the stack.
 * @line_number: of the opcode.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
* add - adds the top two elements of the stack.
* @stack: a double pointer to the top of stack.
* @line_number: of the opcode.
*/

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		}

	stack_t *top = *stack;
	*stack = (*stack)->next;
	(*stack)->n += top->n;
	(*stack)->prev = NULL;
	free(top);
}

/**
 * nop - The opcode nop doesn’t do anything.
 * @stack: a double pointer to the top of the stack.
 * @line_number: of opcode.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
