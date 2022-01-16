/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:34:57 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/21 14:24:21 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(t_stack *a)
{
	int		i;
	t_stack	*tmp;	

	tmp = a;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	get_min_pos(t_stack *a)
{
	int		i;
	int		min_pos;
	int		min;
	t_stack	*tmp;

	i = 0;
	min = a->data;
	tmp = a;
	while (tmp)
	{
		if (min > tmp->data)
		{
			min = tmp->data;
			min_pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (min_pos);
}

void	get_max_val(int size, t_data *data)
{
	int	i;

	i = 0;
	data->max_pos = i;
	data->max_val = data->lis_order[0];
	while (i < size)
	{
		if (data->max_val < data->lis_order[i])
		{
			data->max_pos = i;
			data->max_val = data->lis_order[i];
		}
		i++;
	}
}

void	calculate_lis(t_stack *a, t_data *data)
{
	t_stack	*tmp;
	int		t[3];	

	data->lis_order = (int *)malloc(sizeof(int) * get_size(a));
	if (!data->lis_order)
		return ;
	t[0] = -1;
	while (++t[0] < get_size(a))
		data->lis_order[t[0]] = 1;
	t[0] = 0;
	while (++t[0] < get_size(a))
	{
		tmp = a;
		t[1] = -1;
		while (++t[1] < t[0])
			tmp = tmp->next;
		t[2] = tmp->data;
		tmp = a;
		t[1] = -1;
		calc_loop(&data, t, tmp);
	}
}

void	get_lis(t_stack *a, t_data *data)
{
	int		min_pos;

	data->size = get_size(a);
	min_pos = get_min_pos(a);
	if (min_pos > data->size / 2)
	{
		while (min_pos < data->size)
		{
			rra(&data->acopi, DONT_PRINT);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(&data->acopi, DONT_PRINT);
			min_pos--;
		}
	}
}
