/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_i_sub_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:06:29 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/19 16:34:33 by rel-fagr         ###   ########.fr       */
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

int	*stor_long_i_s(t_infsa infa, t_data *data, int count)
{
	int	sub;
	int	i;
	int	*tab;

	i = 1;
	tab = (int *)malloc(count * sizeof(int));
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

void	check_best_mv_a(t_infsa *infa, int *tab, t_data *data)
{
	while (data->i <= infa->l_i_sub_len - 1)
	{
		data->tmp1 = infa->head;
		while (data->tmp1)
		{
			if (data->tmp1->data == tab[data->i])
			{
				data->tmp1->best_mvb = -1;
				break ;
			}
			data->tmp1 = data->tmp1->next;
		}
		data->i++;
	}
}

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
	check_best_mv_a(infa, tab, &data);
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
			while (data.tmp != infa->head)
				rra(infa);
		else
			while (data.tmp != infa->head)
				ra(infa);
		pb(infa, infb);
		infb->head->best_mva = -1;
		index_stack(infa, infb);
		data.i++;
	}
	free(tab);
	index_stack(infa, infb);
}
