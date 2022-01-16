/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:11:43 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/06 16:03:05 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int aff)
{
	int		tmp;
	t_stack	*tmp2;

	if (aff == 1)
		write (1, "ra\n", 3);
	tmp = (*a)->data;
	tmp2 = (*a);
	while (tmp2->next)
	{
		tmp2->data = tmp2->next->data;
		tmp2 = tmp2->next;
	}
	tmp2->data = tmp;
}

void	rb(t_stack **b, int aff)
{
	int		tmp;
	t_stack	*tmp2;

	if (aff == 1)
		write (1, "rb\n", 3);
	tmp = (*b)->data;
	tmp2 = (*b);
	while (tmp2->next)
	{
		tmp2->data = tmp2->next->data;
		tmp2 = tmp2->next;
	}
	tmp2->data = tmp;
}

void	rr(t_stack *a, t_stack *b, int aff)
{
	if (aff == PRINT)
		write (1, "rr\n", 3);
	ra(&a, DONT_PRINT);
	rb(&b, DONT_PRINT);
}
