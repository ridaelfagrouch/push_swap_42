/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_pa_ra_rra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:43:22 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/02 12:06:50 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	sa(t_inf_sa *infa)
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
}

/* ************************************************************************** */

void	pa(t_inf_sa *infa, t_inf_sb *infb)
{
	t_data	data;

	if (infb->len >= 1 && infa->len != 0)
	{
		data.tmp = infb->head;
		data.tmp2 = infa->head;
		infb->head = infb->head->next;
		data.tmp->next = data.tmp2;
		data.tmp2->prev = data.tmp;
		infa->head = data.tmp;
		infa->len++;
		infb->len--;
	}
	else if (infa->len == 0)
	{
		data.tmp = infb->head;
		infa->head = infb->head;
		infb->head = data.tmp->next;
		infa->head->data = data.tmp->data;
		infa->head->next = NULL;
		infa->tail = infa->head;
		infa->len++;
		infb->len--;
	}
}

/* ************************************************************************** */

void	rra(t_inf_sa *infa)
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
}

/* ************************************************************************** */

void	ra(t_inf_sa *infa)
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
}
