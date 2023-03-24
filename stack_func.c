#include "monty.h"
/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @l_num: Interger representing the line number of of the opcode.
 */
void add_to_stack(stack_t **new_node, unsigned int l_num)
{
	stack_t *tmp;

	(void) l_num;
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * print_top - prints top element of stack
 * @stack: pointer to head node of stack
 * @l_num: line number of opcode
 */
void print_top(stack_t **stack, unsigned int l_num)
{
	(void) l_num;

	if (!stack)
		exit(EXIT_FAILURE);
	if (*stack)
		printf("%d\n", (*stack)->n);
}

/**
 * remove_top - pop
 * @stack: pointer to head node of stack
 * @l_num: line number of opcode
 */
void remove_top(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	(void) l_num;
	if (!stack)
		exit(EXIT_FAILURE);
	tmp = *stack;
	if (tmp)
	{
		if (!tmp->next)
			*stack = NULL;
		else
		{
			*stack = tmp->next;
			(*stack)->prev = NULL;
		}
		free(tmp);
	}

}
