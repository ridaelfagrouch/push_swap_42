/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:50:00 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/09 19:09:58 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	start_oper(t_inf_sa *infa, t_inf_sb *infb, t_best_mouv	*mouv)
{
	t_data	data;
	int		count;

	data.tmp2 = infb->head;
	while (data.tmp2->data != mouv->best_mouv_data && infb->len != 0)
	{
		if (mouv->index_best_mouv_b > (infb->len / 2))
		{
			rrb(infb);
			data.tmp2 = infb->head;
		}
		else
		{
			rb(infb);
			data.tmp2 = infb->head;
		}
	}
	count = 0;
	data.tmp2 = infb->head;
	data.tmp = infa->head;
	if (infb->len != 0)
	{
		if (mouv->index_best_mouv_a > infa->tail->index)
		{
			pa(infa, infb);
			ra(infa);
		}
		else if (mouv->index_best_mouv_a > infa->len / 2)
		{
			while (data.tmp->index != mouv->index_best_mouv_a)
			{
				rra(infa);
				data.tmp = infa->head;
				count++;
			}
			pa(infa, infb);
			while (count >= 0)
			{
				ra(infa);
				count--;
			}
		}
		else if(mouv->index_best_mouv_a <= infa->len / 2)
		{
			while (data.tmp->index != mouv->index_best_mouv_a)
			{
				ra(infa);
				data.tmp = infa->head;
				count++;
			}
			pa(infa, infb);
			while (count >= 0)
			{
				rra(infa);
				count--;
			}
		}
		if (infb->len != 0)
		{
			index_stack(infa, infb);
			found_mouv_stack_b(infa, infb);
			found_index_small(infa);
			found_mouv_stack_a(infa, infb);
			best_mouv(infb, mouv);
			start_oper(infa, infb, mouv);
		}
	}
}
