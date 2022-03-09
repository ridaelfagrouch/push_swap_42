/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len_disp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:53:34 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/09 16:57:28 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	len_stack_a(t_inf_sa *infa)
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

void	len_stack_b(t_inf_sb *infb)
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

void	display_a(t_inf_sa infa)
{
	while (infa.head != NULL)
	{
		ft_printf("data = %d | index = %d | fack_index = %d\n", infa.head->data, infa.head->index, infa.head->fack_index);
		infa.head = infa.head->next;
	}
}

/* ************************************************************************** */

void	display_b(t_inf_sb infb)
{
	while (infb.head != NULL)
	{
		ft_printf("data = %d | index = %d | best_mouv_b = %d | best_mouv_a = %d | index_best_mouv = %d\n", infb.head->data, infb.head->index,  infb.head->best_mouv_b, infb.head->best_mouv_a, infb.head->index_best_mouv_a);
		infb.head = infb.head->next;
	}
}
