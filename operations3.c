#include "push_swap.h"

void	rrr(t_two_stacks ts, int is_printable)
{
	rra(ts, 0);
	rrb(ts, 0);
	if (is_printable)
		write(1, "rrr\n", 4);
}

int	is_dlist_sorted(t_dlist l)
{
	int		is_sort;
	t_elem	val1;
	t_elem	val2;

	is_sort = 1;
	if (l->len < 2)
		return (1);
	dlist_move_cursor_to_head(l);
	while (l->cursor_n->n != l->sentinel)
	{	
		val1 = ((t_elem)(l->cursor_n->value));
		val2 = ((t_elem)(l->cursor_n->n->value));
		if (val1->value < val2->value)
			is_sort = 0;
		dlist_move_cursor_to_next(l);
	}
	return (is_sort);
}
