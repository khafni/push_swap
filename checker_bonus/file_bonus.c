/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:44:42 by khafni            #+#    #+#             */
/*   Updated: 2021/06/30 12:48:19 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bonus.h"

t_file	file(int fd)
{
	static t_file	f = NULL;

	if (!f)
	{
		f = malloc(sizeof(struct s_file));
		f->fd = fd;
		f->cursor = DEFAULT_BUFFER_SIZE;
		f->len = DEFAULT_BUFFER_SIZE;
		f->buffer = malloc(sizeof(char) * DEFAULT_BUFFER_SIZE);
		f->str_buff = rstr_create(1);
		f->reading_state = 666;
		f->is_empty = 1;
	}
	return (f);
}

void	file_destroy(t_file f)
{
	free(f->buffer);
	rstr_destroy(f->str_buff);
	free(f);
}

int	file_read_char(t_file f)
{
	char	c;

	if (f->cursor == f->len)
	{
		f->len = read(f->fd, f->buffer, DEFAULT_BUFFER_SIZE);
		f->reading_state = f->len;
		if (f->len > 1)
			f->reading_state = 1;
		if (f->len == 0)
			return (f->reading_state);
		else
		{
			f->cursor = 1;
			return ((int)f->buffer[0]);
		}
	}
	else
	{
		c = f->buffer[f->cursor];
		f->cursor++;
		return ((int)c);
	}
}

void	file_read_line(t_file f)
{
	int	c;

	rstr_clear(f->str_buff);
	c = file_read_char(f);
	while (c != '\n' && f->reading_state > 0)
	{
		rstr_add(f->str_buff, c);
		f->is_empty = 0;
		c = file_read_char(f);
	}
	rstr_add(f->str_buff, '\0');
}
