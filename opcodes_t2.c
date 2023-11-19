#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 *
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(data.file);
		free(data.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

/**
 * my_div - divides the top two elements of the stack.
 *
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void my_div(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(data.file);
		free(data.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(data.file);
		free(data.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n / h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 *
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void mod(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(data.file);
		free(data.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(data.file);
		free(data.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n % h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

/**
 * mul - multiplies the top two elements of the stack.
 *
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void mul(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(data.file);
		free(data.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->next->n * h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

/**
 * nop- nothing.
 *
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)data;
	(void)line_number;
	(void)head;
}
