#include <stdio.h>
#include "dc.h"

/* print_head: the 'p' command.
 * Prints the head of the main stack, or "stack empty" if the stack has less
 * than one element. */
void
print_head(struct stack *s)
{
	if (stack_empty(s)) {
		puts("stack empty");
		return;
	}

	printf("%f\n", stack_head(s));
}

/* print_stack: the 'f' command.
 * Loops backwards through the stack, from its top to its bottom, printing its
 * elements. Prints "stack empty" if there are no elements in the stack. */
void
print_stack(struct stack *s)
{
	int i;

	if (stack_empty(s)) {
		puts("stack empty");
		return;
	}

	for (i = s->sp; i >= 0; --i) {
		printf("%f\n", s->stk[i]);
	}
}

/* pop_and_print: the 'P' comamnd.
 * Pops a value from the main stack and prints it, or prints "stack empty" if
 * there are no elements in the stack. */
void
pop_and_print(struct stack *s)
{
	double val;

	if (stack_pop(s, &val) == -1) {
		puts("stack empty");
		return;
	}

	printf("%f\n", val);
}

/* pop_and_print_nonl: the 'n' command.
 * Does the same as pop_and_print, but doesn't print a newline with the popped
 * value. */
void
pop_and_print_nonl(struct stack *s)
{
	double val;

	if (stack_pop(s, &val) == -1) {
		puts("stack empty");
		return;
	}

	printf("%f", val);
}
