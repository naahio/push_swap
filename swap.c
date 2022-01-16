/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:12:10 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/06 16:03:13 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int aff)
{
	int	tmp;

	if (aff == 1)
		write (1, "sa\n", 3);
	tmp = a->data;
	a->data = a->next->data;
	a->next->data = tmp;
}

void	sb(t_stack *b, int aff)
{
	int	tmp;

	if (aff == 1)
		write (1, "sb\n", 3);
	tmp = b->data;
	b->data = b->next->data;
	b->next->data = tmp;
}

void	ss(t_stack *a, t_stack *b, int aff)
{
	if (aff == PRINT)
		write (1, "ss\n", 3);
	sa(a, DONT_PRINT);
	sb(b, DONT_PRINT);
}
