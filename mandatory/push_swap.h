/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:31:24 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/02/28 20:14:05 by rel-fagr         ###   ########.fr       */
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

typedef struct data
{
	int		i;
	int		j;
	t_node	*newnode;
	t_node	*head;
	t_node	*tmp;
	t_node	*tail;
}	t_data;

void	len_stack(int *len, t_node *s_a);
void	swap_a(t_node **s_a);

#endif
