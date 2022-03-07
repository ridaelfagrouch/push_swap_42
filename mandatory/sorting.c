/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:43:27 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/07 12:57:39 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	long_i_s(t_inf_sa *infa, t_inf_sb *infb)
{
	t_data	data;
	int		tab[500];
	int		i;
	int		sub_nember;

	i = 1;
	data.tmp = infa->tail;
	tab[0] = data.tmp->index;
	tab[1] = data.tmp->sub_s;
	while (i)
	{
		if (tab[i] == 0)
			break ;
		sub_nember = data.tmp->sub_s;
		while (sub_nember != data.tmp->index && data.tmp->index != 0)
			data.tmp = data.tmp->prev;
		i++;
		tab[i] = data.tmp->sub_s;
	}
	start_sorting(infa, infb, tab);
}

/* ************************************************************************** */

void	long_i_s_index(t_inf_sa *infa, t_inf_sb *infb)
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
	long_i_s(infa, infb);
}

/* ************************************************************************** */

void	sort(t_inf_sa *infa, t_inf_sb *infb)
{
	t_data	data;
	int		i;

	i = -1;
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
		data.tmp3->prev = infa->head;
		infa->head->prev = NULL;
		data.tmp2->next = data.tmp;
		data.tmp->prev = data.tmp2;
		infa->tail = data.tmp4;
		index_stack(infa, infb);
	}
	long_i_s_index(infa, infb);
}
