/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:06:50 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/05 11:33:57 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	check_lis_val(t_data *data, t_stack *a)
{
	int		t[2];
	int		max;
	t_stack	*tmp;

	data->my_lis = (int *)malloc(sizeof(int) * data->max_val);
	if (!data->my_lis)
		return ;
	tmp = a;
	t[0] = -1;
	while (tmp->next && ++t[0] < data->max_pos)
		tmp = tmp->next;
	t[0] = data->max_pos;
	t[1] = data->max_val - 1;
	max = data->max_val;
	while (t[0] >= 0)
	{
		if (data->lis_order[t[0]] == max)
		{
			data->my_lis[t[1]] = tmp->data;
			t[1]--;
			max--;
		}
		t[0]--;
		tmp = tmp->prev;
	}
}

void	create_b(t_data *data, t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	stats;

	i = 0;
	data->size_b = data->size - data->max_val;
	while (i < data->size_b)
	{
		j = 0;
		stats = 1;
		while ((j < data->max_val) && (stats == 1))
		{
			if ((*a)->data == data->my_lis[j])
				stats = 0;
			j++;
		}
		if (stats == 1)
		{
			pb(a, b, PRINT);
			i++;
		}
		else
			ra(a, PRINT);
	}
}

int	get_moves(t_stack *a, t_data *data, t_stack *b)
{
	t_stack	*tmp;
	int		t[2];
	int		i;
	int		tp[2];

	data->res[0] = get_size(a);
	data->res[1] = data->size_b;
	tmp = (b);
	while (tmp)
	{
		data->size_b = get_size(b);
		data->size = get_size(a);
		i = 0;
		t[0] = tmp->data;
		tp[1] = get_pos_b(b, t[0], data);
		tp[0] = get_pos_a(a, t[0], data);
		res_cond(data, tp, t);
		tmp = tmp->next;
	}
	return (t[1]);
}

void	do_move(t_stack **a, t_data *data, t_stack **b)
{
	int		i;
	int		nbr;
	t_stack	*tmp;

	i = 0;
	while (data->size_b > 0)
	{
		nbr = get_moves(*a, data, *b);
		trie_data(a, b, data);
		pa(b, a, PRINT);
		data->size_b--;
	}
	tmp = *a;
	i = 0;
	while (tmp->data != data->acopi->data)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < get_size(*a) / 2)
		while ((*a)->data != data->acopi->data)
			ra(a, PRINT);
	else
		while ((*a)->data != data->acopi->data)
			rra(a, PRINT);
}
