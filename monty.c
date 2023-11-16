#include "monty.h"


instruction_t instructions[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"nop", nop},
{"add", add},
{NULL, NULL}
};

/**
 * p_line - process line from the terminal
 * @file: file to read inputs from
 * @stack: pointer to the top of the stack
 * @line_number: pointer to line number in monty bytecode file
 * @instructions: pointer to the struct array
 */

void p_line(FILE *file, stack_t **stack, unsigned int *line_number,
instruction_t *instructions)
{
char *read;
char *line = NULL;
size_t len = 0;
char *opcode;
int i, found = 0;

while ((read = fgets(line, len, file)) != NULL)
{
(*line_number)++;

opcode = strtok(line, " \t\n");
/** argument = strtok(NULL, " \t\n");*/

for (i = 0; instructions[i].opcode != NULL; i++)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
{
instructions[i].f(stack, *line_number);
found = 1;
break;
}
}
if (!found)
{
fprintf(stderr, "L%u: unknown instruction %s\n", *line_number, opcode);
free_stack(stack);
exit(EXIT_FAILURE);
}
}
free(line);
}

/**
 * main - opens a monty script file for parsing
 * @argc: arguments count
 * @argv: arguments vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
FILE *file;
stack_t *stack = NULL;
unsigned int line_number = 0;
/**  char *argument;*/

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

p_line(file, &stack, &line_number, instructions);

fclose(file);
free_stack(&stack);
return (EXIT_SUCCESS);
}
