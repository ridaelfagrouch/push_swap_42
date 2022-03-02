/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_pb_rb_rrb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:43:33 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/02 17:58:37 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	sb(t_inf_sb *infb)
{
	t_data	data;

	if (infb->len > 2)
	{
		data.tmp = infb->head;
		data.tmp2 = data.tmp->next;
		data.tmp3 = data.tmp2->next;
		data.tmp2->next = data.tmp;
		data.tmp->prev = data.tmp2;
		data.tmp->next = data.tmp3;
		data.tmp3->prev = data.tmp;
		infb->head = data.tmp2;
	}
	else if (infb->len == 2)
	{
		data.tmp = infb->head;
		infb->tail = data.tmp;
		infb->head = data.tmp->next;
		infb->head->next = infb->tail;
		infb->tail->prev = infb->head;
		infb->tail->next = NULL;
	}
}

/* ************************************************************************** */

void	pb(t_inf_sa *infa, t_inf_sb *infb)
{
	t_data	data;

	if (infb->len == 0 && infa->len >= 1)
	{
		data.tmp = infa->head;
		infb->head = infa->head;
		infa->head = data.tmp->next;
		infb->head->data = data.tmp->data;
		infb->head->next = NULL;
		infb->tail = infb->head;
		infb->len++;
		infa->len--;
	}
	else if (infa->len >= 1)
	{
		data.tmp = infa->head;
		data.tmp2 = infb->head;
		infa->head = data.tmp->next;
		data.tmp->next = data.tmp2;
		data.tmp2->prev = data.tmp;
		infb->head = data.tmp;
		infb->len++;
		infa->len--;
	}
}

/* ************************************************************************** */

void	rb(t_inf_sb *infb)
{
	t_data	data;

	if (infb->len > 1)
	{
		data.tmp = infb->head;
		infb->head = infb->head->next;
		data.tmp2 = infb->tail;
		data.tmp->prev = data.tmp2;
		data.tmp2->next = data.tmp;
		data.tmp->next = NULL;
		infb->tail = data.tmp;
	}
}

/* ************************************************************************** */

void	rrb(t_inf_sb *infb)
{
	t_data	data;

	if (infb->len > 1)
	{
		data.tmp = infb->head;
		data.tmp2 = infb->tail;
		infb->tail = infb->tail->prev;
		data.tmp2->next = data.tmp;
		data.tmp->prev = data.tmp2;
		infb->head = data.tmp2;
		infb->tail->next = NULL;
	}
}
