# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 10:28:59 by mbabela           #+#    #+#              #
#    Updated: 2022/01/08 11:52:38 by mbabela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=checker
CC=gcc
CFLAGS=-Wall -Werror -Wextra
INCLUDES=.
SRC= ft_atoi.c ft_isdigit.c ft_strdup.c ft_strchr.c get_next_line.c ft_strjoin.c ft_substr.c addfront.c ft_split.c ft_bzero.c addback.c create_new.c push.c reverse.c rotate.c swap.c calc_data.c check_list_cond.c check_lis.c trie.c special_case.c get_move_bonus.c action.c do_main_fct.c main.c
OBJ=$(SRC:.c=.o)
REM=rm -f
bonus: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) -I$(INCLUDES) $^ $(CFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) -g -c  $(CFLAGS) $<
	@echo  Compiling $< :"\x1B[1;32m[ok]\x1B[0m"

clean:
	$(REM) $(OBJ) $(BOBJ)
		
fclean: clean
	$(REM) $(NAME)

re:	fclean all
.PHONY: all clean fclean re bonus re_bonus