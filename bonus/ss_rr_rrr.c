/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_rr_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:43:43 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/19 20:09:58 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* ************************************************************************** */

void	ssb(t_infsb *infb)
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

void	ss(t_infsa *infa, t_infsb *infb)
{
	t_data	data;

	if (infa->len > 2)
	{
		data.tmp = infa->head;
		data.tmp2 = data.tmp->next;
		data.tmp3 = data.tmp2->next;
		data.tmp2->next = data.tmp;
		data.tmp->prev = data.tmp2;
		data.tmp->next = data.tmp3;
		data.tmp3->prev = data.tmp;
		infa->head = data.tmp2;
	}
	else if (infa->len == 2)
	{
		data.tmp = infa->head;
		infa->tail = data.tmp;
		infa->head = data.tmp->next;
		infa->head->next = infa->tail;
		infa->tail->prev = infa->head;
		infa->tail->next = NULL;
	}
	ssb(infb);
}

/* ************************************************************************** */

void	rr(t_infsa *infa, t_infsb *infb)
{
	t_data	data;

	if (infa->len > 1)
	{
		data.tmp = infa->head;
		infa->head = infa->head->next;
		data.tmp2 = infa->tail;
		data.tmp->prev = data.tmp2;
		data.tmp2->next = data.tmp;
		data.tmp->next = NULL;
		infa->tail = data.tmp;
	}
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

void	rrr(t_infsa *infa, t_infsb *infb)
{
	t_data	data;

	if (infa->len > 1)
	{
		data.tmp = infa->head;
		data.tmp2 = infa->tail;
		infa->tail = infa->tail->prev;
		data.tmp2->next = data.tmp;
		data.tmp->prev = data.tmp2;
		infa->head = data.tmp2;
		infa->tail->next = NULL;
	}
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
