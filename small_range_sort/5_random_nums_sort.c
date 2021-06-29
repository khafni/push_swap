#include "../push_swap.h"

int	get_min_num(t_dlist l)
{
	if (!l->len)
		return (-420);
	dlist_move_cursor_to_head(l);
	while (l->cursor_n != l->sentinel)
	{
		if (((t_elem)l->cursor_n->value)->index == 0)
			return (((t_elem)l->cursor_n->value)->value);
		dlist_move_cursor_to_next(l);
	}
	return (-420);
}

int	ra_or_rra(t_two_stacks ts, int min_num)
{	
	int	count1;
	int	count2;

	count1 = 0;
	count2 = 0;
	dlist_move_cursor_to_head(ts->a);
	while (ts->a->cursor_n != ts->a->sentinel)
	{
		if (((t_elem)ts->a->cursor_n->value)->value == min_num)
			break ;
		count1++;
		dlist_move_cursor_to_next(ts->a);
	}
	dlist_move_cursor_to_tail(ts->a);
	while (ts->a->cursor_p != ts->a->sentinel)
	{
		if (((t_elem)ts->a->cursor_p->value)->value == min_num)
			break ;
		count2++;
		dlist_move_cursor_to_previous(ts->a);
	}
	if (count1 < count2)
		return (RRA);
	return (RA);
}

void	push_smallest_number_to_sb(t_two_stacks ts, int min_num)
{
	t_elem	em;

	if (ra_or_rra(ts, min_num) == RA)
	{
		em = get_stack_top_el(ts->a);
		while (em->index != min_num)
		{
			ra(ts, 1);
			em = get_stack_top_el(ts->a);
		}
		pb(ts, 1);
	}
	else
	{
		em = get_stack_top_el(ts->a);
		while (em->index != min_num)
		{
			rra(ts, 1);
			em = get_stack_top_el(ts->a);
		}
		pb(ts, 1);
	}
}

void	_5random_nums_sort(t_two_stacks ts)
{
	int	min_num;

	min_num = get_min_num(ts->a);
	push_smallest_number_to_sb(ts, 0);
	min_num = get_min_num(ts->a);
	push_smallest_number_to_sb(ts, 1);
	_3random_nums_sort(ts);
	pa(ts, 1);
	pa(ts, 1);
}
