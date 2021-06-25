#include "chunking.h"

void			print_chunk_e(void *chunk)
{
	t_chunk_elem che;

	che = chunk;
	printf("value : %d chunk: %d", che->value, che->chunk_num);
}

t_chunk_elem elem_chunk(int value, int chunk_num)
{
	t_chunk_elem celm;

	celm = malloc(sizeof(struct s_chunk_elem));
	celm->value = value;
	celm->chunk_num = chunk_num;
	return (celm);
}

//void chunk_from_sa_to_sb(t_dlist st_a, t_dlist st_b);

int calculate_n_of_chunks(t_dlist stack)
{
	int which_chunk;
	t_chunk_elem achunk;
	int n_chunks;
	
	n_chunks = 1;
	dlist_move_cursor_to_tail(stack);
	which_chunk = ((t_chunk_elem)(stack->cursor_p->value))->chunk_num;
	while (stack->cursor_p != stack->sentinel)
	{
		if (which_chunk != ((t_chunk_elem)(stack->cursor_p->value))->chunk_num)
		{
			n_chunks++;
			which_chunk = ((t_chunk_elem)(stack->cursor_p->value))->chunk_num;
		}
		dlist_move_cursor_to_previous(stack);
	}
	return (n_chunks);
}

/* t_arrptr fill_sorted_array_from_chnk(t_dlist stack)
{
	int which_chunk;
	t_arrptr arr;

	arr = empty_arrptr_create(NULL);
	which_chunk = ((t_chunk_elem)(stack->cursor_p->value))->chunk_num;
	while (stack->cursor_p != stack->sentinel)
	{
		if (which_chunk != ((t_chunk_elem)(stack->cursor_p->value))->chunk_num)	
			break;	
		arrptr_add(arr, stack->cursor_p->value);
		dlist_move_cursor_to_previous(stack);
	}
	return (arr);
} */

void sort_array(t_arrptr arr)
{
	t_chunk_elem che;
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < arr->len - 1)
	{
		while (j < arr->len - i - 1)	
		{
			if (((t_chunk_elem)arrptr_get(arr, j))->value > ((t_chunk_elem)arrptr_get(arr, j + 1))->value)
				vp_swap((arrptr_get(arr, j)), (arrptr_get(arr, j + 1)));
			j++;
		}
		i++;
	}
}
/* int find_mid_value(t_arrptr sorted_array)
{

} */

void chunk_f_a_t_b(t_dlist st_a, t_dlist st_b, t_arrptr chunk_sorted_array)
{
	int mid_value;

	mid_value = ((t_chunk_elem)arrptr_get(chunk_sorted_array, chunk_sorted_array->len / 2))->value;
	dlist_move_cursor_to_tail(st_a);
	while (st_a->cursor_p != st_a->sentinel)
	{
		achunk = st_a->cursor_p->value;
		if (which_chunk != ((t_chunk_elem)(st_a->cursor_p->value))->chunk_num)	
			break ;
		dlist_move_cursor_to_previous(st_a);
	}
}

void chunk_from_sa_to_sb(t_dlist st_a, t_dlist st_b)
{
	int which_chunk;
	t_chunk_elem achunk;
	t_arrptr sorted_array;
	
	sorted_array = empty_arrptr_create(NULL);
	dlist_move_cursor_to_tail(st_a);
	which_chunk = ((t_chunk_elem)(st_a->cursor_p->value))->chunk_num;
	while (st_a->cursor_p != st_a->sentinel)
	{
		achunk = st_a->cursor_p->value;
		if (which_chunk != ((t_chunk_elem)(st_a->cursor_p->value))->chunk_num)	
			break ;
		arrptr_add(sorted_array, elem_chunk(achunk->value, achunk->chunk_num));
		printf("|%d|\n", ((t_chunk_elem)(st_a->cursor_p->value))->value);
		dlist_move_cursor_to_previous(st_a);
	}
	sort_array(sorted_array);
	chunk_f_a_t_b(st_a, st_b, sorted_array);
	/* for (int i = 0; i < sorted_array->len; i++)
	{	
		printf("%d\n", ((t_chunk_elem)arrptr_get(sorted_array, i))->value);
	} */
}

