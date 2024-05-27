#include <stdio.h>
#include "dc.h"

/* head_dup: the 'd' command.
 * Pushes the main stack's head to the main stack itself, duplicating it. The
 * user is warned and 0 is returned if the stack is empty. Returns -1 on failed
 * pushing, and 0 otherwise. */
int
head_dup(struct stack *s)
{
	if (stack_empty(s)) {
		puts("stack emtpy");
		return 0;
	}

	if (stack_push(s, stack_head(s)) == -1) {
		print_err("head_dup");
		return -1;
	}

	return 0;
}
