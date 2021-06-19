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

t_arrptr fill_sorted_array_from_chnk(t_dlist stack)
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
		if (st_a->cursor_n != )
		dlist_move_cursor_to_previous(st_a);
	}

}

