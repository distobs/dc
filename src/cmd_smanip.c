#include "dc.h"

/* The 'd command.
 * Duplicates the main stack's head. */
int
head_dup(struct stack *s)
{
	if (stack_push(s, stack_head(s)) == -1) {
		print_err("head_dup");
		return -1;
	}

	return 0;
}
