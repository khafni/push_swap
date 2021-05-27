#include "push_swap.h"

void			rrr(t_two_stacks ts)
{
	rra(ts);
	rrb(ts);
}

int		is_dlist_sorted(t_dlist l)
{
	int is_sort;
	int val1;
	int val2;

	is_sort = 1;
	dlist_move_cursor_to_head(l);
	while (l->cursor_n->n != l->sentinel)
	{
		val1 = *(int*)l->cursor_n->value;
		val2 = *(int*)l->cursor_n->n->value;
		if (val1 > val2)
			is_sort = 0;
		dlist_move_cursor_to_next(l);
	}
	return (is_sort);
}