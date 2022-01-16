/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:23:05 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/13 11:08:18 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_data(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
		{
			write (2, "Error !!\n", 10);
			return (0);
		}
		i++;
	}
	return (1);
}

int	two_case(char *str, t_stack **a, t_stack **acopi)
{
	char	**splt;
	int		size;
	int		i;

	size = ft_strlen(str);
	if (size < 1)
		return (0);
	splt = ft_split(str, ' ');
	i = 0;
	while (splt[i])
	{
		if (!check_data(splt[i]))
		{
			write (2, "Error !\n", 9);
			return (0);
		}
		ft_lstadd_back(a, ft_lstnew(ft_atoi(splt[i])));
		ft_lstadd_back(acopi, ft_lstnew(ft_atoi(splt[i])));
		i++;
	}
	return (1);
}

int	check_duplicated(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp1 = a;
	while (tmp1)
	{
		tmp = tmp1->next;
		while (tmp)
		{
			if (tmp1->data == tmp->data)
			{
				write (2, "Duplicated number !!\n", 22);
				return (0);
			}
			tmp = tmp->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*data;
	char	**move;
	int		i;

	data = init_data(&a, &b);
	if (!arg_size(argv))
		return (0);
	if (!first_check(argc, argv, data, &a) || !check_duplicated(a))
	{
		free_param(&data, &a);
		return (0);
	}
	move = get_move_bonus();
	if (!move)
		do_free(&data, &a, move);
	i = -1;
	while (move[++i])
		if (!sort_stack(&a, &b, move[i]))
			return (write(2, "Error wrong move\n", 17), 0);
	check(a, b);
	do_free(&data, &a, move);
	return (0);
}
