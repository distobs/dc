#include <stdlib.h>
#include "stack.h" /* #include <sys/types.h> <stddef.h> */

void
stack_clean(struct stack *s)
{
	s->head = -1;
}

void
stack_destroy(struct stack *s)
{
	free(s->stk);
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
	if (STACK_EMPTY(s))
		return -1;

	*val = s->stk[s->head--];

	return 0;
}

int
stack_push(struct stack *s, double val)
{
	/* converting to ssize_t to avoid underflow in the cases where
	 * size = 0. */
	if (s->head == ((ssize_t)s->size - 1)) {
		if (stack_grow(s) == -1)
			return -1;
	}

	s->stk[++s->head] = val;

	return 0;
}
