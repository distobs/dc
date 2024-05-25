#include <stdio.h>
#include "dc.h"

/* The 'p' command.
 * Prints the head of the main stack. */
void
print_head(struct stack *s)
{
	if (stack_empty(s)) {
		puts("stack empty");
		return;
	}

	printf("%f\n", stack_head(s));
}

/* The 'f' command.
 * Prints the whole main stack. */
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

/* The 'P' comamnd.
 * Pops a value from the main stack and prints it. */
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

/* The 'n' command.
 * Pops a value from the main stack and prints it without a newline. */
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
