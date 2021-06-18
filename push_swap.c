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

void			print_int(void *num)
{
	printf("%d", *((int*)num));
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
/* 	sa(ts);
	pb(ts);
	pb(ts);
	pb(ts);
	ra(ts);
	rb(ts);
	rra(ts);
	rrb(ts);
	sa(ts);
	pa(ts);
	pa(ts);
	pa(ts); */

	
	



	/* dlist_move_cursor_to_head(ts->a);
	while (ts->a->cursor_n != ts->a->sentinel)
	{
		printf("%d", *(int*)(ts->a->cursor_n->value));
		dlist_move_cursor_to_next(ts->a);
	}
	printf("\n-----------------------------\n");
	while (ts->b->cursor_n != ts->b->sentinel)
	{
		printf("%d", *(int*)(ts->b->cursor_n->value));
		dlist_move_cursor_to_next(ts->b);
	} */
	
	/* int *val = pop_from_stack(ts->a);
	while (val)
	{
		printf("%d\n", *val);
		val = pop_from_stack(ts->a);
	} */
	return (0);
}