#include <stdlib.h>
#include "machine.h"

/* stack_inits the whole machine */
void
machine_init(struct machine *m)
{
	m->main_stack = malloc(sizeof(struct stack));
	stack_init(m->main_stack);

	for (size_t i = 0; i < REGISTERS; ++i) {
		m->registers[i] = malloc(sizeof(struct stack));
		stack_init(m->registers[i]);
	}
}

int
machine_empty(struct machine *m, size_t reg)
{
	if (reg == SMAIN) {
		return stack_empty(m->main_stack);
	} else {
		return stack_empty(m->registers[reg]);
	}
}

/* Returns reg register's stack's head, or the main stack's head if reg ==
 * SMAIN. CAUTION: always check for empty stack before using. */
double
machine_head(struct machine *m, size_t reg)
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
machine_pop(struct machine *m, double *val, size_t reg)
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
machine_push(struct machine *m, double val, size_t reg)
{
	if (reg == SMAIN) {
		return stack_push(m->main_stack, val);
	} else {
		return stack_push(m->registers[reg], val);
	}
}

/* stack_destroys the whole machine */
void
machine_destroy(struct machine *m)
{
	int i;
	stack_destroy(m->main_stack);

	for (i = 0; i < REGISTERS; ++i) {
		stack_destroy(m->registers[i]);
	}
}
