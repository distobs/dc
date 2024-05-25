#ifndef STACK_H
#define STACK_H

#include <sys/types.h>

/* How much space to realloc if the stack is full. */
#define GROW_BY 50

struct stack {
	double	*stk;	/* The stack. */
	ssize_t	 head;	/* (stack empty) ? -1 : the stack's head */
	size_t	 size;	/* The size allocated for the stack. */
};

#define STACK_CLEAN(s)	(s->head = -1)
#define STACK_EMPTY(s)	(s->head == -1)
#define STACK_HEAD(s)	(s->stk[s->head])

void	stack_destroy(struct stack *s);
int	stack_enough(struct stack *s, unsigned needed);
int	stack_grow(struct stack *s);
void	stack_init(struct stack *s);
int	stack_pop(struct stack *s, double *val);
int	stack_push(struct stack *s, double val);

#endif
