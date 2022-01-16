/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:50:02 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/08 14:44:46 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\f'
		||c == '\v' || c == '\n' || c == '\r' );
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	free_split(char	**str)
{
	int	i;

	if (str && *str)
	{
		i = 0;
		while (str[i])
		{
			free(str[i]);
			i++;
		}	
	}
	free(str);
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
