/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:43:27 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/16 19:26:10 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	max_lenght(t_data *data, int *max_lenght)
{
	while (data->temp)
	{
		if (data->temp->lenght >= *max_lenght)
		{
			*max_lenght = data->temp->lenght;
			data->tmp1 = data->temp;
		}
		data->temp = data->temp->next;
	}
	data->temp = data->tmp1;
}

/* ************************************************************************** */

int	*stor_long_i_s(t_infsa infa, t_data *data, int *count)
{
	int	sub;
	int	i;
	int	*tab;

	i = 1;
	tab = (int *)malloc(*count * sizeof(int));
	if (!tab)
		exit(1);
	data->tmp1 = data->temp;
	tab[0] = data->tmp1->data;
	sub = data->tmp1->sub_s;
	while (data->tmp1 != infa.head)
	{
		data->tmp1 = data->tmp1->prev;
		if (data->tmp1->index == sub)
		{
			tab[i] = data->tmp1->data;
			sub = data->tmp1->sub_s;
			i++;
		}
	}
	return (tab);
}

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

void	best_mouv_l_i_s(t_infsa *infa, int *tab)
{
	t_data	data;

	data.tmp = infa->head;
	data.i = 0;
	while (data.tmp)
	{
		if (data.tmp->index > (infa->len / 2))
			data.tmp->best_mvb = infa->len - data.tmp->index;
		else
			data.tmp->best_mvb = data.tmp->index;
		data.tmp = data.tmp->next;
	}
	while (data.i <= infa->l_i_sub_len - 1)
	{
		data.tmp1 = infa->head;
		while (data.tmp1)
		{
			if (data.tmp1->data == tab[data.i])
			{
				data.tmp1->best_mvb = -1;
				break ;
			}
			data.tmp1 = data.tmp1->next;
		}
		data.i++;
	}
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
			data.tmp = data.tmp->next;
			i++;
		}
		else
		{
			data.tmp = data.tmp->next;
			i++;
		}
	}
}

/* ************************************************************************** */

void	push_no_lis(t_infsa *infa, t_infsb *infb, int *tab)
{
	t_best_mouv	best;
	t_data		data;

	data.i = 0;
	data.j = infa->len;
	while (data.i < (data.j - infa->l_i_sub_len))
	{
		best_mouv_l_i_s(infa, tab);
		best_mouv_(infa, &best);
		data.tmp = infa->head;
		while (data.tmp->index != best.best_mouv_index)
			data.tmp = data.tmp->next;
		if (best.best_mouv_index > infa->len / 2)
		{
			while (data.tmp != infa->head)
				rra(infa);
		}
		else
		{
			while (data.tmp != infa->head)
				ra(infa);
		}
		pb(infa, infb);
		infb->head->best_mva = -1;
		index_stack(infa, infb);
		data.i++;
	}
	index_stack(infa, infb);
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
	while (data->tmp1 != infa->head)
	{
		data->tmp1 = data->tmp1->prev;
		if (data->tmp1->index == sub)
		{
			count++;
			sub = data->tmp1->sub_s;
		}
	}
	infa->l_i_sub_len = count;
	tab = stor_long_i_s(*infa, data, &count);
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

void	sort(t_infsa *infa, t_infsb *infb)
{
	t_data		data;
	t_infsa		original;
	int			i;

	i = -1;
	if (infa->head->data != infa->small && infa->len > 3)
		fake_head(infa, infb, &data, &original);
	else
	{
		original.head = infa->head;
		original.tail = infa->tail;
	}
	index_stack(infa, infb);
	if (infa->len == 3)
		sort_three(infa);
	else
	{
		long_i_s_index(infa);
		long_i_s(infa, infb, &data, &original);
		start_sort(infa, infb);
	}
}
