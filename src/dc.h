#ifndef DC_H
#define DC_H

#include "stack.h"

#define REGISTERS 256

struct machine {
	struct stack main_stack;
	struct stack registers[REGISTERS];
};

/* main */
int	do_line(char *cmd, struct machine *m);

/* dc_commands */
/** operations **/
int add_nums(struct stack *s);
int sub_nums(struct stack *s);
int mul_nums(struct stack *s);
int div_nums(struct stack *s);
int mod_nums(struct stack *s);
int exp_nums(struct stack *s);
int sqrt_num(struct stack *s);
int divmod_nums(struct stack *s);
int modexp_nums(struct stack *s);

/** printing **/
void print_head(struct stack *s);
void print_stack(struct stack *s);
void pop_and_print(struct stack *s);

/** stack manipulation **/
int head_dup(struct stack *s);

/* machine */
#define SMAIN (-1)
#define MACHINE_STACKP(m, reg)	((reg == SMAIN) ? (&(m->main_stack)) : \
				 (&(m->registers[reg])))
#define MACHINE_STACK_EMPTY(m, reg) (STACK_EMPTY(MACHINE_STACKP(m, reg)))

void	init_machine(struct machine *m);
double	machine_shead(struct machine *m, size_t reg);
int	machine_spop(struct machine *m, double *val, size_t reg);
int	machine_spush(struct machine *m, double val, size_t reg);
void	destroy_machine(struct machine *m);

/* registers */
int copy_from_reg_and_push(struct machine *m, size_t reg);
int pop_and_store_into_reg(struct machine *m, size_t reg);

#endif
