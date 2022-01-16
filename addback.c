/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:57:55 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/08 14:39:30 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while ((tmp) && (tmp)->next)
		tmp = (tmp)->next;
	(tmp)->next = new;
	new->prev = tmp;
}
