/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:36:23 by khafni            #+#    #+#             */
/*   Updated: 2021/06/18 16:19:40 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_int(void *chunk)
{
	t_chunk_elem che;

	che = chunk;
	printf("value : %d chunk: %d", che->value, che->chunk_num);
}

t_two_stacks empty_two_stacks(void)
{
	t_two_stacks ts;

	ts = malloc(sizeof(struct s_two_stacks));
	ts->a = dlist_empty_create(free, NULL, print_int);
	ts->b = dlist_empty_create(free, NULL, print_int);
	ts->args_number = 0;
	return (ts);
}

void			two_stacks_destroy(t_two_stacks ts)
{
	dlist_destroy(ts->a);
	dlist_destroy(ts->b);
	free(ts);
}

void			values_p_swap(void **v1_, void **v2_)
{
	void *tmp;

	tmp = *v1_;
	*v1_ = *v2_;
	*v2_ = tmp;
}

int *intdub(int n)
{
	int *int_ptr;
	
	int_ptr = malloc(sizeof(int));
	*int_ptr = n;
	return (int_ptr);
}

t_two_stacks get_arguments_(int argc, char **argv)
{
	t_two_stacks	ts;
	int				i;	

	ts = empty_two_stacks();
	i = 1;
	ts->args_number = argc - 1;
	//numbers = ft_split(argv[1], ' ');

		while (i <= ts->args_number)
		{
			dlist_pushback(ts->a, elem_chunk(atoi(argv[i]), 0));
			i++;
		}
	//dlist_move_cursor_to_head(ts->a);
	return (ts);
}

void *dlist_get_last_elem(t_dlist dl)
{
	if (dl->len == 0)
		return (NULL);	
	dlist_move_cursor_to_head(dl);
	while (dl->cursor_n->n != dl->sentinel)
	{
		dlist_move_cursor_to_next(dl);
	}
	return dl->cursor_n->value;
}

int main(int argc, char *argv[])
{

	
	
	t_two_stacks ts;
	//printf("%s", argv[1]);
	ts = get_arguments_(argc, argv);
	// dlist_print(ts->a, " \n ");	
	//sa(ts);
	pb(ts);	
	pb(ts);	
	pb(ts);	
	pb(ts);	
	pb(ts);	
	pb(ts);	
	pb(ts);	
	pb(ts);	
	pb(ts);	
	
	if (is_dlist_sorted(ts->a))
		printf("it is sorted\n");
	else
		printf("not sorted\n");
	printf("\n\n");
	print_stack(ts->a, " \n ");	
	return (0);
}