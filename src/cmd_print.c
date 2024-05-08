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
pop_and_print(struct stack *s)
{
	double val;

	if (stack_pop(s, &val) == -1) {
		puts("stack empty");
		return;
	}

	printf("%f\n", val);
}
