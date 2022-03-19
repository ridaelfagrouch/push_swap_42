/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:31:24 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/19 19:56:39 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

//**********struct_node***************

typedef struct node
{
	int			data;
	struct node	*next;
	struct node	*prev;
	int			index;
	int			lenght;
	int			best_mvb;
	int			best_mva;
	int			best_mvb_index;
	int			sub_s;
}	t_node;

typedef struct newnode
{
	int				data;
	struct newnode	*next;
}	t_node_long;

//**********Stack_A_info***************

typedef struct info1
{
	int		len;
	int		small;
	int		small_index;
	int		l_i_sub_len;
	t_node	*head;
	t_node	*tail;
}	t_infsa;

//**********Stack_B_info***************

typedef struct info2
{
	int		len;
	int		index;
	t_node	*head;
	t_node	*tail;
}	t_infsb;

//**********Project_Data***************

typedef struct best_mouv
{
	int	best_mouv_index;
	int	best_mouv_index_a;
	int	best_mv_a;
	int	best_mv_b;
	int	best_mouv_data;
}	t_best_mouv;

//**********Project_Data***************

typedef struct data
{
	int		i;
	int		j;
	int		end;
	t_node	*newnode;
	t_node	*tmp;
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*tmp3;
	t_node	*tmp4;
	t_node	*temp;
}	t_data;

//*****************************GET_NEXT_LINE********************************

# define BUFFER_SIZE 940

char	*get_next_line(int fd);
size_t	ft_strlen1(char *str);
char	*ft_substr1(char *s, unsigned int start, unsigned int len);
void	ft_bzero1(void *s, size_t n);

//********************************sa_pa_rra_ra.c*****************************
void	sa(t_infsa *infa);
void	pa(t_infsa *infa, t_infsb *infb);
void	rra(t_infsa *infa);
void	ra(t_infsa *infa);

//********************************sb_pb_rb_rrb*******************************
void	sb(t_infsb *infb);
void	pb(t_infsa *infa, t_infsb *infb);
void	rb(t_infsb *infb);
void	rrb(t_infsb *infb);

//********************************ss_rr_rrr.c*********************************
void	ssb(t_infsb *infb);
void	ss(t_infsa *infa, t_infsb *infb);
void	rr(t_infsa *infa, t_infsb *infb);
void	rrr(t_infsa *infa, t_infsb *infb);

//*******************************node_data.c********************************
void	check_isdigit(t_data *data, char **av);
void	newnode_data(char **av, t_data *data);
void	data_sa(char **av, t_infsa *infa);

//*******************************sourting.c********************************
void	check_ptr(t_infsa *infa, t_infsb *infb, char *ptr);
void	appl_sortint(t_infsa *infa, t_infsb *infb);

//*******************************stack_len_disp.c***************************
void	len_stack_a(t_infsa *infa);
void	len_stack_b(t_infsb *infb);
void	display_a(t_infsa infa);
void	display_b(t_infsb infb);
void	index_stack(t_infsa *infa, t_infsb *infb);

//*******************************trim_strcmp.c.c***************************
int		ft_setcheck(char c, char const *set);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strcmp(char *s1, char *s2);

//*********************************check_error.c***************************
void	empty_arg(int ac, char **av);
void	check_dup(t_infsa *infa, t_infsb *infb);

//*********************************free_stack******************************
void	ft_free_a(t_infsa *infa);
void	ft_free_b(t_infsb *infb);

#endif
