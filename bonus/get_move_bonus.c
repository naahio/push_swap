/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:15:25 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/09 09:42:04 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size(char **matr)
{
	int	i;

	i = 0;
	while (matr[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (ft_strlen(s1) - 1 != ft_strlen(s2))
		return (0);
	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp2(char *s1, char *s2)
{
	int	i;

	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	sort_stack(t_stack **a, t_stack **b, char *result)
{
	if (ft_strcmp2(result, "sa") == 1)
		sa(*a, DONT_PRINT);
	else if (ft_strcmp2(result, "sb") == 1)
		sb(*b, DONT_PRINT);
	else if (ft_strcmp2(result, "ss") == 1)
		ss(*a, *b, DONT_PRINT);
	else if (ft_strcmp2(result, "ra") == 1)
		ra(a, DONT_PRINT);
	else if (ft_strcmp2(result, "rb") == 1)
		rb(b, DONT_PRINT);
	else if (ft_strcmp2(result, "rr") == 1)
		rr(*a, *b, DONT_PRINT);
	else if (ft_strcmp2(result, "rra") == 1)
		rra(a, DONT_PRINT);
	else if (ft_strcmp2(result, "rrb") == 1)
		rrb(b, DONT_PRINT);
	else if (ft_strcmp2(result, "rrr") == 1)
		rrr(*a, *b, DONT_PRINT);
	else if (ft_strcmp2(result, "pa") == 1)
		pa(b, a, DONT_PRINT);
	else if (ft_strcmp2(result, "pb") == 1)
		pb(a, b, DONT_PRINT);
	else
		return (0);
	return (1);
}

char	**get_move_bonus(void)
{
	char	*buff;
	char	*str;
	char	*tmp;
	char	**ret;

	buff = get_next_line(0);
	str = ft_strdup("");
	while (buff != NULL)
	{
		if (!check_valide_move(buff))
		{
			write (2, "Error !", 8);
			exit(0);
		}
		tmp = str;
		str = ft_strjoin(str, buff);
		free(tmp);
		free(buff);
		buff = get_next_line(0);
	}
	free(buff);
	ret = ft_split(str, '\n');
	free(str);
	return (ret);
}
