#include "dc.h" /* #include "stack.h" */

void
init_machine(struct machine *m)
{
	int i;
	stack_init(&(m->s));

	for (i = 0; i < REGISTERS; ++i)
		stack_init(&(m->r[i]));
}

void
destroy_machine(struct machine *m)
{
	int i;
	stack_destroy(&(m->s));

	for (i = 0; i < REGISTERS; ++i)
		stack_destroy(&(m->r[i]));
}
