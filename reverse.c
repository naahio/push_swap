/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:14:02 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/06 16:02:56 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int aff)
{
	int		tmp;
	t_stack	*tmp2;

	if (aff == 1)
		write (1, "rra\n", 4);
	tmp2 = (*a);
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp = tmp2->data;
	while (tmp2->prev)
	{
		tmp2->data = tmp2->prev->data;
		tmp2 = tmp2->prev;
	}
	tmp2->data = tmp;
}

void	rrb(t_stack **b, int aff)
{
	int		tmp;
	t_stack	*tmp2;

	if (aff == 1)
		write (1, "rrb\n", 4);
	tmp2 = (*b);
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp = tmp2->data;
	while (tmp2->prev)
	{
		tmp2->data = tmp2->prev->data;
		tmp2 = tmp2->prev;
	}
	tmp2->data = tmp;
}

void	rrr(t_stack *a, t_stack *b, int aff)
{
	if (aff == PRINT)
		write (1, "rrr\n", 4);
	rra(&a, DONT_PRINT);
	rrb(&b, DONT_PRINT);
}
