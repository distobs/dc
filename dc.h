#ifndef DC_H
#define DC_H

#include "stack.h" /* #include <sys/types.h> <stddef.h> */

#define REGISTERS 256

struct machine {
	struct stack s;
	struct stack r[REGISTERS];
};

/* main */
int	do_line(char *cmd, struct machine *m);
void	init_machine(struct machine *m);

/* dc_commands */
/** operations **/
int add_nums(struct stack *s);
int sub_nums(struct stack *s);
int mul_nums(struct stack *s);
int div_nums(struct stack *s);

/** printing **/
void print_head(struct stack *s);
void pop_and_print(struct stack *s);

/** stack manipulation **/
int head_dup(struct stack *s);

/* machine */
void	init_machine(struct machine *m);
void	destroy_machine(struct machine *m);

/* registers */
int pop_and_store_into_reg(struct machine *m, unsigned char reg);

#endif
