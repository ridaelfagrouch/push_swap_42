/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_pa_ra_rra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:43:22 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/01 12:10:30 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	len_stack(int *len, t_node *stack)
{
	while (stack != NULL)
	{
		stack = stack->next;
		(*len)++;
	}
}

void	sa(t_node **s_a, t_inf_sa *info)
{
	t_data	data;

	info->len = 0;
	len_stack(&info->len, *s_a);
	if (info->len != 1)
	{
		data.tmp = info->head;
		data.tmp2 = data.tmp->next;
		data.tmp3 = data.tmp2->next;
		data.tmp2->next = data.tmp;
		data.tmp->prev = data.tmp2;
		data.tmp->next = data.tmp3;
		data.tmp3->prev = data.tmp;
		info->head = data.tmp2;
	}
}

void	pa(t_inf_sa *infa, t_inf_sb *infb)
{
	t_data	data;

	if (infb != NULL)
	{
		data.tmp = infb->head;
		data.tmp2 = infa->head;
		infb->head = infb->head->next;
		data.tmp->next = data.tmp2;
		data.tmp2->prev = data.tmp;
		infa->head = data.tmp;
	}
}

void	ra(t_inf_sa *info)
{
	t_data	data;

	data.tmp = info->head;
	data.tmp2 = info->tail;
	info->tail = info->tail->prev;
	data.tmp2->next = data.tmp;
	data.tmp->prev = data.tmp2;
	info->head = data.tmp2;
	info->tail->next = NULL;
}
