#include "push_swap.h"

void			print_elem(void *e_)
{
	t_elem e;

	e = e_;
	printf("value : %d index: %d", e->value, e->index);
}

t_elem elem(int value, int index)
{
    t_elem celm;

	celm = malloc(sizeof(struct s_elem));
	celm->value = value;
	celm->index = index;
	return (celm);
}

void sort_elems(t_arrptr arr)
{
	t_elem che;
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < arr->len - 1)
	{
		while (j < arr->len - i - 1)	
		{
			if (((t_elem)arrptr_get(arr, j))->value > ((t_elem)arrptr_get(arr, j + 1))->value)
				vp_swap((arrptr_get(arr, j)), (arrptr_get(arr, j + 1)));
			j++;
		}
		i++;
	}
}

void simplify(t_dlist stack_a)
{
	t_arrptr sorted_elems;
	int i;

	i = 0;
	sorted_elems = empty_arrptr_create(NULL);
	dlist_move_cursor_to_head(stack_a);
	while (stack_a->cursor_n != stack_a->sentinel)
	{
		arrptr_add(sorted_elems, stack_a->cursor_n->value);
		dlist_move_cursor_to_next(stack_a);
	}
	sort_elems(sorted_elems);
	while (i < sorted_elems->len)
	{
		((t_elem)arrptr_get(sorted_elems, i))->index = i;
		i++;
	}
	arrptr_destroy(sorted_elems);
}