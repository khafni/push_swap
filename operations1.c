#include "push_swap.h"

void			sa(t_two_stacks ts)
{
	int a;
	int b;
	int tmp;

	if (ts->a->len < 2)
		return ;
	dlist_move_cursor_to_tail(ts->a);
	a = *(int*)(ts->a->cursor_p->value); 
	b = *(int*)(ts->a->cursor_p->p->value);
	values_p_swap(&ts->a->cursor_p->value,  &ts->a->cursor_p->p->value);
}

void			sb(t_two_stacks ts)
{
	int a;
	int b;
	int tmp;
	
	if (ts->b->len < 2)
		return ;
	dlist_move_cursor_to_tail(ts->b);
	a = *(int*)(ts->b->cursor_p->value); 
	b = *(int*)(ts->b->cursor_p->p->value);
	values_p_swap(&ts->b->cursor_p->value,  &ts->b->cursor_p->p->value);
}


void			ss(t_two_stacks ts)
{
	sa(ts);
	sb(ts);
}

void			pa(t_two_stacks ts)
{
	void	*elem;

	if (ts->b->len == 0)
		return ;
	dlist_move_cursor_to_tail(ts->b);
	elem = ts->b->cursor_p->value;
	dlist_remove_before_cursor(ts->b, 0);
	dlist_pushback(ts->a, elem);
}


void			pb(t_two_stacks ts)
{
	void	*elem;

	if (ts->a->len == 0)
		return ;
	dlist_move_cursor_to_tail(ts->a);
	elem = ts->a->cursor_p->value;
	dlist_remove_before_cursor(ts->a, 0);
	dlist_pushback(ts->b, elem);
}