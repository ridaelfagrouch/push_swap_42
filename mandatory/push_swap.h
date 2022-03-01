/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:31:24 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/01 12:12:18 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct node
{
	int			data;
	struct node	*next;
	struct node	*prev;
}	t_node;

typedef struct info1
{
	int		len;
	t_node	*head;
	t_node	*tail;
}	t_inf_sa;

typedef struct info2
{
	int		len;
	t_node	*head;
	t_node	*tail;
}	t_inf_sb;

typedef struct data
{
	int		i;
	int		j;
	t_node	*newnode;
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*tmp3;
}	t_data;

void	len_stack(int *len, t_node *stack);
void	sa(t_node **s_a, t_inf_sa *info);
void	sb(t_node **s_b, t_inf_sb *info);
void	pa(t_inf_sa *infa, t_inf_sb *infb);
void	ss(t_node **s_a, t_inf_sa *info1, t_node **s_b, t_inf_sb *info2);
void	ra(t_inf_sa *info);
void	rb(t_inf_sb *info);
void	rr(t_inf_sa *inf_a, t_inf_sb *inf_b);

#endif
