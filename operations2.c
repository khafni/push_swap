#include "push_swap.h"

void			ra(t_two_stacks ts)
{
	void	*elem;

	if (ts->a->len == 0)
		return ;
	dlist_move_cursor_to_head(ts->a);
	elem = ts->a->cursor_n->value;
	dlist_remove_after_cursor(ts->a, 0);
	dlist_pushback(ts->a, elem);
}


void			rb(t_two_stacks ts)
{
	void	*elem;

	if (ts->b->len == 0)
		return ;
	dlist_move_cursor_to_head(ts->b);
	elem = ts->b->cursor_n->value;
	dlist_remove_after_cursor(ts->b, 0);
	dlist_pushback(ts->b, elem);
}

void			rr(t_two_stacks ts)
{
	ra(ts);
	rb(ts);
}

void			rra(t_two_stacks ts)
{
	void	*elem;

	if (ts->a->len == 0)
		return ;
	dlist_move_cursor_to_tail(ts->a);
	elem = ts->a->cursor_p->value;
	dlist_remove_before_cursor(ts->a, 0);
	dlist_move_cursor_to_head(ts->a);
	dlist_insert_after_cursor(ts->a, elem);
}

void			rrb(t_two_stacks ts)
{
	void	*elem;

	if (ts->b->len == 0)
		return ;
	dlist_move_cursor_to_tail(ts->b);
	elem = ts->b->cursor_p->value;
	dlist_remove_before_cursor(ts->b, 0);
	dlist_move_cursor_to_head(ts->b);
	dlist_insert_after_cursor(ts->b, elem);
}