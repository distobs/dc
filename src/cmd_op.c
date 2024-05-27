#include <math.h>
#include <stdio.h>
#include "dc.h"

/* add_nums: the '+' command.
 * Pops two values and adds them both, pushing the result onto the stack.
 * Prints "stack empty" if there are less than two items in the stack,
 * returning from the function and leaving the stack unaltered. -1 is returned
 * if pushing fails, and 0 otherwise. */
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

/* sub_nums: the '-' command.
 * Pops two values and subtracts the first from the second, pushing the result
 * onto the stack. Prints "stack empty" if there are less than two items in the
 * stack, returning from the function and leaving the stack unaltered. -1 is
 * returned if pushing fails, and 0 otherwise. */
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

/* mul_nums: the '*' command.
 * Pops two values and multiplies them both, pushing the result onto the stack.
 * Prints "stack empty" if there are less than two items in the stack,
 * returning from the function and leaving the stack unaltered. -1 is returned
 * if pushing fails, and 0 otherwise. */
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

/* div_nums: The '/' command.
 * Pops two values and divides the second by the first, pushing the quotient to
 * the main stack. Prints "stack empty", and returns if there are less than two
 * items in the stack. If the first value popped is 0, "division by 0" is
 * printed and the popped value is pushed back onto the stack. -1 is returned
 * if pushing fails, and 0 is returned otherwise. */
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

		if (stack_push(s, val1) == -1) {
			print_err("div_nums");
			return -1;
		}

		return 0;
	}

	stack_pop(s, &val2);

	if (stack_push(s, val2 / val1) == -1) {
		print_err("div_nums");
		return -1;
	}

	return 0;
}

/* mod_nums: The '%' command.
 * Pops two values and divides the second by the first, pushing the remainder
 * to the main stack. Prints "stack empty", and returns if there are less than
 * two items in the stack. If the first value popped is 0, "division by 0" is
 * printed and the popped value is pushed back onto the stack. -1 is returned
 * if pushing fails, and 0 is returned otherwise. Doubles here are cast to
 * ints, so '10 .5 %' is a division by 0, and '10 2.9' is a division by 2. This
 * will be so until arbitrary precision is implemented. */
int
mod_nums(struct stack *s)
{
	double val1, val2;

	if (!stack_enough(s, 2)) {
		puts("stack empty");

		if (stack_push(s, val1) == -1) {
			print_err("mod_nums");
			return -1;
		}

		return 0;
	}

	stack_pop(s, &val1);

	if ((int)val1 == 0) {
		puts("division by 0");
	}

	stack_pop(s, &val2);

	if (stack_push(s, (int)val2 % (int)val1) == -1) {
		print_err("mod_nums");
		return -1;
	}

	return 0;
}

/* exp_nums: the '^' command.
 * Pops two values, the first being the exponent, and the second being the
 * base. Pushes the result of the base to the power of the exponent onto the
 * main stack. Prints "stack empty" if there are less than two items in the
 * stack, returning from the function and leaving the main stack unaltered.
 * Returns -1 if pushing fails, and 0 otherwise. */
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

/* sqrt_num: the 'v' command.
 * Pops one value and computes its square root, pushing it onto the stack.
 * Prints "stack empty" if there's less than one value in the stack, returning
 * from the function. Returns -1 on failed push, and 0 otherwise. */
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
 * Pops two values. Divides the second by the first, then pushes the quotient,
 * then the remainder. If there are less than 2 values in the stack, "stack
 * empty" is printed and 0 is returned, leaving the stack unaltered. When
 * comparing the divisor to 0, it's cast to an int like in mod_nums, so
 * '2 .3 ~' is a division by 0, and "division by 0" is printed, before pushing
 * the divisor to the stack again. Returns -1 on failed push, and 0 otherwise.
 */
int
divmod_nums(struct stack *s)
{
	double val1, val2;

	if (!stack_enough(s, 2)) {
		puts("stack empty");
		return 0;
	}

	stack_pop(s, &val1);

	if ((int)val1 == 0) {
		puts("division by zero");

		if (stack_push(s, val1) == -1) {
			print_err("divmod_nums");
			return -1;
		}

		return 0;
	}

	stack_pop(s, &val2);

	if (stack_push(s, val2 / val1) == -1) {
		return -1;
	}

	if (stack_push(s, (int)val2 % (int)val1) == -1) {
		print_err("divmod_nums");
		return -1;
	}

	return 0;
}

/* The '|' command.
 * Pops three values. The first is the modulus, the second is the exponent,
 * the third is the base. Calculates (base^exponent) % mod and pushes the
 * result onto the main stack. "stack empty" is printed if there are less than
 * two items in the stack, returning 0. Everything here is cast to an int, so
 * a modulo of '.5' means a division by 0. "division by 0" is printed and
 * the modulo is pushed back onto the stack if (int)mod == 0. Returns -1 if
 * pushing fails, and 0 otherwise. */
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

		if (stack_push(s, mod) == -1) {
			print_err("modexp_nums");
			return -1
		}

		return 0;
	}

	stack_pop(s, &exp);
	stack_pop(s, &base);

	/* :( */
	if (stack_push(s, (int)pow(base, exp) % (int)mod) == -1) {
		print_err("modexp_nums");
		return -1;
	}

	return 0;
}
