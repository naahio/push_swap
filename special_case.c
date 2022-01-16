/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 09:29:28 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/05 12:06:32 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_2(t_stack *a)
{
	if (a->data > a->next->data)
		sa(a, PRINT);
}

void	case_3(t_stack *a)
{
	if ((a->data > a->next->data && (a->data > a->next->next->data)))
	{
		ra(&a, PRINT);
		if (a->data > a->next->data)
			sa(a, PRINT);
		return ;
	}
	if ((a->data < a->next->data && (a->data < a->next->next->data)))
	{
		if (a->next->data > a->next->next->data)
		{
			rra(&a, PRINT);
			sa(a, PRINT);
		}
		return ;
	}
	if ((a->data > a->next->data && (a->data < a->next->next->data)))
	{
		sa(a, PRINT);
		return ;
	}
	if ((a->data < a->next->data && (a->data > a->next->next->data)))
		rra(&a, PRINT);
}

int	get_pos_a(t_stack *a, int nbr, t_data *data)
{
	t_stack	*tmp[2];
	int		i;

	tmp[1] = get_list_reverse(a);
	tmp[0] = a;
	if (nbr < a->data && nbr > tmp[1]->data)
		return (0);
	i = 0;
	while ((i < data->size / 2))
	{
		if (nbr > tmp[0]->data && nbr < tmp[0]->next->data)
			return (i + 1);
		if (nbr < tmp[1]->data && nbr > tmp[1]->prev->data)
			return (-i - 1);
		i++;
		tmp[0] = tmp[0]->next;
		tmp[1] = tmp[1]->prev;
	}
	tmp[0] = a;
	i = 0;
	while (tmp[0] && tmp[0]->data != data->acopi->data && (i++) >= 0)
		tmp[0] = tmp[0]->next;
	return (compare(i, data->size));
}

t_stack	*get_list_reverse(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	compare(int i, int size)
{
	if (i == size)
		return (-1);
	if (i <= size)
		return (i);
	else
		return (i - size);
}
