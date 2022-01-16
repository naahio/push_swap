/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:24:11 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/05 11:22:20 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	positive(t_stack **a, t_stack **b, t_data *data)
{
	int	t[2];
	int	i;

	t[0] = data->res[0];
	t[1] = data->res[1];
	if (data->res[0] > data->res[1])
	{
		t[0] = data->res[1];
		t[1] = data->res[0];
	}
	i = 0;
	while (i < t[0])
	{
		rr(*a, *b, PRINT);
		i++;
	}
	i = 0;
	while (i < t[1] - t[0])
	{
		if (data->res[0] - data->res[1] > 0)
			ra(a, PRINT);
		else
			rb(b, PRINT);
		i++;
	}
}

void	negative(t_stack **a, t_stack **b, t_data *data)
{
	int	t[2];
	int	i;

	t[0] = abs(data->res[0]);
	t[1] = abs(data->res[1]);
	if (t[0] > abs(data->res[1]))
	{
		t[0] = abs(data->res[1]);
		t[1] = abs(data->res[0]);
	}
	i = 0;
	while (i < t[0])
	{
		rrr(*a, *b, PRINT);
		i++;
	}
	i = 0;
	while (i < t[1] - t[0])
	{
		if (data->res[0] - data->res[1] < 0)
			rra(a, PRINT);
		else
			rrb(b, PRINT);
		i++;
	}
}

void	mixed_a(t_stack **a, t_stack **b, t_data *data)
{
	int	j;

	j = 0;
	while (j < data->res[0])
	{
		ra(a, PRINT);
		j++;
	}
	j = 0;
	while (j < abs(data->res[1]))
	{
		rrb(b, PRINT);
		j++;
	}
}

void	mixed_b(t_stack **a, t_stack **b, t_data *data)
{
	int	j;

	j = 0;
	while (j < data->res[1])
	{
		rb(b, PRINT);
		j++;
	}
	j = 0;
	while (j < abs(data->res[0]))
	{
		rra(a, PRINT);
		j++;
	}
}

void	half_null(t_data *data, t_stack **a, t_stack **b)
{
	int	j;

	if (data->res[0] != 0)
	{
		j = -1;
		while (++j < data->res[0])
			ra(a, PRINT);
		j = -1;
		if (data->res[0] < 0)
		{
			while (++j < abs(data->res[0]))
				rra(a, PRINT);
		}	
	}
	if (data->res[1] != 0)
	{
		j = -1;
		while (++j < abs(data->res[1]))
		{
			if (data->res[1] > 0)
				rb(b, PRINT);
			else
				rrb(b, PRINT);
		}
	}
}
