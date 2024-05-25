#include <stdio.h>
#include "dc.h"

/* The 'lR' command.
 * Copies a value from the 'R' register's stack and pushes onto the main stack.
 * Returns -1 on failed push. */
int
copy_from_reg_and_push(struct machine *m, size_t reg)
{
	if (machine_empty(m, reg)) {
		puts("register stack empty");
		return 0;
	}

	if (machine_push(m, machine_head(m, reg), SMAIN) == -1)
		return -1;

	return 0;
}

/* The 'sR' command.
 * Pops a value from the main stack register and pushes onto the 'R' register's
 * stack. Returns -1 on failed push. */
int
pop_and_store_into_reg(struct machine *m, size_t reg)
{
	double val;

	if (machine_pop(m, &val, SMAIN) == -1) {
		puts("stack empty");
		return 0;
	}

	if (machine_push(m, val, reg) == -1)
		return -1;

	return 0;
}
