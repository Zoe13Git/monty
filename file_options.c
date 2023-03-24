#include "monty.h"

/**
 * open_file - opens a file
 * @file: file path
 * Return: void
 */
void open_file(char *file)
{
	FILE *fd = fopen(file, "r");

	if (!file || !fd)
		fprintf(stderr, "Error: Can't open file %s\n", file);

	read_file(fd);
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
	{
		if (!buf)
		{
			fprintf(stderr, "malloc failed\n");
			exit(EXIT_FAILURE);
		}
		format = parse_line(buf, l_num, format);
	}
	free(buf);
}

/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buf: line from the file
 * @l_num: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int parse_line(char *buf, int l_num, int format)
{
	char *opcode, *value;
	const char *delim = " \n";

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
 * @l_num: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int l_num, int format)
{
	int i;
	int flag = 1;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", remove_top},
		{NULL, NULL}
	};

	for (i = 0; func_list[i].opcode; i++)
	{
		if (flag != 1)
			break;
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_func(func_list[i].f, opcode, value, l_num, format);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l_num, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * call_func - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @l_num: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_func(op_func func, char *op, char *val, int l_num, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (!val)
		{
			fprintf(stderr, "L%d: usage: push integer\n", l_num);
			 exit(EXIT_FAILURE);
		}
		else if (val[0] == '-')
		{
			val += 1;
			flag = -1;
		}

		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", l_num);
				exit(EXIT_FAILURE);
			}
		}

		node = create_node(atoi(val) * flag);

		if (format == 0)
			func(&node, l_num);

	}
	else
		func(&head, l_num);
}
