/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_Mv_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 11:30:24 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/18 16:01:32 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	found_mouv_stack_b(t_infsb *infb)
{
	t_data	data;

	data.tmp = infb->head;
	while (data.tmp)
	{
		if (data.tmp->index > (infb->len / 2))
		{
			data.tmp->best_mvb = infb->len - data.tmp->index;
			data.tmp->best_mvb_index = -1;
		}
		else
		{
			data.tmp->best_mvb = data.tmp->index;
			data.tmp->best_mvb_index = -1;
		}
		data.tmp = data.tmp->next;
	}
}

/* ************************************************************************** */

void	check_small_index(t_infsa *infa)
{
	t_data	data;

	data.tmp = infa->head;
	while (data.tmp)
	{
		if (data.tmp->data == infa->small)
		{
			infa->small_index = data.tmp->index;
			break ;
		}
		data.tmp = data.tmp->next ;
	}
}

/* ************************************************************************** */

void	check_negative(t_infsa *infa, t_infsb *infb, t_data	*data)
{
	while (1)
	{
		check_small_index(infa);
		data->tmp3 = infb->head;
		data->i = 0;
		while (data->tmp3 && data->tmp3->best_mva != -1 && \
			data->i < infb->len - 1)
		{
			data->tmp3 = data->tmp3->next;
			data->i++;
		}
		if (data->tmp3->best_mva == -1)
		{
			if (infa->small_index > (infa->len / 2))
				data->tmp3->best_mva = infa->len - infa->small_index;
			else
				data->tmp3->best_mva = infa->small_index;
			data->tmp3->best_mvb_index = infa->small_index;
		}
		if (data->i == infb->len - 1)
			break ;
	}
}

/* ************************************************************************** */

void	check_rang2(t_infsa *infa, t_data *data)
{
	if (data->tmp->index > (infa->len / 2))
	{
		data->tmp2->best_mva = infa->len - data->tmp3->index;
		data->tmp2->best_mvb_index = data->tmp3->index;
	}
	else
	{
		data->tmp2->best_mva = data->tmp3->index;
		data->tmp2->best_mvb_index = data->tmp3->index;
	}
	data->tmp = infa->head;
}

/* ************************************************************************** */

void	check_rang1(t_infsa *infa, t_data *data)
{
	data->tmp3 = data->tmp->next;
	if (data->tmp3->data == infa->small && (data->tmp3->index < infa->len - 1))
	{
		infa->small_index = data->tmp3->index;
		data->tmp3 = data->tmp3->next;
		data->tmp = data->tmp->next;
	}
}
