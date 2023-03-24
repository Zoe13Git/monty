#include "monty.h"

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

/**
 * print_char - prints char at top of stack
 * @stack: points to the head of the stack
 * @l_num: line number of opcode
 */
void print_char(stack_t **stack, unsigned int l_num)
{
        if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);

}

/**
 * print_string - prints string from top of stack
 * @stack: points to the head of the stack
 * @l_num: line number of opcode
 */
void print_string(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	(void) l_num;
	if (!stack || !(*stack))
		printf("\n");
	tmp = *stack;
	while (tmp)
	{
		if (tmp->n == 0 || tmp->n > 127)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
