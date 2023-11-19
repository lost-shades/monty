#include "monty.h"

/**
 * addnode - add node to the head stack.
 *
 * @head: head of the stack.
 * @n: new_value.
 *
 * Return: Nothing.
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * addqueue - add node to the tail stack.
 *
 * @n: new_value.
 * @head: head of the stack.
 *
 * Return: Nothing.
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}

/**
 * free_stack - frees a doubly linked list.
 *
 * @head: head of the stack.
 *
 * Return: Nothing.
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * exec - executes the opcode.
 *
 * @stack: head linked list - stack.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
int exec(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
	char *op;
	instruction_t opst[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", my_div},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{"queue", queue}, {"stack", op_stack}, {NULL, NULL}};

	op = strtok(data.line, " \n\t");
	if (op && op[0] == '#')
		return (0);
	data.value = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(data.file);
		free(data.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
