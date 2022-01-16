/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_cond.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:26:21 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/08 14:32:03 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	switch_val(t_data *data, int tp[2], int t[2])
{
	data->res[0] = tp[0];
	data->res[1] = tp[1];
	return (t[0]);
}

int	*res_cond(t_data *data, int tp[2], int t[2])
{
	if ((tp[0] * tp[1]) > 0)
	{
		if (data->res[0] * data->res[1] > 0)
		{
			if (get_max(abs(tp[0]), abs(tp[1]))
				< get_max(abs(data->res[0]), abs(data->res[1])))
				t[1] = switch_val(data, tp, t);
		}
		else
		{
			if (get_max(abs(tp[0]), abs(tp[1]))
				< (abs(data->res[0]) + abs(data->res[1])))
				t[1] = switch_val(data, tp, t);
		}
	}
	else
	{
		if ((abs(tp[0]) + abs(tp[1])) < (abs(data->res[0]) + abs(data->res[1])))
			t[1] = switch_val(data, tp, t);
	}
	return (tp);
}

int	check_order(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	if (!b)
		return (1);
	return (0);
}
