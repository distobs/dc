#include <math.h>
#include <stdio.h>
#include "dc.h"

int
add_nums(struct stack *s)
{
	double val1, val2;

	if (!STACK_ENOUGH(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val1);
	stack_pop(s, &val2);

	if (stack_push(s, val2 + val1) == -1)
		return -1;

	return 0;
}

int
sub_nums(struct stack *s)
{
	double val1, val2;

	if (!STACK_ENOUGH(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val1);
	stack_pop(s, &val2);

	if (stack_push(s, val2 - val1) == -1)
		return -1;

	return 0;
}

int
mul_nums(struct stack *s)
{
	double val1, val2;

	if (!STACK_ENOUGH(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val1);
	stack_pop(s, &val2);

	if (stack_push(s, val2 * val1) == -1)
		return -1;

	return 0;
}

int
div_nums(struct stack *s)
{
	double val1, val2;

	if (!STACK_ENOUGH(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val1);

	if (val1 == 0) {
		puts("division by 0");
		return 0;
	}

	stack_pop(s, &val2);

	if (stack_push(s, val2 / val1) == -1)
		return -1;

	return 0;
}

int
mod_nums(struct stack *s)
{
	double val1, val2;

	if (!STACK_ENOUGH(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val1);

	if (val1 == 0) {
		puts("division by 0");
		return stack_push(s, val1);
	}

	stack_pop(s, &val2);

	return stack_push(s, (int)val2 % (int)val1);
}

int
exp_nums(struct stack *s)
{
	double base, exp;

	if (!STACK_ENOUGH(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &exp);
	stack_pop(s, &base);

	return stack_push(s, pow(base, exp));
}

int
sqrt_num(struct stack *s)
{
	double val;

	if (!STACK_ENOUGH(s, 1)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val);

	return stack_push(s, sqrt(val));
}

int
divmod_nums(struct stack *s)
{
	double val1, val2;

	if (!STACK_ENOUGH(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val1);

	if (val1 == 0) {
		puts("division by zero");
		return stack_push(s, val1);
	}

	stack_pop(s, &val2);

	if (stack_push(s, val2 / val1) == -1)
		return -1;

	return stack_push(s, (int)val2 % (int)val1);
}

int
modexp_nums(struct stack *s)
{
	double mod, base, exp;

	if (!STACK_ENOUGH(s, 3)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &mod);

	if (mod == 0) {
		puts("mod can't be 0");
		return stack_push(s, mod);
	}

	stack_pop(s, &exp);
	stack_pop(s, &base);

	/* :( */
	return stack_push(s, (int)pow(base, exp) % (int)mod);
}
