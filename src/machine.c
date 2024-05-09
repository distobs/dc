#include "machine.h"

void
init_machine(struct machine *m)
{
	int i;
	stack_init(STACKP(m, SMAIN));

	for (i = 0; i < REGISTERS; ++i)
		stack_init(STACKP(m, i));
}

double
machine_shead(struct machine *m, size_t reg)
{
	return (STACK_HEAD(STACKP(m, reg)));
}

int
machine_spop(struct machine *m, double *val, size_t reg)
{
	return (stack_pop(STACKP(m, reg), val));
}

int
machine_spush(struct machine *m, double val, size_t reg)
{
	return (stack_push(STACKP(m, reg), val));
}

void
destroy_machine(struct machine *m)
{
	int i;
	stack_destroy(STACKP(m, SMAIN));

	for (i = 0; i < REGISTERS; ++i)
		stack_destroy(STACKP(m, i));
}
