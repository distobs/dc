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
	if (s->head == -1) {
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
	return stack_push(s, s->stk[s->head]);
}

/* Registers */
int
copy_from_reg_and_push(struct machine *m, unsigned char reg)
{
	if (stack_push(&(m->s), m->r[reg].stk[m->r[reg].head]) == -1)
		return -1;

	return 0;
}

int
pop_and_store_into_reg(struct machine *m, unsigned char reg)
{
	double val;

	if (stack_pop(&(m->s), &val) == -1) {
		puts("stack empty");
		return 0;
	}

	if (stack_push(&(m->r[reg]), val) == -1)
		return -1;

	return 0;
}
