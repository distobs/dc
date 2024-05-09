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
		} else if (stack_push(STACKP(m, SMAIN), num) == -1) {
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
		if (get_num(&cmd, m) == -1)
			return -1;

		switch (*cmd) {
			case '+':
				rv = add_nums(STACKP(m, SMAIN));
				break;
			case '-':
				rv = sub_nums(STACKP(m, SMAIN));
				break;
			case '*':
				rv = mul_nums(STACKP(m, SMAIN));
				break;
			case '/':
				rv = div_nums(STACKP(m, SMAIN));
				break;
			case '%':
				rv = mod_nums(STACKP(m, SMAIN));
				break;
			case '^':
				rv = exp_nums(STACKP(m, SMAIN));
				break;
			case '~':
				rv = divmod_nums(STACKP(m, SMAIN));
				break;
			case '|':
				rv = modexp_nums(STACKP(m, SMAIN));
				break;
			case 'c':
				STACK_CLEAN(STACKP(m, SMAIN));
				break;
			case 'd':
				rv = head_dup(STACKP(m, SMAIN));
				break;
			case 'f':
				print_stack(STACKP(m, SMAIN));
				break;
			case 'l':
				rv = copy_from_reg_and_push(m, *(++cmd));
				break;
			case 's':
				rv = pop_and_store_into_reg(m, *(++cmd));
				break;
			case 'v':
				rv = sqrt_num(STACKP(m, SMAIN));
				break;
			case 'P':
				pop_and_print(STACKP(m, SMAIN));
				break;
			case 'p':
				print_head(STACKP(m, SMAIN));
				break;
			default:
				break;
		}

		if (rv == -1)
			return -1;
		else
			++cmd;
	}

	return rv;
}

int
main(void)
{
	char		buf[1024];
	struct machine	m;

	init_machine(&m);

	while (1) {
		if (fgets(buf, 1024, stdin) == NULL) {
			if (ferror(stdin)) {
				destroy_machine(&m);
				exit(1);
			} else if (feof(stdin)) {
				destroy_machine(&m);
				exit(0);
			}
		}

		if (do_line(buf, &m) == -1) {
			destroy_machine(&m);
			exit(1);
		}
	}

	return 0;
}
