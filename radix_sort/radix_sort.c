#include "../push_swap.h"

void radix_sort_helper(t_two_stacks ts, int which_bit)
{
	int i;
	int init_stacka_len;

	i = 0;
	init_stacka_len = ts->a->len;
	dlist_move_cursor_to_head(ts->a);

	while (i < init_stacka_len)
	{
		if (((((t_elem)get_stack_top_el(ts->a))->index >> which_bit) & 1))	
			ra(ts, 1);		
		else	
			pb(ts, 1);		
		i++;
	}

	i = 0;
	dlist_move_cursor_to_head(ts->b);
	while (ts->b->len)	
		pa(ts, 1);	
}
int get_max_num(t_dlist l)
{
	int max_num;

	if (!l->len)
		return (-420);
	dlist_move_cursor_to_head(l);
	max_num = ((t_elem)l->cursor_n->value)->index;
	while (l->cursor_n != l->sentinel)
	{
		if (max_num < ((t_elem)l->cursor_n->value)->index)	
			max_num = ((t_elem)l->cursor_n->value)->index;
		dlist_move_cursor_to_next(l);
	}
	return (max_num);
}
void radix_sort(t_two_stacks ts)
{
	int which_bit;
	int max_num;
	int max_bits = 0;

	which_bit = 0;
	max_num = get_max_num(ts->a);
	while ((max_num >> max_bits))
		++max_bits;
	while (which_bit < max_bits)
	{
		radix_sort_helper(ts, which_bit);
		which_bit++;
	}	
} 