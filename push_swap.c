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
			if (j != i && !ft_strcmp(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_nums(char *argv[])
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (argv[i])
	{
		j = 0;
		count = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] != '-') && (argv[i][j] < '0' || argv[i][j] > '9'))
				return (0);
			count++;
			j++;
		}
		if (count > 9)
			return (0);
		i++;
	}
	return (1);
}
