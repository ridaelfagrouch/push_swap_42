/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_Mvm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 11:30:24 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/18 16:05:20 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	check_rang1_rang2(t_infsa *infa, t_data *data)
{
	data->tmp = infa->head;
	while (data->tmp)
	{
		if (data->tmp->index <= infa->len - 2)
			check_rang1(infa, data);
		else
			data->tmp3 = data->tmp;
		if (data->tmp2->data > data->tmp->data && \
			data->tmp2->data < data->tmp3->data)
		{
			check_rang2(infa, data);
			break ;
		}
		data->tmp = data->tmp->next;
	}
	data->tmp2 = data->tmp2->next;
}

/* ************************************************************************** */

void	found_mouv_stack_a(t_infsa *infa, t_infsb *infb)
{
	t_data	data;

	data.tmp = infa->head;
	data.tmp2 = infb->head;
	while (data.tmp2)
	{
		if (data.tmp2->data < infa->head->data && \
			data.tmp2->data > infa->tail->data)
		{
			data.tmp2->best_mva = 0;
			data.tmp2->best_mvb_index = 0;
			data.tmp2 = data.tmp2->next;
		}
		else
			check_rang1_rang2(infa, &data);
	}
	check_negative(infa, infb, &data);
}
