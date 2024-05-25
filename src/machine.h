#ifndef MACHINE_H
#define MACHINE_H

#include "stack.h"

#define REGISTERS 256
struct machine {
	struct stack *main_stack;
	struct stack *registers[REGISTERS];
};

#define SMAIN				(-1)
#define MACHINE_STACK_EMPTY(m, reg)	(stack_empty(m-

void	destroy_machine(struct machine *m);
void	init_machine(struct machine *m);
double	machine_shead(struct machine *m, size_t reg);
int	machine_spop(struct machine *m, double *val, size_t reg);
int	machine_spush(struct machine *m, double val, size_t reg);

#endif
