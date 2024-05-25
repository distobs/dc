#ifndef MACHINE_H
#define MACHINE_H

#include <sys/types.h>
#include "stack.h"

#define REGISTERS 256
struct machine {
	struct stack *main_stack;
	struct stack *registers[REGISTERS];
};

#define SMAIN (-1)

void	machine_destroy(struct machine *m);
int	machine_empty(struct machine *m, size_t reg);
double	machine_head(struct machine *m, size_t reg);
int	machine_init(struct machine *m);
int	machine_pop(struct machine *m, double *val, size_t reg);
int	machine_push(struct machine *m, double val, size_t reg);
int	register_init(struct machine *m, size_t reg);

#endif
