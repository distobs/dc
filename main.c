#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "dc.h" /* #include "stack.h" */

int
do_line(char *cmd, struct machine *m)
{
	while (*cmd) {
		int is_neg = (*cmd == '_');

		if (is_neg)
			*cmd = '-';

		if (isdigit(*cmd) || is_neg) {
			char *cmdorig = cmd;
			if (stack_push(&(m->s), strtod(cmd, &cmd)) == -1) {
				return -1;
			} else if (cmd == cmdorig) {
				puts("expected digit or dot after _");
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
