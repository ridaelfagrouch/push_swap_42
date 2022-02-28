/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_pa_ra_rra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:43:22 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/02/28 20:13:42 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	len_stack(int *len, t_node *s_a)
{
	while (s_a != NULL)
	{
		s_a = s_a->next;
		(*len)++;
	}
}

void	swap_a(t_node **s_a)
{
	int		len;
	t_data	data;

	len = 0;
	data.head = *s_a;
	len_stack(&len, *s_a);
	printf("-----%d-----\n", len);
	if (len != 1)
	{
		data.tmp = data.head;
		data.head = data.head->next;
		data.tail = data.head->next;
		data.head->next = data.tmp;
		data.tmp->prev = data.head;
		data.tmp->next = data.tail;
		data.tail->prev = data.tmp;
	}
}
