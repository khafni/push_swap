/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:36:23 by khafni            #+#    #+#             */
/*   Updated: 2021/03/28 17:38:58 by khafni           ###   ########.fr       */
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

/* int main()
{
	t_two_stacks ts;

	ts = empty_two_stacks();
	dlist_pushback(ts->b, intdub(1));
	dlist_pushback(ts->b, intdub(2));
	dlist_pushback(ts->b, intdub(3));
	dlist_pushback(ts->b, intdub(4));
	dlist_pushback(ts->b, intdub(5));
	dlist_print(ts->a, " , ");
	dlist_print(ts->b, " , ");	


	rrb(ts);
	rrb(ts);
	//rb(ts);

	printf("\n");
	dlist_print(ts->a, " , ");	
	dlist_print(ts->b, " , ");	
	two_stacks_destroy(ts);
} */