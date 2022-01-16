/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:11:48 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/05 14:21:07 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (ft_strdup(""));
	else if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (ft_strdup(""));
	i = 0;
	while (s[start] && i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
