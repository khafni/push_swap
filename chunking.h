/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:48:03 by khafni            #+#    #+#             */
/*   Updated: 2021/06/18 13:17:01 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNKING_H
# define CHUNKING_H
# include <stdlib.h>
# include "dlist/dlists.h"
# include "CPCA/generic_parrays/garrptr.h"
# include "CPCA/generic_parrays/parray_heaps/parr_heap.h"

typedef struct s_chunk_elem *t_chunk_elem;

struct s_chunk_elem
{
	int value;
	int chunk_num;	
};

t_chunk_elem elem_chunk(int value, int chunk_num);
void chunk_from_sa_to_sb(t_dlist st_a, t_dlist st_b);
void			print_chunk_e(void *chunk);
int calculate_n_of_chunks(t_dlist stack);
#endif