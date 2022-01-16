/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:11:18 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/06 14:15:05 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		result [i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
