/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len_disp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:48:16 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/19 18:48:38 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		ft_printf("data = %d\n", infa.head->data);
		infa.head = infa.head->next;
	}
}

/* ************************************************************************** */

void	display_b(t_infsb infb)
{
	while (infb.head != NULL)
	{
		ft_printf("data = %d | index = %d\n", infb.head->data, infb.head->index);
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
