/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:34:47 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/21 21:21:11 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	empty_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(ft_strtrim(av[i], " ")) == 0)
		{
			write(2, "error: empty arg!\n", 18);
			exit(1);
		}
		i++;
	}
}

/* ************************************************************************** */

void	check_dup(t_infsa *infa, t_infsb *infb)
{
	t_data	data;

	data.tmp = infa->head;
	while (data.tmp)
	{
		data.tmp2 = data.tmp->next;
		while (data.tmp2)
		{
			if (data.tmp->data == data.tmp2->data)
			{
				ft_free_a(infa);
				ft_free_b(infb);
				write(2, "error: dup number!\n", 19);
				exit(1);
			}
			else
				data.tmp2 = data.tmp2->next;
		}
		data.tmp = data.tmp->next;
	}
}
