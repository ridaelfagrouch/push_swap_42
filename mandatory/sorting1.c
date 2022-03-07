/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:51:13 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/07 19:09:36 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	best_mouv(t_inf_sb *infb)
{
	t_best_mouv	mouv;
	t_data		data;
	int			mouv_total;
	int			mouv_total_prev;

	data.tmp = infb->head;
	mouv_total_prev = data.tmp->best_mouv_a + data.tmp->best_mouv_b;
	mouv.best_mouv_index = data.tmp->index;
	mouv.mouv_a = data.tmp->best_mouv_a;
	mouv.mouv_b = data.tmp->best_mouv_b;
	data.tmp = data.tmp->next;
	while (data.tmp)
	{
		mouv_total = data.tmp->best_mouv_a + data.tmp->best_mouv_b;
		if (mouv_total < mouv_total_prev)
		{
			mouv.best_mouv_index = data.tmp->index;
			mouv.mouv_a = data.tmp->best_mouv_a;
			mouv.mouv_b = data.tmp->best_mouv_b;
			mouv_total_prev = mouv_total;
		}
		data.tmp = data.tmp->next;
	}
	ft_printf("--------best_mouv-----");
	ft_printf("best_mouv_index = %d\n", mouv.best_mouv_index);
}

/* ************************************************************************** */

void	found_mouv_stack_a(t_inf_sa *infa, t_inf_sb *infb)
{
	t_data	data;
	int		count;

	data.tmp = infa->head;
	data.tmp2 = infb->head;
	count = 0;
	while (data.tmp2)
	{
		while (data.tmp)
		{
			count++;
			if (data.tmp->index <= infa->len - 2)
				data.tmp3 = data.tmp->next;
			else
				data.tmp3 = data.tmp;
			if (data.tmp2->data > data.tmp->data && \
				data.tmp2->data < data.tmp3->data)
			{
				if (data.tmp->index >= (infa->len / 2))
					data.tmp2->best_mouv_a = ((infa->len - count) * 2) + 1;
				else
					data.tmp2->best_mouv_a = count * 2;
				count = 0;
				data.tmp = infa->head;
				break ;
			}
			else if(count == infa->len)
			{
				data.tmp2->best_mouv_a = 1;
				count = 0;
				data.tmp = infa->head;
				break ;
			}
			data.tmp = data.tmp->next;
		}
		data.tmp2 = data.tmp2->next;
	}
}

/* ************************************************************************** */

void	found_mouv_stack_b(t_inf_sa *infa, t_inf_sb *infb)
{
	t_data	data;

	(void)infa;
	data.tmp = infb->head;
	while (data.tmp)
	{
		if (data.tmp->index >= (infb->len / 2))
			data.tmp->best_mouv_b = infb->len - data.tmp->index;
		else
			data.tmp->best_mouv_b = data.tmp->index;
		data.tmp = data.tmp->next;
	}
}

/* ************************************************************************** */

void	index_stack(t_inf_sa *infa, t_inf_sb *infb)
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

/* ************************************************************************** */

void	start_sorting(t_inf_sa *infa, t_inf_sb *infb, int *tab)
{
	t_data	data;

	data.j = 0;
	while (tab[data.j] != 0)
		data.j++;
	data.i = data.j;
	data.tmp = infa->head;
	while (data.i >= 0)
	{
		while (data.tmp->index == tab[data.i])
		{
			ra(infa);
			data.tmp = infa->head;
			data.i--;
		}
		if (data.tmp->index != 0)
		{
			pb(infa, infb);
			data.tmp = infa->head;
		}
	}
	index_stack(infa, infb);
	found_mouv_stack_b(infa, infb);
	found_mouv_stack_a(infa, infb);
	best_mouv(infb);
}
