/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:54:41 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/12 18:10:37 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	best_mouv(t_infsb *infb, t_best_mouv *mouv)
{
	t_data	data;
	int		mouv_to;
	int		mouv_to_prev;

	data.tmp = infb->head;
	mouv_to_prev = data.tmp->best_mva + data.tmp->best_mvb;
	mouv->best_mouv_index = data.tmp->index;
	mouv->best_mv_a = data.tmp->best_mva;
	mouv->best_mv_b = data.tmp->best_mvb;
	data.tmp = data.tmp->next;
	while (data.tmp)
	{
		mouv_to = data.tmp->best_mva + data.tmp->best_mvb;
		if (mouv_to < mouv_to_prev)
		{
			mouv->best_mouv_index = data.tmp->index;
			mouv->best_mv_a = data.tmp->best_mva;
			mouv->best_mv_b = data.tmp->best_mvb;
			mouv_to_prev = mouv_to;
		}
		data.tmp = data.tmp->next;
	}
}

/* ************************************************************************** */

void	start_sort(t_infsa *infa, t_infsb *infb)
{
	t_best_mouv	mouv;

	found_mouv_stack_b(infb);
	found_mouv_stack_a(infa, infb);
	best_mouv(infb, &mouv);
	ft_printf("--------best_mouv-----");
	ft_printf("best_mouv_index = %d\n", mouv.best_mouv_index);
}
