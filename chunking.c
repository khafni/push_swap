#include "chunking.h"

t_chunk_elem elem_chunk(int value, int chunk_num)
{
	t_chunk_elem celm;

	celm = malloc(sizeof(struct s_chunk_elem));
	celm->value = value;
	celm->chunk_num = chunk_num;
	return (celm);
}

