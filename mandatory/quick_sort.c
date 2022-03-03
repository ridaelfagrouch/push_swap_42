/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:43:27 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/03 17:08:07 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	partition(t_inf_sa *infa, t_inf_sb *infb, t_data *data)
{
	int j = 0;

	while (data->start < data->end)
	{
		while (data->tmp->data <= data->pivot)
		{
			data->start++;
			data->tmp++;
		}
		ft_printf("hello\n");
		while (data->tmp2->data > data->pivot)
		{
			data->end--;
			data->tmp2--;
		}
		if (data->start < data->end)
		{
			data->tmp3 = infa->head;
			while (data->tmp3->data != data->tmp->data)
			{
				pb(infa, infb);
				data->tmp3++;
			}
			while (data->tmp2 < infa->tail)
			{
				rra(infa);
				pb(infa, infb);
				j++;
			}
			rra(infa);
			sa(infa);
			ra(infa);
			while (j > 0)
			{
				pa(infa, infb);
				ra(infa);
				j--;
			}
			while (infb->len > 0)
			{
				pa(infa, infb);
				infb->len--;
			}
		}
	}
	data->tmp4->data = infa->head->data;
	infa->head->data = data->tmp2->data;
	data->tmp2->data = data->tmp4->data;
}

void	quick_sort_(t_inf_sa *infa, t_inf_sb *infb)
{
	t_data	data;
	int		location;

	data.tmp = infa->head->next;
	data.tmp2 = infa->tail;
	data.pivot = infa->head->data;
	data.start = 0;
	data.end = infa->len;
	if (data.start < data.end)
	{
		partition(infa, infb, &data);
		location = data.end;
		data.end--;
		data.tmp2--;
		quick_sort_(infa, infb);
		data.start = location + 1;
		quick_sort_(infa, infb);
	}
}
