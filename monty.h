#ifndef MONTY_H
#define MONTY_H


/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


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
} _stack_t;

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
	void (*f)(_stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global Variable */
typedef struct global_s
{
	FILE *file;
	char **line;
	int line_number;
	_stack_t *stack;
} global_t;

global_t global;

/* auxiliary functions */
void (*get_op_func(char *s))(_stack_t **stack, unsigned int line_number);
void free_stack(_stack_t *head);
void free_all(_stack_t *head, FILE *fd);
int is_number(char *str);
char **split(char *str, char *delim);

/* opcode functions */
void _push(_stack_t **stack, unsigned int line_number);
void _pall(_stack_t **stack, unsigned int line_number);
void _pint(_stack_t **stack, unsigned int line_number);
void _pop(_stack_t **stack, unsigned int line_number);
void _swap(_stack_t **stack, unsigned int line_number);
void _add(_stack_t **stack, unsigned int line_number);
void _nop(_stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
