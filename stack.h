#ifndef STACK_H
#define STACK_H

#include <sys/types.h>
#include <stddef.h>

#define GROW_BY 50

struct stack {
	double	*stk;
	ssize_t	 head;
	size_t	 size;
};

void	stack_clean(struct stack *s);
void	stack_destroy(struct stack *s);
int	stack_grow(struct stack *s);
double	stack_head(struct stack *s);
void	stack_init(struct stack *s);
int	stack_pop(struct stack *s, double *val);
int	stack_push(struct stack *s, double val);

#endif
