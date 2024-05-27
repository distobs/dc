#include <stdio.h>
#include "dc.h"
#include "machine.h"

/* copy_from_reg_and_push: the 'lR' command.
 * Pushes the specified register's head onto the main stack. If this is that
 * register's first use, it is then initialized. If the register's stack is
 * empty, or if the register specified, when converted to an integer, is more
 * than the maximum number of registers, the user is warned and 0 is returned.
 * Returns -1 on failed push, or on failed register initialization, and 0
 * otherwise. */
int
copy_from_reg_and_push(struct machine *m, size_t reg)
{
	if (reg > REGISTERS) {
		printf("%c is an invalid register.\n", (unsigned char)reg);
		return 0;
	}

	if (m->registers[reg] == NULL) {
		if (register_init(m, reg) == -1) {
			print_err("copy_from_reg_and_push");
			return -1;
		}
	}

	if (machine_empty(m, reg)) {
		puts("register stack empty");
		return 0;
	}

	if (machine_push(m, machine_head(m, reg), SMAIN) == -1) {
		print_err("copy_from_reg_and_push");
		return -1;
	}

	return 0;
}

/* pop_and_store_into_reg: the 'sR' command.
 * Pops a value from the main stack register and pushes it to the specified
 * register's stack. If this is that register's first use, it is initialized
 * before pushing. If the main stack is empty, or if the specified register,
 * when converted to an integer, is greater than the maximum number of
 * registers, the user is warned and 0 is returned. Returns -1 on failed push,
 * or on failed register initialization, and 0 otherwise. */
int
pop_and_store_into_reg(struct machine *m, size_t reg)
{
	double val;

	if (reg > REGISTERS) {
		printf("%c is an invalid register.\n", (unsigned char)reg);
		return 0;
	}

	if (m->registers[reg] == NULL) {
		if (register_init(m, reg) == -1) {
			print_err("pop_and_store_into_reg");
			return -1;
		}
	}

	if (machine_pop(m, &val, SMAIN) == -1) {
		puts("stack empty");
		return 0;
	}

	if (machine_push(m, val, reg) == -1) {
		print_err("pop_and_store_into_reg");
		return -1;
	}

	return 0;
}
