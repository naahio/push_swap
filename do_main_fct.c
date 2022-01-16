/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_main_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:49:38 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/13 11:12:54 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_param(char *join, char *s1)
{
	char	*tmp;

	tmp = join;
	join = ft_strjoin(join, " ");
	free(tmp);
	tmp = join;
	join = ft_strjoin(join, s1);
	free(tmp);
	return (join);
}

int	first_check(int argc, char **argv, t_data *data, t_stack **a)
{
	int		i;
	char	*join;
	char	**str;

	if (argc < 2)
		return (0);
	join = ft_substr(argv[1], 0, ft_strlen(argv[1]));
	i = 0;
	while (++i < argc - 1)
		join = join_param(join, argv[i + 1]);
	str = ft_split(join, ' ');
	free(join);
	i = -1;
	while (str[++i])
	{
		if (!check_data(str[i]))
		{
			free_split(str);
			return (0);
		}
		ft_lstadd_back(a, ft_lstnew(ft_atoi(str[i])));
		ft_lstadd_back(&data->acopi, ft_lstnew(ft_atoi(str[i])));
	}
	free_split(str);
	return (1);
}

t_data	*init_data(t_stack **a, t_stack **b)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	(data)->acopi = NULL;
	a = NULL;
	b = NULL;
	return (data);
}

void	calc_loop(t_data **data, int t[2], t_stack *tmp)
{
	while (tmp && ++t[1] < t[0])
	{
		if (tmp->data < t[2]
			&& (*data)->lis_order[t[1]] + 1 >= (*data)->lis_order[t[0]])
			(*data)->lis_order[t[0]] = (*data)->lis_order[t[1]] + 1;
		tmp = tmp->next;
	}
}

int	get_pos_b(t_stack *b, int nbr, t_data *data)
{
	t_stack	*tmp;
	int		ret;
	int		i;

	i = 0;
	tmp = (b);
	while (tmp->data != nbr)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > data->size_b / 2)
		ret = i - data->size_b;
	else
		ret = i;
	return (ret);
}
