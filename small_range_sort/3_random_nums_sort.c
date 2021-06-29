#include "../push_swap.h"

void	get_the_numbers_into_arr(t_dlist s, int *arr)
{
	int	i;

	i = 0;
	dlist_move_cursor_to_tail(s);
	while (s->cursor_p != s->sentinel)
	{
		arr[i++] = ((t_elem)s->cursor_p->value)->value;
		dlist_move_cursor_to_previous(s);
	}
}

void	_3random_nums_sort(t_two_stacks ts)
{
	int	arr[3];

	get_the_numbers_into_arr(ts->a, arr);
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
		sa(ts, 1);
	else if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		sa(ts, 1);
		rra(ts, 1);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
		ra(ts, 1);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
	{
		sa(ts, 1);
		ra(ts, 1);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
		rra(ts, 1);
}
