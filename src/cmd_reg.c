#include <stdio.h>
#include "dc.h"

int
copy_from_reg_and_push(struct machine *m, size_t reg)
{
	if (MACHINE_STACK_EMPTY(m, reg)) {
		puts("register stack empty");
		return 0;
	}

	if (machine_spush(m, machine_shead(m, reg), SMAIN)
	    == -1)
		return -1;

	return 0;
}

int
pop_and_store_into_reg(struct machine *m, size_t reg)
{
	double val;

	if (machine_spop(m, &val, SMAIN) == -1) {
		puts("stack empty");
		return 0;
	}

	if (machine_spush(m, val, reg) == -1)
		return -1;

	return 0;
}
