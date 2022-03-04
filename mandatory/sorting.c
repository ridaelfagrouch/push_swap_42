/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:43:27 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/04 19:02:32 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	long_i_s(t_inf_sa *infa, t_inf_sb *infb)
{
	t_data	data;
	int		nember_befor;
	int		index_befor;

	(void)infb;
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
	t_data	data;
	int		i;

	(void)infb;
	i = -1;
	if (infa->small_index >= (infa->len / 2))
	{
		while (infa->head->data != infa->small)
			rra(infa);
	}
	else
	{
		while (infa->head->data != infa->small)
			ra(infa);
	}
	data.tmp = infa->head;
	infa->small_index = 0;
	while (data.tmp)
	{
		data.tmp->index = i + 1;
		data.tmp->lenght = 1;
		data.tmp = data.tmp->next;
		i++;
	}
	long_i_s(infa, infb);
}
