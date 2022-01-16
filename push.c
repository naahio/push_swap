/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:53:28 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/06 16:02:32 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*free_data(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	free(*a);
	*a = tmp;
	if (*a)
		(*a)->prev = NULL;
	return (*a);
}

void	pb(t_stack **a, t_stack **b, int aff)
{
	t_stack	*new;

	if (aff == 1)
		write (1, "pb\n", 3);
	if (!*a)
		return ;
	if (!*b)
	{
		*b = (t_stack *)malloc((sizeof(t_stack)));
		(*b)->data = (*a)->data;
		(*b)->next = NULL;
		(*b)->prev = NULL;
	}
	else
	{	
		new = (t_stack *)malloc(sizeof(t_stack));
		new->data = (*a)->data;
		new->next = *b;
		new->prev = NULL;
		(*b)->prev = new;
		*b = new;
	}
	(*a) = free_data(a);
}

void	pa(t_stack **b, t_stack **a, int aff)
{
	t_stack	*tmp;

	if (aff == 1)
		write (1, "pa\n", 3);
	ft_lstadd_front(a, ft_lstnew((*b)->data));
	tmp = (*b)->next;
	free(*b);
	*b = tmp;
	if (*b)
		(*b)->prev = NULL;
}
