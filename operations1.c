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
	if (ts->b->len)
		push_to_stack(ts->a, pop_from_stack(ts->b));
}


void			pb(t_two_stacks ts)
{
	if (ts->a->len)
		push_to_stack(ts->b, pop_from_stack(ts->a));
}