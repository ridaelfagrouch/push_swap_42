/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:31:24 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/15 17:38:23 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
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

//**********Function_prototype**********

void	sa(t_infsa *infa);
void	pa(t_infsa *infa, t_infsb *infb);
void	rra(t_infsa *infa);
void	ra(t_infsa *infa);
void	sb(t_infsb *infb);
void	pb(t_infsa *infa, t_infsb *infb);
void	rb(t_infsb *infb);
void	rrb(t_infsb *infb);
void	ssb(t_infsb *infb);
void	ss(t_infsa *infa, t_infsb *infb);
void	rr(t_infsa *infa, t_infsb *infb);
void	rrr(t_infsa *infa, t_infsb *infb);
void	max_lenght(t_data *data, int *max_lenght);
int		*stor_long_i_s(t_infsa infa, t_data *data, int *count);
void	native_infa(t_data *data, t_infsa *original, t_infsa *infa);
void	best_mouv_l_i_s(t_infsa *infa, int *tab);
void	best_mouv_(t_infsa *infa, t_best_mouv *best);
void	push_no_lis(t_infsa *infa, t_infsb *infb, int *tab);
void	long_i_s(t_infsa *infa, t_infsb *infb, t_data *data, t_infsa *original);
void	long_i_s_index(t_infsa *infa);
void	sort(t_infsa *infa, t_infsb *infb);
void	len_stack_a(t_infsa *infa);
void	len_stack_b(t_infsb *infb);
void	display_a(t_infsa infa);
void	display_b(t_infsb infb);
void	index_stack(t_infsa *infa, t_infsb *infb);
void	found_mouv_stack_b(t_infsb *infb);
void	found_mouv_stack_a(t_infsa *infa, t_infsb *infb);
void	check_negative(t_infsa *infa, t_infsb *infb, t_data	*data);
void	check_rang2(t_infsa *infa, t_data *data);
void	check_rang1(t_infsa *infa, t_data *data);
void	best_mouv(t_infsb *infb, t_best_mouv *mouv);
void	start_sort(t_infsa *infa, t_infsb *infb);
void	check_small_index(t_infsa *infa);
void	sorting_case1(t_infsa *infa, t_infsb *infb, \
	t_best_mouv	*mouv, t_data *data);
void	sorting_case2(t_infsa *infa, t_infsb *infb, \
	t_best_mouv	*mouv, t_data *data);
void	sorting_case3(t_infsa *infa, t_infsb *infb, \
	t_best_mouv *mouv, t_data *data);
void	sorting_case4(t_infsa *infa, t_infsb *infb, \
	t_best_mouv *mouv, t_data *data);
void	sorting_case5(t_infsa *infa, t_infsb *infb, \
	t_best_mouv *mouv, t_data *data);

#endif
