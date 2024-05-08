#include <stdio.h>
#include "stack.h"

void
print_head(struct stack *s)
{
	if (STACK_EMPTY(s)) {
		puts("stack empty");
		return;
	}

	printf("%f\n", s->stk[s->head]);
}

void
print_stack(struct stack *s)
{
	int i;

	if (STACK_EMPTY(s)) {
		puts("stack empty");
		return;
	}

	for (i = 0; i <= s->head; ++i) {
		printf("%f\n", s->stk[i]);
	}
}

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
