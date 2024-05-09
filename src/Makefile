SRC = cmd_op.c cmd_print.c cmd_reg.c cmd_smanip.c machine.c main.c stack.c

#CFLAGS = -o dc -pedantic -std=c99 -Wall
CFLAGS = -o dc -pedantic -std=c99 -Wall -O0 -g -lm

all: dc

dc: ${SRC}
	$(CC) ${CFLAGS} ${SRC}

clean:
	rm dc
