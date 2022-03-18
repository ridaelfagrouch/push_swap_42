/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:43:27 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/18 19:58:55 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	native_infa(t_data *data, t_infsa *original, t_infsa *infa)
{
	data->tmp4->next = data->tmp3;
	data->tmp3->prev = data->tmp4;
	data->tmp2->next = NULL;
	data->tmp->prev = NULL;
	original->head = data->tmp;
	original->tail = data->tmp2;
	infa->head = original->head;
	infa->tail = original->tail;
}

/* ************************************************************************** */

void	best_mouv_(t_infsa *infa, t_best_mouv *best)
{
	t_data	data;
	int		b_mouv;
	int		i;

	data.tmp = infa->head;
	b_mouv = infa->len;
	i = 0;
	while (data.tmp)
	{
		while (i < infa->len && data.tmp->best_mvb == -1)
		{
			data.tmp = data.tmp->next;
			i++;
		}
		if (i == infa->len)
			break ;
		if (data.tmp->best_mvb != -1 && data.tmp->best_mvb < b_mouv)
		{
			b_mouv = data.tmp->best_mvb;
			best->best_mouv_index = data.tmp->index;
		}
		data.tmp = data.tmp->next;
		i++;
	}
}

/* ************************************************************************** */

void	sort_three(t_infsa *infa)
{
	if (infa->head->data == infa->small && \
		infa->head->next->data > infa->tail->data)
	{
		sa(infa);
		ra(infa);
	}
	else if (infa->head->next->data == infa->small)
	{
		if (infa->head->data > infa->tail->data)
			ra(infa);
		else
			sa(infa);
	}
	else if (infa->tail->data == infa->small)
	{
		if (infa->head->data > infa->head->next->data)
			sa(infa);
		rra(infa);
	}
}

/* ************************************************************************** */

void	sort(t_infsa *infa, t_infsb *infb)
{
	t_data		data;
	t_infsa		original;
	int			i;

	i = -1;
	original.head = infa->head;
	original.tail = infa->tail;
	if (infa->head->data != infa->small && infa->len > 3)
		fake_head(infa, infb, &data, &original);
	index_stack(infa, infb);
	if (infa->len == 3)
	{
		ft_free_b(infb);
		sort_three(infa);
	}
	else
	{
		long_i_s_index(infa);
		long_i_s(infa, infb, &data, &original);
		start_sort(infa, infb);
	}
}
