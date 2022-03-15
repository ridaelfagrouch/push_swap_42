/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:54:41 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/15 16:27:58 by rel-fagr         ###   ########.fr       */
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

void	found_best_mouv(t_infsa *infa, t_infsb *infb, t_best_mouv *mouv)
{
	index_stack(infa, infb);
	initial_best_mv(infb);
	found_mouv_stack_b(infb);
	found_mouv_stack_a(infa, infb);
	best_mouv(infb, mouv);
}

/* ************************************************************************** */

void	start_sort(t_infsa *infa, t_infsb *infb)
{
	t_best_mouv	mouv;
	t_data		data;

	while (infb->len != 0)
	{
		found_best_mouv(infa, infb, &mouv);
		data.tmp2 = infb->head;
		data.tmp1 = infa->head;
		if (mouv.best_mouv_index_a > infa->tail->index)
			sorting_case1(infa, infb, &mouv, &data);
		else if ((mouv.best_mouv_index_a > infa->len / 2) && \
			(mouv.best_mouv_index > infb->len / 2))
			sorting_case2(infa, infb, &mouv, &data);
		else if ((mouv.best_mouv_index_a <= infa->len / 2) && \
			(mouv.best_mouv_index <= infb->len / 2))
			sorting_case3(infa, infb, &mouv, &data);
		else if (mouv.best_mouv_index_a > infa->len / 2 && \
			mouv.best_mouv_index <= infb->len / 2)
			sorting_case4(infa, infb, &mouv, &data);
		else if (mouv.best_mouv_index_a <= infa->len / 2 && \
			mouv.best_mouv_index > infb->len / 2)
			sorting_case5(infa, infb, &mouv, &data);
	}
	index_stack(infa, infb);
	check_small_index(infa);
	last_sort(infa);
}
