/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 09:36:11 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/08 12:50:59 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../push_swap.h"

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

#endif
