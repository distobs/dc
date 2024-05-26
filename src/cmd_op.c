#include <math.h>
#include <stdio.h>
#include "dc.h"

/* The '+' command.
 * Pops two values and adds them both. Returns -1 on failed push. */
int
add_nums(struct stack *s)
{
	double val1, val2;

	if (!stack_enough(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val1);
	stack_pop(s, &val2);

	if (stack_push(s, val2 + val1) == -1) {
		print_err("add_nums");
		return -1;
	}

	return 0;
}

/* The '-' command.
 * Pops two values and subtracts the first from the second. Returns -1 on
 * failed push. */
int
sub_nums(struct stack *s)
{
	double val1, val2;

	if (!stack_enough(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val1);
	stack_pop(s, &val2);

	if (stack_push(s, val2 - val1) == -1) {
		print_err("sub_nums");
		return -1;
	}

	return 0;
}

/* The '*' command.
 * Pops two values and multiplies them both. Returns -1 on failed push. */
int
mul_nums(struct stack *s)
{
	double val1, val2;

	if (!stack_enough(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val1);
	stack_pop(s, &val2);

	if (stack_push(s, val2 * val1) == -1) {
		print_err("mul_nums");
		return -1;
	}

	return 0;
}

/* The '/' command.
 * Pops two values and divides the second by the first. Returns -1 on failed
 * push. */
int
div_nums(struct stack *s)
{
	double val1, val2;

	if (!stack_enough(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val1);

	if (val1 == 0) {
		puts("division by 0");
		return 0;
	}

	stack_pop(s, &val2);

	if (stack_push(s, val2 / val1) == -1) {
		print_err("div_nums");
		return -1;
	}

	return 0;
}

/* The '%' command.
 * Pops two values and calculates the second one modulo the first one. Returns
 * -1 on failed push. */
int
mod_nums(struct stack *s)
{
	double val1, val2;

	if (!stack_enough(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val1);

	if ((int)val1 == 0) {
		puts("division by 0");
		return stack_push(s, val1);
	}

	stack_pop(s, &val2);

	if (stack_push(s, (int)val2 % (int)val1) == -1) {
		print_err("mod_nums");
		return -1;
	}

	return 0;
}

/* The '^' command.
 * Pops two values. The first is the exponent, the second is the base.
 * Calculates base to the power of exp. Returns -1 on failed push. */
int
exp_nums(struct stack *s)
{
	double base, exp;

	if (!stack_enough(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &exp);
	stack_pop(s, &base);

	if (stack_push(s, pow(base, exp)) == -1) {
		print_err("exp_nums");
		return -1;
	}

	return 0;
}

/* The 'v' command.
 * Pops one value and computes its square root. Returns -1 on failed push. */
int
sqrt_num(struct stack *s)
{
	double val;

	if (!stack_enough(s, 1)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val);

	if (stack_push(s, sqrt(val)) == -1) {
		print_err("sqrt_num");
		return -1;
	}

	return 0;
}

/* The '~' command.
 * Pops two values. Divide the second by the first. Push the quotient, then the
 * remainder. */
int
divmod_nums(struct stack *s)
{
	double val1, val2;

	if (!stack_enough(s, 2)) {
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

	if (stack_push(s, (int)val2 % (int)val1) == -1) {
		print_err("divmod_nums");
		return -1;
	}

	return 0;
}

/* The '|' command.
 * Pops three values. The first is the modulus, the second is the exponent,
 * the third is the base. Calculates (base^exponent) % mod. Returns -1 on
 * failed push. */
int
modexp_nums(struct stack *s)
{
	double mod, base, exp;

	if (!stack_enough(s, 3)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &mod);

	if ((int)mod == 0) {
		puts("division by 0");
		return stack_push(s, mod);
	}

	stack_pop(s, &exp);
	stack_pop(s, &base);

	/* :( */
	if (stack_push(s, (int)pow(base, exp) % (int)mod) == -1) {
		print_err("divmod_nums");
		return -1;
	}

	return 0;
}
