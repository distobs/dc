#include <stdio.h>
#include "stack.h"

int
add_nums(struct stack *s)
{
	double val1, val2;

	if (stack_pop(s, &val1) == -1) {
		puts("stack empty");
		return 0;
	}

	if (stack_pop(s, &val2) == -1) {
		puts("stack empty");
		stack_push(s, val1);
		return 0;
	}

	if (stack_push(s, val2 + val1) == -1)
		return -1;

	return 0;
}

int
sub_nums(struct stack *s)
{
	double val1, val2;

	if (stack_pop(s, &val1) == -1) {
		puts("stack empty");
		return 0;
	}

	if (stack_pop(s, &val2) == -1) {
		puts("stack empty");
		stack_push(s, val1);
		return 0;
	}

	if (stack_push(s, val2 - val1) == -1)
		return -1;

	return 0;
}

int
mul_nums(struct stack *s)
{
	double val1, val2;

	if (stack_pop(s, &val1) == -1) {
		puts("stack empty");
		return 0;
	}

	if (stack_pop(s, &val2) == -1) {
		puts("stack empty");
		stack_push(s, val1);
		return 0;
	}

	if (stack_push(s, val2 * val1) == -1)
		return -1;

	return 0;
}

int
div_nums(struct stack *s)
{
	double val1, val2;

	if (stack_pop(s, &val1) == -1) {
		puts("stack empty");
		return 0;
	}

	if (stack_pop(s, &val2) == -1) {
		puts("stack empty");
		stack_push(s, val1);
		return 0;
	}

	if (stack_push(s, val2 / val1) == -1)
		return -1;

	return 0;
}
