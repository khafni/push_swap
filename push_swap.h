/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:02:26 by khafni            #+#    #+#             */
/*   Updated: 2021/03/28 16:30:02 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "dlist/dlists.h"

typedef struct s_two_stacks  *t_two_stacks;

struct s_two_stacks
{
	t_dlist a;
	t_dlist b;
};

t_two_stacks	empty_two_stacks(void);
void			two_stacks_destroy(t_two_stacks ts);
void			sa(t_two_stacks ts);
void			sb(t_two_stacks ts);
void			ss(t_two_stacks ts);
#endif