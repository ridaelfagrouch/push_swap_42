/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_i_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:02:15 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/18 19:11:45 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	fake_head(t_infsa *infa, t_infsb *infb, t_data *data, t_infsa *original)
{
	original->head = infa->head;
	original->tail = infa->tail;
	data->tmp = infa->head;
	data->tmp2 = infa->tail;
	data->tmp3 = infa->head;
	while (data->tmp3->data != infa->small)
		data->tmp3 = data->tmp3->next;
	if (data->tmp3 != data->tmp)
	{
		data->tmp4 = data->tmp3->prev;
		data->tmp4->next = NULL;
		infa->head = data->tmp3;
		infa->head->prev = NULL;
		data->tmp2->next = data->tmp;
		data->tmp->prev = data->tmp2;
		infa->tail = data->tmp4;
		index_stack(infa, infb);
	}
}

/* ************************************************************************** */

void	count_calculat(t_data *data, t_infsa *infa, int *sub, int *count)
{
	while (data->tmp1 != infa->head)
	{
		data->tmp1 = data->tmp1->prev;
		if (data->tmp1->index == *sub)
		{
			(*count)++;
			*sub = data->tmp1->sub_s;
		}
	}
}

/* ************************************************************************** */

void	long_i_s(t_infsa *infa, t_infsb *infb, t_data *data, t_infsa *original)
{
	int		*tab;
	int		max_len;
	int		sub;
	int		count;

	count = 1;
	max_len = 1;
	tab = NULL;
	data->temp = infa->head;
	max_lenght(data, &max_len);
	sub = data->tmp1->sub_s;
	count_calculat(data, infa, &sub, &count);
	infa->l_i_sub_len = count;
	tab = stor_long_i_s(*infa, data, count);
	if (original->head != infa->head)
		native_infa(data, original, infa);
	index_stack(infa, infb);
	push_no_lis(infa, infb, tab);
}

/* ************************************************************************** */

void	check_tmp_lenght(int *nember_befor, int *index_befor, t_data *data)
{
	if (data->tmp->lenght + 1 > data->tmp2->lenght)
	{
		data->tmp2->lenght = data->tmp->lenght + 1;
		data->tmp2->sub_s = data->tmp->index;
		*nember_befor = data->tmp->data;
		*index_befor = data->tmp->index;
	}
	else if (data->tmp->lenght + 1 == data->tmp2->lenght)
	{
		if (data->tmp->data < *nember_befor)
			data->tmp2->sub_s = data->tmp->index;
		else
			data->tmp2->sub_s = *index_befor;
	}
}

/* ************************************************************************** */

void	long_i_s_index(t_infsa *infa)
{
	t_data	data;
	int		nember_befor;
	int		index_befor;

	data.tmp = infa->head;
	data.tmp2 = data.tmp->next;
	while (data.tmp2)
	{
		data.tmp = infa->head;
		while (data.tmp != data.tmp2 && data.tmp)
		{
			if (data.tmp->data < data.tmp2->data)
				check_tmp_lenght(&nember_befor, &index_befor, &data);
			data.tmp = data.tmp->next;
		}
		data.tmp2 = data.tmp2->next;
	}
}
