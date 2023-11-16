#include "monty.h"

/**
* swap - swaps the top two elements of the stack
* @stack: pointer to the top of the stack
* @line_number: line number in the Monty bytecode file
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	temp = first->n;
	first->n = second->n;
	second->n = temp;
}

#include "monty.h"

/**
* nop - doesn't do anything
* @stack: pointer to the top of the stack
* @line_number: line number in the Monty bytecode file
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
* add - adds the top two elements of the stack
* @stack: pointer to the top of the stack
* @line_number: line number in the Monty bytecode file
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
