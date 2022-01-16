/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:13:52 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/13 11:07:41 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"
# define PRINT 1
# define DONT_PRINT 0

typedef struct s_stack	t_stack;
typedef struct s_data	t_data;

struct s_stack
{
	int		data;
	t_stack	*next;
	t_stack	*prev;
};
struct s_data
{
	t_stack	*acopi;
	int		*lis_order;
	int		*my_lis;
	int		max_val;
	int		max_pos;
	int		size;
	int		size_b;
	int		res[2];
};

void	check(t_stack *a, t_stack *b);
int		arg_size(char **argv);
void	do_free(t_data **data, t_stack **a, char **move);
int		check_valide_move(char *result);
void	free_split(char	**str);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		get_size(t_stack *a);
void	case_3(t_stack *a);
void	sa(t_stack *a, int aff);
void	sb(t_stack *b, int aff);
void	ss(t_stack *a, t_stack *b, int aff);
void	pb(t_stack **a, t_stack **b, int aff);
void	pa(t_stack **b, t_stack **a, int aff);
void	ra(t_stack **a, int aff);
void	rb(t_stack **b, int aff);
void	rr(t_stack *a, t_stack *b, int aff);
void	rra(t_stack **a, int aff);
void	rrb(t_stack **b, int aff);
void	rrr(t_stack *a, t_stack *b, int aff);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	get_lis(t_stack *a, t_data *data);
void	check_lis_val(t_data *data, t_stack *a);
void	create_b(t_data *data, t_stack **a, t_stack **b);
void	calculate_lis(t_stack *a, t_data *data);
void	get_max_val(int size, t_data *data);
void	positive(t_stack **a, t_stack **b, t_data *data);
void	negative(t_stack **a, t_stack **b, t_data *data);
void	mixed_a(t_stack **a, t_stack **b, t_data *data);
void	mixed_b(t_stack **a, t_stack **b, t_data *data);
int		get_pos_a(t_stack *a, int nbr, t_data *data);
int		get_pos_b(t_stack *b, int nbr, t_data *data);
void	print_table(t_stack *a, t_stack *b, t_data *data);
int		get_moves(t_stack *a, t_data *data, t_stack *b);
void	do_move(t_stack **a, t_data *data, t_stack **b);
int		two_case(char *str, t_stack **a, t_stack **acopi);
char	*join_param(char *join, char *s1);
void	calc_loop(t_data **data, int t[2], t_stack *tmp);
void	trie_data(t_stack **a, t_stack **b, t_data *data);
void	half_null(t_data *data, t_stack **a, t_stack **b);
int		*res_cond(t_data *data, int tp[2], int t[2]);
int		first_check(int argc, char **argv, t_data *data, t_stack **a);
t_data	*init_data(t_stack **a, t_stack **b);
char	*ft_substr(char *s, int start, int len);
char	**ft_split(char const *s, char c);
int		check_data(char *str);
int		check_duplicated(t_stack *a);
void	case_2(t_stack *a);
int		check_order(t_stack *a, t_stack *b);
int		compare(int i, int size);
int		get_min(int a, int b);
int		get_max(int a, int b);
char	*ft_strdup(char *s1);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
int		sort_stack(t_stack **a, t_stack **b, char *result);
char	**get_move_bonus(void);
t_stack	*get_list_reverse(t_stack *stack);
t_stack	*ft_lstnew(int data);
void	free_param(t_data **data, t_stack **a);

#endif