#include <stdio.h>
#include "dc.h" /* #include "stack.h" */

/* Operations */
int
add_nums(struct stack *s)
{
	double val1, val2;

	if (stack_pop(s, &val1) == -1) {
		puts("stack empty");
		return 0;
	}

	if (stack_pop(s, &val2) == -1) {
		puts("stack empty");
		stack_push(s, val1);
		return 0;
	}

	if (stack_push(s, val2 + val1) == -1)
		return -1;

	return 0;
}

int
sub_nums(struct stack *s)
{
	double val1, val2;

	if (stack_pop(s, &val1) == -1) {
		puts("stack empty");
		return 0;
	}

	if (stack_pop(s, &val2) == -1) {
		puts("stack empty");
		stack_push(s, val1);
		return 0;
	}

	if (stack_push(s, val2 - val1) == -1)
		return -1;

	return 0;
}

int
mul_nums(struct stack *s)
{
	double val1, val2;

	if (stack_pop(s, &val1) == -1) {
		puts("stack empty");
		return 0;
	}

	if (stack_pop(s, &val2) == -1) {
		puts("stack empty");
		stack_push(s, val1);
		return 0;
	}

	if (stack_push(s, val2 * val1) == -1)
		return -1;

	return 0;
}

int
div_nums(struct stack *s)
{
	double val1, val2;

	if (stack_pop(s, &val1) == -1) {
		puts("stack empty");
		return 0;
	}

	if (stack_pop(s, &val2) == -1) {
		puts("stack empty");
		stack_push(s, val1);
		return 0;
	}

	if (stack_push(s, val2 / val1) == -1)
		return -1;

	return 0;
}

/* Printing */
void
print_head(struct stack *s)
{
	if (STACK_EMPTY(s)) {
		puts("stack empty");
		return;
	}

	printf("%f\n", s->stk[s->head]);
}

void
pop_and_print(struct stack *s)
{
	double val;

	if (stack_pop(s, &val) == -1) {
		puts("stack empty");
		return;
	}

	printf("%f\n", val);

}

/* Stack manipulation */
int
head_dup(struct stack *s)
{
	return stack_push(s, stack_head(s));
}

/* Registers */
int
copy_from_reg_and_push(struct machine *m, size_t reg)
{
	if (MACHINE_STACK_EMPTY(m, reg)) {
		puts("register stack empty");
		return 0;
	}

	if (machine_spush(m, machine_shead(m, reg), SMAIN)
	    == -1)
		return -1;

	return 0;
}

int
pop_and_store_into_reg(struct machine *m, size_t reg)
{
	double val;

	if (machine_spop(m, &val, SMAIN) == -1) {
		puts("stack empty");
		return 0;
	}

	if (machine_spush(m, val, reg) == -1)
		return -1;

	return 0;
}
