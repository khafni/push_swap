/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_methods2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:23:50 by khafni            #+#    #+#             */
/*   Updated: 2021/06/30 11:31:54 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstr.h"

int	is_rstr_eq_cstr(t_rstr rs, char *cstr)
{
	int	i;	

	i = 0;
	while (i < rs->len)
	{
		if (rs->data[i] != cstr[i])
			return (0);
		i++;
	}
	return (1);
}

void	print_rstr(t_rstr rs)
{
	int		i;
	char	c;

	i = 0;
	while (i < rs->len)
	{
		c = rstr_get(rs, i);
		write(1, &c, 1);
		i++;
	}
}
