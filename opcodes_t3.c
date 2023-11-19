#include "monty.h"

/**
 * sub - subtraction function.
 *
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int sus, nodes;

	temp = *head;
	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(data.file);
		free(data.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sus = temp->next->n - temp->n;
	temp->next->n = sus;
	*head = temp->next;
	free(temp);
}

/**
 * swap - adds the top two elements of the stack.
 *
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void swap(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(data.file);
		free(data.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
