#include "dc.h"

/* Stack manipulation */
int
head_dup(struct stack *s)
{
	return stack_push(s, STACK_HEAD(s));
}
