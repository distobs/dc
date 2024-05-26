#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "dc.h"


/* do_line:
 * This function takes a line read by the main loop and parses it, pushing
 * numbers to the stack and executing commands it finds. It loops through the
 * string, and, if a number is found, it is pushed to the main stack and the
 * cmd pointer is increased to the next character which is not a valid part of
 * a number. Then, it tries to read a command. If a valid command is found,
 * its respective function is called and that function's return value is stored
 * inside rv, which is returned if it's equal to -1, indicating an error. If a
 * line is read succesfully and all commands and pushes are executed without
 * errors, 0 is returned. */
static int
do_line(char *cmd, struct machine *m)
{
	int rv = 0;
	while (*cmd) {
		int is_neg = (*cmd == '_');
		int is_dot = (*cmd == '.');

		if (is_neg)
			*cmd = '-';

		if (isdigit(*cmd) || is_neg || is_dot) {
			char	*cmdorig = cmd;
			double	num = strtod(cmd, &cmd);

			/* !is_dot: a single dot just means 0.0 is pushed. */
			if (cmd == cmdorig && !is_dot) {
				puts("expected digit after _");
			} else if (machine_push(m, num, SMAIN) == -1) {
				print_err("do_line");
				return -1;
			}
		}

		switch (*cmd) {
			case '+':
				rv = add_nums(m->main_stack);
				break;
			case '-':
				rv = sub_nums(m->main_stack);
				break;
			case '*':
				rv = mul_nums(m->main_stack);
				break;
			case '/':
				rv = div_nums(m->main_stack);
				break;
			case '%':
				rv = mod_nums(m->main_stack);
				break;
			case '^':
				rv = exp_nums(m->main_stack);
				break;
			case '~':
				rv = divmod_nums(m->main_stack);
				break;
			case '|':
				rv = modexp_nums(m->main_stack);
				break;
			case 'c':
				stack_destroy(m->main_stack);
				break;
			case 'd':
				rv = head_dup(m->main_stack);
				break;
			case 'f':
				print_stack(m->main_stack);
				break;
			case 'l':
				rv = copy_from_reg_and_push(m, *(++cmd));
				break;
			case 'n':
				pop_and_print_nonl(m->main_stack);
				break;
			case 's':
				rv = pop_and_store_into_reg(m, *(++cmd));
				break;
			case 'v':
				rv = sqrt_num(m->main_stack);
				break;
			case 'P':
				pop_and_print(m->main_stack);
				break;
			case 'p':
				print_head(m->main_stack);
				break;
			default:
				break;
		}

		if (rv == -1) {
			return -1;
		} else {
			++cmd;
		}
	}

	return rv;
}

/* print_err:
 * This function is used for printing fatal errors. For now, the only fatal
 * error we are dealing with is failed allocation, though this function could
 * be extended in the future. Functions outside the machine.c and stack.c files
 * that report a failed allocation should print this as soon as possible with
 * its name as an argument, to indicate where it happened. */
void
print_err(const char *s)
{
	fprintf(stderr, "failed allocation in function %s\n", s);
}

/* main:
 * This is the main function. It initializes the program machine and runs on an
 * infinite loop, reading lines up to 1024 characters. If it finds an EOF, the
 * program returns with exit value 0. If it finds an error when reading stdin,
 * the program returns 1. In both of this cases, it destroys the machine before
 * exiting. After performing this check, do_line is called and, if anything it
 * does fails, the machine is destroyed and the program exits with status 1. */
int
main(void)
{
	char		buf[1024];
	struct machine	m;

	machine_init(&m);

	while (1) {
		if (fgets(buf, 1024, stdin) == NULL) {
			if (ferror(stdin)) {
				machine_destroy(&m);
				exit(1);
			} else if (feof(stdin)) {
				machine_destroy(&m);
				exit(0);
			}
		}

		if (do_line(buf, &m) == -1) {
			machine_destroy(&m);
			exit(1);
		}
	}

	return 0;
}
