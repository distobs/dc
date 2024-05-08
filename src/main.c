#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "dc.h" /* #include "stack.h" */

int
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

			if (cmd == cmdorig && !is_dot) {
				puts("expected digit after _");
				break;
			} else if (stack_push(MACHINE_STACKP(m, SMAIN), num) == -1) {
				return -1;
			}
		}

		switch (*cmd) {
			case '+':
				rv = add_nums(MACHINE_STACKP(m, SMAIN));
				break;
			case '-':
				rv = sub_nums(MACHINE_STACKP(m, SMAIN));
				break;
			case '*':
				rv = mul_nums(MACHINE_STACKP(m, SMAIN));
				break;
			case '/':
				rv = div_nums(MACHINE_STACKP(m, SMAIN));
				break;
			case 'c':
				stack_clean(MACHINE_STACKP(m, SMAIN));
				break;
			case 'd':
				rv = head_dup(MACHINE_STACKP(m, SMAIN));
				break;
			case 'f':
				print_stack(MACHINE_STACKP(m, SMAIN));
				break;
			case 'l':
				rv = copy_from_reg_and_push(m, *(++cmd));
				break;
			case 's':
				rv = pop_and_store_into_reg(m, *(++cmd));
				break;
			case 'P':
				pop_and_print(MACHINE_STACKP(m, SMAIN));
				break;
			case 'p':
				print_head(MACHINE_STACKP(m, SMAIN));
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

	/* never reached */
	return 0;
}
