/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:09:55 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/08 14:47:50 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*k;

	k = (unsigned char *)s;
	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			k[i] = 0;
			i++;
		}
	}
}

void	free_param(t_data **data, t_stack **a)
{
	t_stack	*tmp;

	tmp = (*data)->acopi;
	while (tmp)
	{
		free((*data)->acopi);
		(*data)->acopi = tmp->next;
		tmp = tmp->next;
	}
	free((*data));
	tmp = *a;
	while (tmp)
	{
		free(*a);
		*a = tmp->next;
		tmp = tmp->next;
	}
}
