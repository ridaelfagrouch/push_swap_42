/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:26:09 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/15 20:24:48 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	sorting_case1(t_infsa *infa, t_infsb *infb, \
	t_best_mouv	*mouv, t_data *data)
{
	while (data->tmp2->data != mouv->best_mouv_data)
	{
		if (mouv->best_mouv_index > (infb->len / 2))
			rrb(infb);
		else
			rb(infb);
		data->tmp2 = infb->head;
	}
	pa(infa, infb);
	ra(infa);
}

/* ************************************************************************** */

void	sorting_case2(t_infsa *infa, t_infsb *infb, \
	t_best_mouv	*mouv, t_data *data)
{
	while ((data->tmp1->index != mouv->best_mouv_index_a) && \
		(data->tmp2->data != mouv->best_mouv_data))
	{
		rrr(infa, infb);
		data->tmp1 = infa->head;
		data->tmp2 = infb->head;
	}
	while (data->tmp1->index != mouv->best_mouv_index_a)
	{
		rra(infa);
		data->tmp1 = infa->head;
	}
	while (data->tmp2->data != mouv->best_mouv_data)
	{
		rrb(infb);
		data->tmp2 = infb->head;
	}
	pa(infa, infb);
}

/* ************************************************************************** */

void	sorting_case3(t_infsa *infa, t_infsb *infb, \
	t_best_mouv *mouv, t_data *data)
{
	while ((data->tmp1->index != mouv->best_mouv_index_a) && \
		(data->tmp2->data != mouv->best_mouv_data))
	{
		rr(infa, infb);
		data->tmp1 = infa->head;
		data->tmp2 = infb->head;
	}
	while (data->tmp1->index != mouv->best_mouv_index_a)
	{
		ra(infa);
		data->tmp1 = infa->head;
	}
	while (data->tmp2->data != mouv->best_mouv_data)
	{
		rb(infb);
		data->tmp2 = infb->head;
	}
	pa(infa, infb);
}

/* ************************************************************************** */

void	sorting_case4(t_infsa *infa, t_infsb *infb, \
	t_best_mouv *mouv, t_data *data)
{
	// int	som;

	// som = (infa->len - mouv->best_mouv_index_a) + mouv->best_mouv_index;
	// if (mouv->best_mouv_index_a < som )
	// {
	// 	while (data->tmp2->data != mouv->best_mouv_data && data->tmp1->index != mouv->best_mouv_index_a)
	// 	{
	// 		rr(infa, infb);
	// 		data->tmp2 = infb->head;
	// 		data->tmp1 = infa->head;
	// 	}
	// 	while (data->tmp2->data != mouv->best_mouv_data)
	// 	{
	// 		rb(infb);
	// 		data->tmp2 = infb->head;
	// 	}
	// 	while (data->tmp1->index != mouv->best_mouv_index_a)
	// 	{
	// 		ra(infa);
	// 		data->tmp1 = infa->head;
	// 	}
	// }
	// else
	// {
	while (data->tmp2->data != mouv->best_mouv_data)
	{
		rb(infb);
		data->tmp2 = infb->head;
	}
	while (data->tmp1->index != mouv->best_mouv_index_a)
	{
		rra(infa);
		data->tmp1 = infa->head;
	}
	pa(infa, infb);
}

/* ************************************************************************** */

void	sorting_case5(t_infsa *infa, t_infsb *infb, \
	t_best_mouv *mouv, t_data *data)
{
	// int	som;

	// som = mouv->best_mouv_index_a + (infb->len - mouv->best_mouv_index);
	// if (infa->len - mouv->best_mouv_index_a < som)
	// {
	// 	while (data->tmp2->data != mouv->best_mouv_data && data->tmp1->index != mouv->best_mouv_index_a)
	// 	{
	// 		rrr(infa, infb);
	// 		data->tmp2 = infb->head;
	// 		data->tmp1 = infa->head;
	// 	}
	// 	while (data->tmp2->data != mouv->best_mouv_data)
	// 	{
	// 		rrb(infb);
	// 		data->tmp2 = infb->head;
	// 	}
	// 	while (data->tmp1->index != mouv->best_mouv_index_a)
	// 	{
	// 		rra(infa);
	// 		data->tmp1 = infa->head;
	// 	}
	// }
	while (data->tmp2->data != mouv->best_mouv_data)
	{
		rrb(infb);
		data->tmp2 = infb->head;
	}
	while (data->tmp1->index != mouv->best_mouv_index_a)
	{
		ra(infa);
		data->tmp1 = infa->head;
	}
	pa(infa, infb);
}