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
	//printf("|%d %d %d|\n", arr[0], arr[1], arr[2]);
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
	else if(arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
		rra(ts, 1);
}


void _5random_nums_sort(t_two_stacks ts)
{
	int arr[5] = {0, 0, 0, 0, 0};

	pb(ts, 1);
	pb(ts, 1);
	_3random_nums_sort(ts);
	get_the_numbers_into_arr(ts->b, arr);	
	pa(ts, 1);
	dlist_move_cursor_to_tail(ts->a);
	get_the_numbers_into_arr(ts->a, arr);
	if (arr[3] > arr[2])
		ra(ts, 1);
	pa(ts, 1);
	dlist_move_cursor_to_tail(ts->a);
	get_the_numbers_into_arr(ts->a, arr);
	if (arr[4] > arr[3])
		ra(ts, 1);
}