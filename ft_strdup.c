/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:11:13 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/06 13:54:17 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

char	*ft_strdup(char *s1)
{
	char	*cop;
	int		i;

	i = 0;
	cop = (char *)malloc((ft_strlen(s1) + 1));
	if (cop)
	{
		while (s1[i])
		{
			cop[i] = s1[i];
			i++;
		}
		cop[i] = '\0';
		return (cop);
	}
	else
		return (NULL);
}
