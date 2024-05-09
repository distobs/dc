#include "machine.h"

/* stack_inits the whole machine */
void
init_machine(struct machine *m)
{
	int i;
	stack_init(STACKP(m, SMAIN));

	for (i = 0; i < REGISTERS; ++i)
		stack_init(STACKP(m, i));
}

/* Returns reg register's stack's head, or the main stack's head if reg ==
 * SMAIN. CAUTION: always check for empty stack before using. */
double
machine_shead(struct machine *m, size_t reg)
{
	return (STACK_HEAD(STACKP(m, reg)));
}

/* Pops from the reg register's stack, or from the main stack if reg == SMAIN.
 * Returns -1 on empty stack. */
int
machine_spop(struct machine *m, double *val, size_t reg)
{
	return (stack_pop(STACKP(m, reg), val));
}

/* Pushes onto the reg register's stack, or onto the main stack if reg ==
 * SMAIN. Returns -1 on failed push. */
int
machine_spush(struct machine *m, double val, size_t reg)
{
	return (stack_push(STACKP(m, reg), val));
}

/* stack_destroys the whole machine */
void
destroy_machine(struct machine *m)
{
	int i;
	stack_destroy(STACKP(m, SMAIN));

	for (i = 0; i < REGISTERS; ++i)
		stack_destroy(STACKP(m, i));
}
