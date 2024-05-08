#include "dc.h"

void
init_machine(struct machine *m)
{
	int i;
	stack_init(MACHINE_STACKP(m, SMAIN));

	for (i = 0; i < REGISTERS; ++i)
		stack_init(MACHINE_STACKP(m, i));
}

double
machine_shead(struct machine *m, size_t reg)
{
	return (stack_head(MACHINE_STACKP(m, reg)));
}

int
machine_spop(struct machine *m, double *val, size_t reg)
{
	return (stack_pop(MACHINE_STACKP(m, reg), val));
}

int
machine_spush(struct machine *m, double val, size_t reg)
{
	return (stack_push(MACHINE_STACKP(m, reg), val));
}

void
destroy_machine(struct machine *m)
{
	int i;
	stack_destroy(MACHINE_STACKP(m, SMAIN));

	for (i = 0; i < REGISTERS; ++i)
		stack_destroy(MACHINE_STACKP(m, i));
}
