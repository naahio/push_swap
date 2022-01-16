/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:34:49 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/13 11:04:46 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	trie_data(t_stack **a, t_stack **b, t_data *data)
{
	if (data->res[0] == 0 || data->res[1] == 0)
		half_null(data, a, b);
	else if (data->res[0] > 0 && data->res[1] > 0)
		positive(a, b, data);
	else if (data->res[0] < 0 && data->res[1] < 0)
		negative(a, b, data);
	else if (data->res[0] > 0 && data->res[1] < 0)
		mixed_a(a, b, data);
	else
		mixed_b(a, b, data);
}

void	do_free(t_data **data, t_stack **a, char **move)
{
	free_param(data, a);
	free_split(move);
}

int	arg_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (ft_strlen(argv[i]) < 1)
			return (0);
	return (1);
}
