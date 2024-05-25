#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "dc.h"

/* Reads a number from the *cmd string if there's a digit. Pushes onto the main
 * stack. Returns -1 on failed push. */
static int
get_num(char **cmd, struct machine *m)
{
	int is_neg = (**cmd == '_');
	int is_dot = (**cmd == '.');

	if (is_neg)
		**cmd = '-';

	if (isdigit(**cmd) || is_neg || is_dot) {
		char	*cmdorig = *cmd;
		double	num = strtod(*cmd, cmd);

		if (*cmd == cmdorig && !is_dot) {
			puts("expected digit after _");
		} else if (machine_push(m, num, SMAIN) == -1) {
			print_err("get_num");
			return -1;
		}
	}

	return 0;
}

/* Executes commands in cmd. Returns -1 on failed push. */
static int
do_line(char *cmd, struct machine *m)
{
	int rv = 0;
	while (*cmd) {
		if (get_num(&cmd, m) == -1) {
			return -1;
		}

		switch (*cmd) {
			case '+':
				rv = add_nums(m->main_stack); //
				break;
			case '-':
				rv = sub_nums(m->main_stack); //
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

void
print_err(const char *s)
{
	fprintf(stderr, "failed allocation in function %s\n", s);
}

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
