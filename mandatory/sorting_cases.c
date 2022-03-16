/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:26:09 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/16 19:28:24 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	sorting_case1(t_infsa *infa, t_infsb *infb, \
	t_best_mouv	*mouv, t_data *data)
{
	data->tmp2 = infb->head;
	data->tmp1 = infa->head;
	while (data->tmp2->data != mouv->best_mouv_data)
	{
		if (mouv->best_mouv_index > (infb->len / 2))
			rrb(infb);
		else
			rb(infb);
		data->tmp2 = infb->head;
	}
	pa(infa, infb);
}

/* ************************************************************************** */

void	sorting_case2(t_infsa *infa, t_infsb *infb, \
	t_best_mouv	*mouv, t_data *data)
{
	data->tmp2 = infb->head;
	data->tmp1 = infa->head;
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
	data->tmp2 = infb->head;
	data->tmp1 = infa->head;
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

// void	compare_mouv(t_infsa *infa, t_infsb *infb, \
// 	t_best_mouv *mouv, t_data *data)
// {
// 	if (mouv->best_mouv_index_a > mouv->best_mouv_index)
// 		data->i = mouv->best_mouv_index_a;
// 	else
// 		data->i = mouv->best_mouv_index;
// 	if ((infa->len - mouv->best_mouv_index_a) > (infb->len - mouv->best_mouv_index))
// 		data->j = infa->len - mouv->best_mouv_index_a;
// 	else
// 		data->j = infb->len - mouv->best_mouv_index;
// }

/* ************************************************************************** */

void	sorting_case4(t_infsa *infa, t_infsb *infb, \
	t_best_mouv *mouv, t_data *data)
{
	data->tmp2 = infb->head;
	data->tmp1 = infa->head;
	// int	som;

	// compare_mouv(infa, infb, mouv, data);
	// som = mouv->best_mouv_index + (infa->len - mouv->best_mouv_index_a);
	// if (data->i < som)
	// {
	// 	while ((data->tmp1->index != mouv->best_mouv_index_a) && \
	// 		(data->tmp2->data != mouv->best_mouv_data))
	// 	{
	// 		rr(infa, infb);
	// 		data->tmp1 = infa->head;
	// 		data->tmp2 = infb->head;
	// 	}
	// 	while (data->tmp1->index != mouv->best_mouv_index_a)
	// 	{
	// 		ra(infa);
	// 		data->tmp1 = infa->head;
	// 	}
	// 	while (data->tmp2->data != mouv->best_mouv_data)
	// 	{
	// 		rb(infb);
	// 		data->tmp2 = infb->head;
	// 	}
	// }
	// else if (data->j < som)
	// {
	// 	while ((data->tmp1->index != mouv->best_mouv_index_a) && \
	// 		(data->tmp2->data != mouv->best_mouv_data))
	// 	{
	// 		rrr(infa, infb);
	// 		data->tmp1 = infa->head;
	// 		data->tmp2 = infb->head;
	// 	}
	// 	while (data->tmp1->index != mouv->best_mouv_index_a)
	// 	{
	// 		rra(infa);
	// 		data->tmp1 = infa->head;
	// 	}
	// 	while (data->tmp2->data != mouv->best_mouv_data)
	// 	{
	// 		rrb(infb);
	// 		data->tmp2 = infb->head;
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
	data->tmp2 = infb->head;
	data->tmp1 = infa->head;
	// int	som;

	// compare_mouv(infa, infb, mouv, data);
	// som = mouv->best_mouv_index_a + (infb->len - mouv->best_mouv_index);
	// if (data->i < data->j)
	// 	data->end = data->i;
	// else
	// 	data->end = data->j;
	// if (data->i < som)
	// {
	// 	while ((data->tmp1->index != mouv->best_mouv_index_a) && \
	// 		(data->tmp2->data != mouv->best_mouv_data))
	// 	{
	// 		rr(infa, infb);
	// 		data->tmp1 = infa->head;
	// 		data->tmp2 = infb->head;
	// 	}
	// 	while (data->tmp1->index != mouv->best_mouv_index_a)
	// 	{
	// 		ra(infa);
	// 		data->tmp1 = infa->head;
	// 	}
	// 	while (data->tmp2->data != mouv->best_mouv_data)
	// 	{
	// 		rb(infb);
	// 		data->tmp2 = infb->head;
	// 	}
	// }
	// else if (data->j < som)
	// {
	// 	while ((data->tmp1->index != mouv->best_mouv_index_a) && \
	// 		(data->tmp2->data != mouv->best_mouv_data))
	// 	{
	// 		rrr(infa, infb);
	// 		data->tmp1 = infa->head;
	// 		data->tmp2 = infb->head;
	// 	}
	// 	while (data->tmp1->index != mouv->best_mouv_index_a)
	// 	{
	// 		rra(infa);
	// 		data->tmp1 = infa->head;
	// 	}
	// 	while (data->tmp2->data != mouv->best_mouv_data)
	// 	{
	// 		rrb(infb);
	// 		data->tmp2 = infb->head;
	// 	}
	// }
	// else
	// {
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

// t_node	*get_next_node(t_node *node, t_stack *stack)
// {
// 	if (node == stack->tail)
// 		return (stack->head);
// 	return (node->next);
// }

// node = get_next_node(node);