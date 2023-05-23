#include "monty.h"


void print_line(void)
{
	int i;

	for (i = 0; global.line[i]; i++) {
		if (global.line[i][0] == '\0') {
			printf("[%d]: %s\n", i, "\\0");
		} else if (global.line[i][0] == '\n') {
			printf("[%d]: %s\n", i, "\n");
		} else {
			printf("[%d]: %s\n", i, global.line[i]);
		}
	}

	printf("\n");
}

/**
 * main - entry point
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0 on success
*/
int main(int ac, char **av)
{
	FILE *file = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	unsigned int line_number = 0;

	global.line = NULL;
	global.file = NULL;
	global.stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	global.file = file;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		if (line[0] == '\n')
			continue;
		global.line = split(line, " \n\t\r");
		if (global.line[0] != NULL)
			get_op_func(global.line[0])(&global.stack, line_number);
		free(global.line);
	}

	free(line);
	free_all(global.stack, file);
	return (EXIT_SUCCESS);
}
