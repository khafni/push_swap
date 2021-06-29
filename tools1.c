/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:06:22 by khafni            #+#    #+#             */
/*   Updated: 2021/03/31 14:07:53 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstr.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tdst;
	const char	*tsrc;

	tdst = dst;
	tsrc = src;
	if (dst == src && n == 1)
		return (dst);
	if (!tsrc && !tdst)
		return (0);
	while (n > 0)
	{
		*tdst++ = *tsrc++;
		n--;
	}
	return (dst);
}

void	*ft_mem_grow(void *addr, size_t old_size, size_t new_size)
{
	void	*tmp;

	tmp = malloc(new_size);
	ft_memcpy(tmp, addr, old_size);
	free(addr);
	return (tmp);
}
