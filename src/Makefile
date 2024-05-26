SRC = cmd_op.c cmd_print.c cmd_reg.c cmd_smanip.c machine.c main.c stack.c

ifeq ($(DEBUG), 1)
	CFLAGS = -o dc -pedantic -std=c99 -Wall -O0 -lm -ggdb3 \
		 -fsanitize=address,undefined
else
	CFLAGS = -o dc -pedantic -std=c99 -Wall -O2 -lm
endif

all: dc

dc: ${SRC}
	$(CC) ${CFLAGS} ${SRC}

clean:
	rm dc
