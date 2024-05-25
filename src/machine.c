#include "machine.h"

/* stack_inits the whole machine */
void
init_machine(struct machine *m)
{
	stack_init(m->main_stack);

	for (size_t i = 0; i < REGISTERS; ++i)
		stack_init(m->registers[i]);
}

/* Returns reg register's stack's head, or the main stack's head if reg ==
 * SMAIN. CAUTION: always check for empty stack before using. */
double
machine_shead(struct machine *m, size_t reg)
{
	if (reg == SMAIN) {
		return STACK_HEAD(m->main_stack);
	} else {
		return STACK_HEAD(m->registers[reg]);
	}
}

/* Pops from the reg register's stack, or from the main stack if reg == SMAIN.
 * Returns -1 on empty stack. */
int
machine_spop(struct machine *m, double *val, size_t reg)
{
	if (reg == SMAIN) {
		return stack_pop(m->main_stack, val);
	} else {
		return stack_pop(m->registers[reg], val);
	}
}

/* Pushes onto the reg register's stack, or onto the main stack if reg ==
 * SMAIN. Returns -1 on failed push. */
int
machine_spush(struct machine *m, double val, size_t reg)
{
	if (reg == SMAIN) {
		return stack_push(m->main_stack, val);
	} else {
		return stack_push(m->registers[reg], val);
	}
}

/* stack_destroys the whole machine */
void
destroy_machine(struct machine *m)
{
	int i;
	stack_destroy(m->main_stack);

	for (i = 0; i < REGISTERS; ++i)
		stack_destroy(m->registers[i]);
}
