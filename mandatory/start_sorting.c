/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:54:41 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/14 17:36:37 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	best_mouv(t_infsb *infb, t_best_mouv *mouv)
{
	t_data	data;
	int		mouv_to;
	int		mouv_to_prev;

	data.tmp = infb->head;
	mouv_to_prev = data.tmp->best_mva + data.tmp->best_mvb;
	mouv->best_mouv_index = data.tmp->index;
	mouv->best_mouv_index_a = data.tmp->best_mvb_index;
	mouv->best_mv_a = data.tmp->best_mva;
	mouv->best_mv_b = data.tmp->best_mvb;
	mouv->best_mouv_data = data.tmp->data;
	data.tmp = data.tmp->next;
	while (data.tmp)
	{
		mouv_to = data.tmp->best_mva + data.tmp->best_mvb;
		if (mouv_to < mouv_to_prev)
		{
			mouv->best_mouv_index = data.tmp->index;
			mouv->best_mouv_index_a = data.tmp->best_mvb_index;
			mouv->best_mv_a = data.tmp->best_mva;
			mouv->best_mv_b = data.tmp->best_mvb;
			mouv->best_mouv_data = data.tmp->data;
			mouv_to_prev = mouv_to;
		}
		data.tmp = data.tmp->next;
	}
}

/* ************************************************************************** */

void	initial_best_mv(t_infsb *infb)
{
	t_data	data;

	data.tmp = infb->head;
	while (data.tmp)
	{
		data.tmp->best_mva = -1;
		data.tmp->best_mvb = -1;
		data.tmp = data.tmp->next;
	}
}

/* ************************************************************************** */

void	last_sort(t_infsa *infa)
{
	t_data	data;

	data.tmp = infa->head;
	if (infa->small_index > (infa->len / 2))
	{
		while (data.tmp->data != infa->small)
		{
			rra(infa);
			data.tmp = infa->head;
		}
	}
	else
	{
		while (data.tmp->data != infa->small)
		{
			ra(infa);
			data.tmp = infa->head;
		}
	}
}

/* ************************************************************************** */

void	start_sort(t_infsa *infa, t_infsb *infb)
{
	t_best_mouv	mouv;
	t_data		data;

	while (infb->len != 0)
	{
		index_stack(infa, infb);
		initial_best_mv(infb);
		found_mouv_stack_b(infb);
		found_mouv_stack_a(infa, infb);
		best_mouv(infb, &mouv);
		data.tmp2 = infb->head;
		data.tmp1 = infa->head;
		if (mouv.best_mouv_index_a > infa->tail->index)
		{
			while (data.tmp2->data != mouv.best_mouv_data)
			{
				if (mouv.best_mouv_index > (infb->len / 2))
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
			pa(infa, infb);
			ra(infa);
		}
		else if ((mouv.best_mouv_index_a > infa->len / 2) && (mouv.best_mouv_index > infb->len / 2))
		{
			while ((data.tmp1->index != mouv.best_mouv_index_a) && (data.tmp2->data != mouv.best_mouv_data))
			{
				rrr(infa, infb);
				data.tmp1 = infa->head;
				data.tmp2 = infb->head;
			}
			while (data.tmp1->index != mouv.best_mouv_index_a)
			{
				rra(infa);
				data.tmp1 = infa->head;
			}
			while (data.tmp2->data != mouv.best_mouv_data)
			{
				rrb(infb);
				data.tmp2 = infb->head;
			}
			pa(infa, infb);
		}
		else if ((mouv.best_mouv_index_a <= infa->len / 2) && (mouv.best_mouv_index <= infb->len / 2))
		{
			while ((data.tmp1->index != mouv.best_mouv_index_a) && (data.tmp2->data != mouv.best_mouv_data))
			{
				rr(infa, infb);
				data.tmp1 = infa->head;
				data.tmp2 = infb->head;
			}
			while (data.tmp1->index != mouv.best_mouv_index_a)
			{
				ra(infa);
				data.tmp1 = infa->head;
			}
			while (data.tmp2->data != mouv.best_mouv_data)
			{
				rb(infb);
				data.tmp2 = infb->head;
			}
			pa(infa, infb);
		}
		else if (mouv.best_mouv_index_a > infa->len / 2)
		{
			while (data.tmp2->data != mouv.best_mouv_data)
			{
				if (mouv.best_mouv_index > (infb->len / 2))
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
			while (data.tmp1->index != mouv.best_mouv_index_a)
			{
				rra(infa);
				data.tmp1 = infa->head;
			}
			pa(infa, infb);
		}
		else if (mouv.best_mouv_index_a <= infa->len / 2)
		{
			while (data.tmp2->data != mouv.best_mouv_data)
			{
				if (mouv.best_mouv_index > (infb->len / 2))
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
			while (data.tmp1->index != mouv.best_mouv_index_a)
			{
				ra(infa);
				data.tmp1 = infa->head;
			}
			pa(infa, infb);
		}
	}
	index_stack(infa, infb);
	check_small_index(infa);
	last_sort(infa);
}
