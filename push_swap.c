/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:36:23 by khafni            #+#    #+#             */
/*   Updated: 2021/06/27 16:45:45by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*dlist_get_last_elem(t_dlist dl)
{
	if (dl->len == 0)
		return (NULL);
	dlist_move_cursor_to_head(dl);
	while (dl->cursor_n->n != dl->sentinel)
		dlist_move_cursor_to_next(dl);
	return (dl->cursor_n->value);
}

int	check_if_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (j != i && !strcmp(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_two_stacks	ts;

	if (check_if_duplicates(argc, argv))
	{
		printf("Error\n");
		return (0);
	}
	if (argc < 3)
		return (0);
	ts = get_arguments_(argc, argv);
	if (ts->a->len == 3)
		_3random_nums_sort(ts);
	else if (ts->a->len == 5)
		_5random_nums_sort(ts);
	else
		radix_sort(ts);
	return (0);
}
