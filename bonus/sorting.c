/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:48:00 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/21 14:36:38 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_ptr(t_infsa *infa, t_infsb *infb, char *str)
{
	if (ft_strcmp(str, "ra") == 0)
		ra(infa);
	else if (ft_strcmp(str, "sa") == 0)
		sa(infa);
	else if (ft_strcmp(str, "pa") == 0)
		pa(infa, infb);
	else if (ft_strcmp(str, "rra") == 0)
		rra(infa);
	else if (ft_strcmp(str, "sb") == 0)
		sb(infb);
	else if (ft_strcmp(str, "pb") == 0)
		pb(infa, infb);
	else if (ft_strcmp(str, "rb") == 0)
		rb(infb);
	else if (ft_strcmp(str, "rrb") == 0)
		rrb(infb);
	else if (ft_strcmp(str, "rr") == 0)
		rr(infa, infb);
	else if (ft_strcmp(str, "ss") == 0)
		ss(infa, infb);
	else if (ft_strcmp(str, "rrr") == 0)
		rrr(infa, infb);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	check_sorting(t_infsa *infa, int *i)
{
	t_data	data;

	data.tmp = infa->head;
	data.tmp1 = infa->head->next;
	while (data.tmp1)
	{
		if (data.tmp1->data > data.tmp->data)
		{
			data.tmp1 = data.tmp1->next;
			data.tmp = data.tmp1->prev;
		}
		else
		{
			*i = -1;
			break ;
		}
	}
}

void	appl_sortint(t_infsa *infa, t_infsb *infb)
{
	char	*str;
	int		i;
	int		len;

	len = infa->len;
	str = ft_strtrim(get_next_line(0), "\n");
	while (str)
	{
		check_ptr(infa, infb, str);
		free(str);
		str = NULL;
		i = 0;
		check_sorting(infa, &i);
		str = ft_strtrim(get_next_line(0), "\n");
	}
	if (i == 0 && (infa->len == len))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_b(infb);
}
