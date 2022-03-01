/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_pb_rb_rrb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:43:33 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/01 12:09:12 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **s_b, t_inf_sb *info)
{
	t_data	data;

	info->len = 0;
	len_stack(&info->len, *s_b);
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

void	pb(t_inf_sa *infa, t_inf_sb *infb)
{
	t_data	data;

	if (infa != NULL)
	{
		data.tmp = infa->head;
		data.tmp2 = infb->head;
		infa->head = infa->head->next;
		data.tmp->next = data.tmp2;
		data.tmp2->prev = data.tmp;
		infb->head = data.tmp;
	}
}

void	rb(t_inf_sb *info)
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
