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

typedef struct s_chunk_elem *t_chunk_elem;

struct s_chunk_elem
{
	int value;
	int chunk_num;	
};

t_chunk_elem elem_chunk(int value, int chunk_num);

#endif