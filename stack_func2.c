#include "monty.h"

/**
 * add - adds th top two elements of the stack
 * @stack: points to head node of stack
 * @l_num: line number of opcode
 */
void add(stack_t **stack, unsigned int l_num)
{
	int sum;
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop - does nothing
 * @stack: points to head node of stack
 * @l_num: line number of opcode
 */
void nop(stack_t **stack, unsigned int l_num)
{
	(void) stack;
	(void) l_num;
}


