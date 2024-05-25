#include <stdlib.h>
#include "stack.h"

void
stack_destroy(struct stack *s)
{
	s->head = -1;
	s->size = 0;
	free(s->stk);
}

int
stack_empty(struct stack *s)
{
	return (s->head == -1);
}

int
stack_enough(struct stack *s, unsigned needed)
{
	return (s->head >= (needed - 1));
}

int
stack_grow(struct stack *s)
{
	s->stk = realloc(s->stk, (s->size += GROW_BY) * sizeof(s->stk[0]));

	return (s->stk == NULL) ? -1 : 0;
}

void
stack_init(struct stack *s)
{
	s->stk = NULL;
	s->size = 0;
	s->head = -1;
}

int
stack_pop(struct stack *s, double *val)
{
	if (stack_empty(s))
		return -1;

	*val = s->stk[s->head--];

	return 0;
}

int
stack_push(struct stack *s, double val)
{
	if (s->size == 0 || s->head == (s->size - 1)) {
		if (stack_grow(s) == -1)
			return -1;
	}

	s->stk[++s->head] = val;

	return 0;
}
