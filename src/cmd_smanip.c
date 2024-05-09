#include "dc.h"

/* The 'd command.
 * Duplicates the main stack's head. */
int
head_dup(struct stack *s)
{
	return stack_push(s, STACK_HEAD(s));
}
