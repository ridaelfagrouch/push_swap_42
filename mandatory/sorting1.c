/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:51:13 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/09 18:53:26 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	best_mouv(t_inf_sb *infb, t_best_mouv *mouv)
{
	t_data		data;
	int			mouv_total;
	int			mouv_total_prev;

	data.tmp = infb->head;
	mouv_total_prev = data.tmp->best_mouv_a + data.tmp->best_mouv_b;
	mouv->best_mouv_index = data.tmp->index;
	mouv->mouv_a = data.tmp->best_mouv_a;
	mouv->mouv_b = data.tmp->best_mouv_b;
	mouv->best_mouv_data = data.tmp->data;
	mouv->index_best_mouv_a = data.tmp->index_best_mouv_a;
	mouv->index_best_mouv_b = data.tmp->index;
	data.tmp = data.tmp->next;
	while (data.tmp)
	{
		mouv_total = data.tmp->best_mouv_a + data.tmp->best_mouv_b;
		if (mouv_total < mouv_total_prev)
		{
			mouv->best_mouv_index = data.tmp->index;
			mouv->best_mouv_data = data.tmp->data;
			mouv->index_best_mouv_a = data.tmp->index_best_mouv_a;
			mouv->index_best_mouv_b = data.tmp->index;
			mouv->mouv_a = data.tmp->best_mouv_a;
			mouv->mouv_b = data.tmp->best_mouv_b;
			mouv_total_prev = mouv_total;
		}
		data.tmp = data.tmp->next;
	}
	// ft_printf("--------best_mouv-----\n");
	// ft_printf("best_mouv_index = %d | best_mouv_data = %d | index_best_mouv_in_a = %d | index_best_mouv_in_b = %d\n", mouv.best_mouv_index, mouv.best_mouv_data, mouv.index_best_mouv_a, mouv.index_best_mouv_b);
}

/* ************************************************************************** */

void	found_mouv_stack_a(t_inf_sa *infa, t_inf_sb *infb)
{
	t_data	data;
	int		count;

	count = 0;
	while (infa->head->data != infa->small)
	{
		if (infa->small_index >= (infa->len / 2))
			rra(infa);
		else
			ra(infa);
	}
	data.tmp = infa->head;
	data.tmp2 = infb->head;
	index_stack(infa, infb);
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
				if (data.tmp->index > (infa->len / 2))
					data.tmp2->best_mouv_a = ((infa->len - count) * 2) + 1;
				else
					data.tmp2->best_mouv_a = count * 2;
				data.tmp2->index_best_mouv_a = data.tmp3->index;
				count = 0;
				data.tmp = infa->head;
				break ;
			}
			else if (count == infa->len)
			{
				data.tmp2->best_mouv_a = 1;
				data.tmp2->index_best_mouv_a = infa->len;
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
		if (data.tmp->index > (infb->len / 2))
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

void	fack_index(t_inf_sa *infa)
{
	t_data	data;
	int		i;

	i = -1;
	data.tmp = infa->head;
	while (data.tmp != NULL)
	{
		data.tmp->fack_index = i + 1;
		data.tmp = data.tmp->next;
		i++;
	}
}

/* ************************************************************************** */

void	found_index_small(t_inf_sa *infa)
{
	t_data	data;

	data.tmp = infa->head;
	while (data.tmp)
	{
		if (data.tmp->data != infa->small)
			data.tmp = data.tmp->next;
		else
		{
			infa->small_index = data.tmp->index;
			break ;
		}
	}
}

/* ************************************************************************** */

void	start_sorting(t_inf_sa *infa, t_inf_sb *infb, int *tab)
{
	t_data		data;
	t_best_mouv mouv;

	fack_index(infa);
	data.j = 0;
	while (tab[data.j] != 0)
		data.j++;
	data.i = data.j;
	data.tmp = infa->head;
	while (data.tmp)
	{
		while (tab[data.j] != data.tmp->index && data.j >= 0)
			data.j--;
		if (data.j == -1)
		{
			if (data.tmp->fack_index >= (infa->len / 2))
			{
				while (data.tmp != infa->head)
					rra(infa);
				pb(infa, infb);
				data.tmp = infa->head;
			}
			else
			{
				while (data.tmp != infa->head)
					ra(infa);
				pb(infa, infb);
				data.tmp = infa->head;
			}
		}
		else
			data.tmp = data.tmp->next;
		data.j = data.i;
	}
	index_stack(infa, infb);
	found_mouv_stack_b(infa, infb);
	found_index_small(infa);
	found_mouv_stack_a(infa, infb);
	best_mouv(infb, &mouv);
	start_oper(infa, infb, &mouv);
}
