#include "push_swap.h"

void			ra(t_two_stacks ts, int is_printable)
{
	void	*elem;

	if (ts->a->len < 2)
		return ;
	dlist_move_cursor_to_tail(ts->a);
	elem = ts->a->cursor_p->value;
	dlist_remove_before_cursor(ts->a, 0);
	dlist_move_cursor_to_head(ts->a);
	dlist_insert_after_cursor(ts->a, elem);
	if (is_printable)
		write(1, "ra\n", 3);
}


void			rb(t_two_stacks ts, int is_printable)
{
	void	*elem;

	if (ts->b->len < 2)
		return ;
	dlist_move_cursor_to_tail(ts->b);
	elem = ts->b->cursor_p->value;
	dlist_remove_before_cursor(ts->b, 0);
	dlist_move_cursor_to_head(ts->b);
	dlist_insert_after_cursor(ts->b, elem);
	if (is_printable)
		write(1, "rb\n", 3);

	
}

void			rr(t_two_stacks ts, int is_printable)
{
	ra(ts, 0);
	rb(ts, 0);
	if (is_printable)
		write(1, "rr\n", 3);
}

void			rra(t_two_stacks ts, int is_printable)
{
	void	*elem;

	if (ts->a->len < 2)
		return ;
	dlist_move_cursor_to_head(ts->a);
	elem = ts->a->cursor_n->value;
	dlist_remove_after_cursor(ts->a, 0);
	dlist_pushback(ts->a, elem);
	if (is_printable)
		write(1, "rra\n", 4);
}

void			rrb(t_two_stacks ts, int is_printable)
{
	void	*elem;

	if (ts->b->len < 2)
		return ;
	dlist_move_cursor_to_head(ts->b);
	elem = ts->b->cursor_n->value;
	dlist_remove_after_cursor(ts->b, 0);
	dlist_pushback(ts->b, elem);
	if (is_printable)
		write(1, "rrb\n", 4);
}