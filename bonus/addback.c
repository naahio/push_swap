/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:57:55 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/09 09:20:31 by mbabela          ###   ########.fr       */
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

int	check_valide_move(char *result)
{
	if (ft_strcmp(result, "sa") == 1)
		return (1);
	else if (ft_strcmp(result, "sb") == 1)
		return (1);
	else if (ft_strcmp(result, "ss") == 1)
		return (1);
	else if (ft_strcmp(result, "ra") == 1)
		return (1);
	else if (ft_strcmp(result, "rb") == 1)
		return (1);
	else if (ft_strcmp(result, "rr") == 1)
		return (1);
	else if (ft_strcmp(result, "rra") == 1)
		return (1);
	else if (ft_strcmp(result, "rrb") == 1)
		return (1);
	else if (ft_strcmp(result, "rrr") == 1)
		return (1);
	else if (ft_strcmp(result, "pa") == 1)
		return (1);
	else if (ft_strcmp(result, "pb") == 1)
		return (1);
	else
		return (0);
}
