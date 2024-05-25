#include <stdlib.h>
#include "machine.h"

/* stack_inits the whole machine */
int
machine_init(struct machine *m)
{
	m->main_stack = malloc(sizeof(struct stack));

	if (m->main_stack == NULL) {
		return -1;
	}

	stack_init(m->main_stack);

	for (size_t i = 0; i < REGISTERS; ++i) {
		m->registers[i] = NULL;
	}

	return 0;
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
	free(m->main_stack);

	for (i = 0; i < REGISTERS; ++i) {
		if (m->registers[i] != NULL) {
			stack_destroy(m->registers[i]);
			free(m->registers[i]);
		}
	}
}

int
register_init(struct machine *m, size_t reg)
{
	m->registers[reg] = malloc(sizeof(struct stack));

	if (m->registers[reg] == NULL) {
		return -1;
	}

	return 0;
}
