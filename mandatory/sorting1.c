/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:51:13 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/05 18:21:23 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	start_sorting(t_inf_sa *infa, t_inf_sb *infb, int *tab)
{
	int		len;
	int		i;
	t_data	data;

	len = 0;
	while (tab[len] != 0)
		len++;
	i = len;
	data.tmp = infa->head;
	while (i >= 0)
	{
		while (data.tmp->index == tab[i])
		{
			ra(infa);
			data.tmp = infa->head;
			i--;
		}
		if (data.tmp->index != 0)
		{
			pb(infa, infb);
			data.tmp = infa->head;
		}
	}
}
