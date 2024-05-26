#include <stdlib.h>
#include "machine.h"

/* machine_init:
 * This function initializes the main stack and sets all of the registers to
 * NULL, for lazy allocating them later. It returns -1 if allocating the main
 * stack fails, and 0 otherwise. */
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

/* machine_empty:
 * Returns true if reg's stack is empty, or if the main stack is empty if reg
 * == SMAIN */
int
machine_empty(struct machine *m, size_t reg)
{
	if (reg == SMAIN) {
		return stack_empty(m->main_stack);
	} else {
		return stack_empty(m->registers[reg]);
	}
}

/* machine_head:
 * Returns the value at the top of reg's stack, or that at the top of the main
 * stack if reg == SMAIN. */
double
machine_head(struct machine *m, size_t reg)
{
	if (reg == SMAIN) {
		return stack_head(m->main_stack);
	} else {
		return stack_head(m->registers[reg]);
	}
}

/* machine_pop:
 * Does a pop operation on reg's stack, or on the main stack if reg == SMAIN.
 * Stores the popped value inside val if val != NULL. Returns -1 if the stack
 * popped from is empty, and 0 otherwise. */
int
machine_pop(struct machine *m, double *val, size_t reg)
{
	if (reg == SMAIN) {
		return stack_pop(m->main_stack, val);
	} else {
		return stack_pop(m->registers[reg], val);
	}
}

/* machine_push:
 * Does a push operation on reg's stack, or on the main stack if reg == SMAIN.
 * Returns -1 on failed allocation if the stack is full, and 0 otherwise. */
int
machine_push(struct machine *m, double val, size_t reg)
{
	if (reg == SMAIN) {
		return stack_push(m->main_stack, val);
	} else {
		return stack_push(m->registers[reg], val);
	}
}

/* machine_destroy:
 * Destroys the main stack and frees the pointer to it inside the machine.
 * Destroys all the initialized registers and frees the pointers to them inside
 * the machine. */
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

/* register_init:
 * Allocates space for a register and initializes its stack. Returns -1 on
 * failed allocation, and 0 otherwise. */
int
register_init(struct machine *m, size_t reg)
{
	m->registers[reg] = malloc(sizeof(struct stack));

	if (m->registers[reg] == NULL) {
		return -1;
	}

	stack_init(m->registers[reg]);

	return 0;
}
