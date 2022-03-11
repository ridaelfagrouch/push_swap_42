/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:43:27 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/11 23:05:27 by rel-fagr         ###   ########.fr       */
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

int	*stor_long_i_s(t_inf_sa infa, t_data *data, int *count)
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
	ft_printf("%d\n", tab[0]);
	sub = data->tmp1->sub_s;
	while (data->tmp1 != infa.head)
	{
		data->tmp1 = data->tmp1->prev;
		if (data->tmp1->index == sub)
		{
			tab[i] = data->tmp1->data;
			ft_printf("%d\n", tab[i]);
			sub = data->tmp1->sub_s;
			i++;
		}
	}
	return (tab);
}

/* ************************************************************************** */

void	native_infa(t_data *data, t_inf_sa *original, t_inf_sa *infa)
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

void	best_mouv_l_i_s(t_inf_sa *infa, t_inf_sb *infb, int *tab)
{
	t_data	data;
	int		i;

	(void)infb;
	data.tmp = infa->head;
	i = 0;
	while (data.tmp)
	{
		if (data.tmp->index > (infa->len / 2))
			data.tmp->b_m_lis = infa->len - data.tmp->index;
		else
			data.tmp->b_m_lis = data.tmp->index;
		data.tmp = data.tmp->next;
	}
	while (i <= infa->l_i_sub_len - 1)
	{
		data.tmp1 = infa->head;
		while (data.tmp1)
		{
			if (data.tmp1->data == tab[i])
			{
				data.tmp1->b_m_lis = -1;
				break ;
			}
			data.tmp1 = data.tmp1->next;
		}
		i++;
	}
}

/* ************************************************************************** */

void	best_mouv_(t_inf_sa *infa, t_best_mouv *best)
{
	t_data	data;
	int		b_mouv;

	data.tmp = infa->head;
	b_mouv = infa->len;
	while (data.tmp)
	{
		if (data.tmp->b_m_lis == -1)
			data.tmp = data.tmp->next;
		if (data.tmp->b_m_lis != -1 && data.tmp->b_m_lis < b_mouv)
		{
			b_mouv = data.tmp->b_m_lis;
			best->best_mouv_index = data.tmp->index;
			data.tmp = data.tmp->next;
		}
		else
			data.tmp = data.tmp->next;
	}
}

/* ************************************************************************** */

void	push_no_lis(t_inf_sa *infa, t_inf_sb *infb, int *tab)
{
	t_best_mouv	best;
	t_data		data;

	data.i = 0;
	data.j = infa->len;
	while (data.i < (data.j - infa->l_i_sub_len))
	{
		best_mouv_l_i_s(infa, infb, tab);
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
		index_stack(infa, infb);
		data.i++;
	}
}

/* ************************************************************************** */

void	long_i_s(t_inf_sa *infa, t_inf_sb *infb, t_data *data, t_inf_sa *original)
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
	(void)original;
	infa->l_i_sub_len = count;
	tab = stor_long_i_s(*infa, data, &count);
	native_infa(data, original, infa);
	index_stack(infa, infb);
	push_no_lis(infa, infb, tab);
}

/* ************************************************************************** */

void	long_i_s_index(t_inf_sa *infa)
{
	t_data	data;
	int		nember_befor;
	int		index_befor;

	data.tmp = infa->head;
	data.tmp2 = data.tmp->next;
	data.tmp->sub_s = -1;
	while (data.tmp2)
	{
		data.tmp = infa->head;
		while (data.tmp != data.tmp2 && data.tmp)
		{
			if (data.tmp->data < data.tmp2->data)
			{
				if (data.tmp->lenght + 1 > data.tmp2->lenght)
				{
					data.tmp2->lenght = data.tmp->lenght + 1;
					data.tmp2->sub_s = data.tmp->index;
					nember_befor = data.tmp->data;
					index_befor = data.tmp->index;
				}
				else if (data.tmp->lenght + 1 == data.tmp2->lenght)
				{
					if (data.tmp->data < nember_befor)
						data.tmp2->sub_s = data.tmp->index;
					else
						data.tmp2->sub_s = index_befor;
				}
			}
			data.tmp = data.tmp->next;
		}
		data.tmp2 = data.tmp2->next;
	}
}

/* ************************************************************************** */

void	sort(t_inf_sa *infa, t_inf_sb *infb)
{
	t_data		data;
	t_inf_sa	original;
	int			i;

	i = -1;
	original.head = infa->head;
	original.tail = infa->tail;
	data.tmp = infa->head;
	data.tmp2 = infa->tail;
	data.tmp3 = infa->head;
	while (data.tmp3->data != infa->small)
		data.tmp3 = data.tmp3->next;
	if (data.tmp3 != data.tmp)
	{
		data.tmp4 = data.tmp3->prev;
		data.tmp4->next = NULL;
		infa->head = data.tmp3;
		infa->head->prev = NULL;
		data.tmp2->next = data.tmp;
		data.tmp->prev = data.tmp2;
		infa->tail = data.tmp4;
		index_stack(infa, infb);
	}
	long_i_s_index(infa);
	long_i_s(infa, infb, &data, &original);
}
