/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len_disp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:53:34 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/16 19:30:07 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	len_stack_a(t_infsa *infa)
{
	t_data	data;

	infa->len = 0;
	data.tmp = infa->head;
	while (data.tmp != NULL)
	{
		data.tmp = data.tmp->next;
		infa->len++;
	}
}

/* ************************************************************************** */

void	len_stack_b(t_infsb *infb)
{
	t_data	data;

	infb->len = 0;
	data.tmp = infb->head;
	while (data.tmp != NULL)
	{
		data.tmp = data.tmp->next;
		infb->len++;
	}
}

/* ************************************************************************** */

void	display_a(t_infsa infa)
{
	while (infa.head != NULL)
	{
		ft_printf("data = %d | index = %d | lenght = %d | sub = %d | best_mouv_lis = %d\n", infa.head->data, infa.head->index, infa.head->lenght, infa.head->sub_s, infa.head->best_mvb);
		infa.head = infa.head->next;
	}
}

/* ************************************************************************** */

void	display_b(t_infsb infb)
{
	while (infb.head != NULL)
	{
		ft_printf("data = %d | index = %d | best_mv_b = %d | best_mv_a = %d | best_mvb_index = %d\n", infb.head->data, infb.head->index, infb.head->best_mvb, infb.head->best_mva, infb.head->best_mvb_index);
		infb.head = infb.head->next;
	}
}

/* ************************************************************************** */

void	index_stack(t_infsa *infa, t_infsb *infb)
{
	t_data	data;

	data.i = -1;
	data.tmp = infa->head;
	data.tmp2 = infb->head;
	while (data.tmp)
	{
		data.tmp->index = data.i + 1;
		data.tmp = data.tmp->next;
		data.i++;
	}
	data.i = -1;
	while (data.tmp2)
	{
		data.tmp2->index = data.i + 1;
		data.tmp2 = data.tmp2->next;
		data.i++;
	}
}
