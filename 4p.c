#include "monty.h"
#include "stdio.h"
#include "stdlib.h"

/**
 *push - The opcode push pushes an element to the stack.
 *@stack: a double pointer to the top of the stack.
 *@line_number: value to be pushed to the stack.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = NULL;

	arg = strtok(NULL, " \n\r\t");
	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *node = malloc(sizeof(stack_t));

		if (!node)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		node->n = atoi(arg);
		node->next = (*stack);
		node->prev = NULL;
		if (*stack)
		{
			(*stack)->prev = node;
		}
		*stack = node;
	}
}

/**
 *pall - The opcode pall prints all the values on the stack
 *   starting from the top of the stack
 *@stack: a double pointer to the top of stack.
 *@line_number: an unsigned integer
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number; /* unused parameter */

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 *pint - Prints the value at the top of the stack.
 *@stack: Double pointer to the top of the stack.
 *@line_number: Line number where the opcode is encountered.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: a double pointer at the top of the stack.
 * @line_number: an unsigned integer
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 *free_stack - frees memory allocation after use
 *@stack: a double pointer
 */

void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
