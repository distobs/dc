#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "dc.h" /* #include "stack.h" */

int
do_line(char *cmd, struct machine *m)
{
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
			} else if (stack_push(&(m->s), num) == -1) {
				return -1;
			}
		}

		switch (*cmd) {
			case '+':
				if (add_nums(&(m->s)) == -1)
					return -1;
				break;
			case '-':
				if (sub_nums(&(m->s)) == -1)
					return -1;
				break;
			case '*':
				if (mul_nums(&(m->s)) == -1)
					return -1;
				break;
			case '/':
				if (div_nums(&(m->s)) == -1)
					return -1;
				break;
			case 'c':
				stack_clean(&(m->s));
				break;
			case 'd':
				if (head_dup(&(m->s)) == -1)
					return -1;
				break;
			case 'l':
				if (copy_from_reg_and_push(m, *(++cmd)) == -1)
					return -1;
				break;
			case 's':
				if (pop_and_store_into_reg(m, *(++cmd)) == -1)
					return -1;
				break;
			case 'P':
				pop_and_print(&(m->s));
				break;
			case 'p':
				print_head(&(m->s));
				break;
			default:
				break;
		}

		++cmd;
	}

	return 0;
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
				destroy_machine(&(m));
				exit(1);
			} else if (feof(stdin)) {
				destroy_machine(&(m));
				exit(0);
			}
		}

		if (do_line(buf, &m) == -1) {
			destroy_machine(&(m));
			exit(1);
		}
	}

	/* never reached */
	return 0;
}
