/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:48:23 by khafni            #+#    #+#             */
/*   Updated: 2021/06/29 19:56:55 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_two_stacks	ts;

	if (check_if_duplicates(argc, argv) || !check_if_nums(argv))
	{
		printf("Error\n");
		return (0);
	}
	if (argc < 3)
		return (0);
	ts = get_arguments_(argc, argv);
	if (is_dlist_sorted(ts->a))
	{
		two_stacks_destroy(ts);
		return (0);
	}
	if (ts->a->len == 3)
		_3random_nums_sort(ts);
	else if (ts->a->len == 5)
		_5random_nums_sort(ts);
	else
		radix_sort(ts);
	return (0);
}
