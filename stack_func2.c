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
 * sub - subtracts top element from second top element
 * @stack: points to head node of stack
 * @l_num: line number of opcode
 */
void sub(stack_t **stack, unsigned int l_num)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->n -= (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divide - divides seond top element by stop element
 * @stack: points to head node of stack
 * @l_num: line number of opcode
 */
void divide(stack_t **stack, unsigned int l_num)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_num);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n /= (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul - subtracts top element from second top element
 * @stack: points to head node of stack
 * @l_num: line number of opcode
 */
void mul(stack_t **stack, unsigned int l_num)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->n *= (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod - computes rest of div of second top by top element
 * @stack: points to head node of stack
 * @l_num: line number of opcode
 */
void mod(stack_t **stack, unsigned int l_num)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_num);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n %= (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

