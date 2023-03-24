#include "monty.h"
#include <stdio.h>

/**
 * open_file - opens a file
 * @file: file path
 * Return: void
 */
void open_file(char *file)
{
	FILE *fd = fopen(file, "r");

	if (!file || !fd)
		err(2, file);

	read_file(FILE *fd)
	fclose(fd);

}

/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */
void read_file(FILE *fd)
{
	int l_num, format = 0;
	char *buf = NULL;
	size_t len = 0;

	for (l_num = 1; getline(&buf, &len, fd) != -1; l_num++)
		format = parse_line(buf, l_num, format);

	free(buffer);
}

/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int parse_line(char *buf, int l_num, int format)
{
	char *opcode, *value;
	const char *delim = " \n";

	if (!buf)
		err(4);

	opcode = strtok(buf, delim);
	if (!opcode)
		return (format);
	value = strtok(NULL, delim);

	find_func(opcode, value, l_num, format);
	return (format);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int l_num, int format)
{
	stack_t *node;
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes}
		{"NULL", "NULL"}
	}

	for (i = 0, flag = 1; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			node = create_node(atoi(val) * flag);
			func_list[i](&node, l_num);
			flag = 0;
		}
	}
}

