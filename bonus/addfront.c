/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:27:15 by mbabela           #+#    #+#             */
/*   Updated: 2021/11/06 11:27:15 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	(*lst)->prev = new;
	new->prev = NULL;
	*lst = new;
}

void	free_split(char	**str)
{
	int	i;

	if (str && *str)
	{
		i = 0;
		while (str[i])
		{
			free(str[i]);
			i++;
		}	
	}
	free(str);
}
