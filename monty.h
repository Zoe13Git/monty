#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void open_file(char *file);
void read_file(FILE *);

int parse_line(char *buf, int l_num, int format);
void find_func(char *opcode, char *value, int l_num, int format);
void call_func(op_func func, char *op, char *val, int ln, int format);


stack_t *create_node(int n);
void add_to_stack(stack_t **new_node, unsigned int);
void print_stack(stack_t **stack, unsigned int);
void free_nodes(void);






#endif
