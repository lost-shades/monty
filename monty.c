#include "monty.h"

data_t data = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter.
*
* @argc: arguments count
* @argv: argument vector
* Return: 0 Success OR STD Error.
*/
int main(int argc, char *argv[])
{
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	data.file = fopen(argv[1], "r");
	if (!data.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		data.line = NULL;
		read_line = getline(&data.line, &size, data.file);
		line_number++;
		if (read_line > 0)
		{
			exec(&stack, line_number);
		}
		free(data.line);
	}
	free_stack(stack);
	fclose(data.file);
return (0);
}
