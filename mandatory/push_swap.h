/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:31:24 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/11 21:49:45 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
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
	int			b_m_lis;
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
}	t_inf_sa;

//**********Stack_B_info***************

typedef struct info2
{
	int		len;
	int		index;
	t_node	*head;
	t_node	*tail;
}	t_inf_sb;

//**********Project_Data***************

typedef struct best_mouv
{
	int	best_mouv_index;
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

void	len_stack_a(t_inf_sa *infa);
void	len_stack_b(t_inf_sb *infb);
void	sa(t_inf_sa *infa);
void	sb(t_inf_sb *infb);
void	pa(t_inf_sa *infa, t_inf_sb *infb);
void	pb(t_inf_sa *infa, t_inf_sb *infb);
void	ss(t_inf_sa *infa, t_inf_sb *infb);
void	ra(t_inf_sa *infa);
void	rb(t_inf_sb *infb);
void	rra(t_inf_sa *infa);
void	rrb(t_inf_sb *infb);
void	rr(t_inf_sa *infa, t_inf_sb *infb);
void	rrr(t_inf_sa *infa, t_inf_sb *infb);
void	display_a(t_inf_sa infa);
void	display_b(t_inf_sb infb);
void	sort(t_inf_sa *infa, t_inf_sb *infb);
void	long_i_s_index(t_inf_sa *infa);
void	long_i_s(t_inf_sa *infa, t_inf_sb *infb, t_data *data, t_inf_sa *original);
void	start_sorting(t_inf_sa *infa, t_inf_sb *infb, int *tab);
void	index_stack(t_inf_sa *infa, t_inf_sb *infb);
void	found_mouv_stack_b(t_inf_sa *infa, t_inf_sb *infb);
void	found_mouv_stack_a(t_inf_sa *infa, t_inf_sb *infb);
void	best_mouv(t_inf_sb *infb, t_best_mouv *mouv);
void	start_oper(t_inf_sa *infa, t_inf_sb *infb, t_best_mouv	*mouv);
void	found_index_small(t_inf_sa *infa);

#endif
