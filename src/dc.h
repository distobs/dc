#ifndef DC_H
#define DC_H

#include "machine.h"

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
void pop_and_print_nonl(struct stack *s);

/* registers */
int copy_from_reg_and_push(struct machine *m, size_t reg);
int pop_and_store_into_reg(struct machine *m, size_t reg);

/** stack manipulation **/
int head_dup(struct stack *s);

#endif
