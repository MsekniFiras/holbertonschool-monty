#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - main function of the monty interpreter.
 * @argc: number of command-line arguments.
 * @argv: array of command-line argument strings.
 * Return: EXIT_SUCCES or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)

	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	char *line = NULL;
	size_t line_size = 0;
	unsigned int line_number = 1;

	while (getline(&line, &line_size, file) != -1)
	{
		char *opcode = strtok(line, " \t\n");

		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				push(&stack, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&stack, line_number);
			}
			else if (strcmp(opcode, "pint") == 0)
			{
				pint(&stack, line_number);
			}
			else if (strcmp(opcode, "pop") == 0)
			{
				pop(&stack, line_number);
			}
			else if (strcmp(opcode, "swap") == 0)
			{
				swap(&stack, line_number);
			}
			else if (strcmp(opcode, "add") == 0)
			{
				add(&stack, line_number);
			}
			else if (strcmp(opcode, "nop") == 0)
			{
				nop(&stack, line_number);
			}

			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				free_stack(&stack);
				free(line);
				fclose(file);
				return (EXIT_FAILURE);
			}
		}
		line_number++;
	}

	free_stack(&stack);
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
