#include "push_swap.h"

void	sa(t_two_stacks ts, int is_printable)
{
	if (ts->a->len < 2)
		return ;
	dlist_move_cursor_to_tail(ts->a);
	values_p_swap(&ts->a->cursor_p->value, &ts->a->cursor_p->p->value);
	if (is_printable)
		write(1, "sa\n", 3);
}

void	sb(t_two_stacks ts, int is_printable)
{
	if (ts->b->len < 2)
		return ;
	dlist_move_cursor_to_tail(ts->b);
	values_p_swap(&ts->b->cursor_p->value, &ts->b->cursor_p->p->value);
	if (is_printable)
		write(1, "sb\n", 3);
}

void	ss(t_two_stacks ts, int is_printable)
{
	sa(ts, 0);
	sb(ts, 0);
	if (is_printable)
		write(1, "ss\n", 3);
}

void	pa(t_two_stacks ts, int is_printable)
{
	if (ts->b->len)
		push_to_stack(ts->a, pop_from_stack(ts->b));
	if (is_printable)
		write(1, "pa\n", 3);
}

void	pb(t_two_stacks ts, int is_printable)
{
	if (ts->a->len)
		push_to_stack(ts->b, pop_from_stack(ts->a));
	if (is_printable)
		write(1, "pb\n", 3);
}
