#include "dc.h" /* #include "stack.h" */

void
init_machine(struct machine *m)
{
	int i;
	stack_init(&(m->main_stack));

	for (i = 0; i < REGISTERS; ++i)
		stack_init(&(m->registers[i]));
}

void
destroy_machine(struct machine *m)
{
	int i;
	stack_destroy(&(m->main_stack));

	for (i = 0; i < REGISTERS; ++i)
		stack_destroy(&(m->registers[i]));
}
