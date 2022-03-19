/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:48:00 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/19 20:17:01 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "checker.h"

void	check_ptr(t_infsa *infa, t_infsb *infb, char *ptr)
{
	if (ft_strcmp(ptr, "ra") == 0)
		ra(infa);
	else if (ft_strcmp(ptr, "sa") == 0)
		sa(infa);
	else if (ft_strcmp(ptr, "pa") == 0)
		pa(infa, infb);
	else if (ft_strcmp(ptr, "rra") == 0)
		rra(infa);
	else if (ft_strcmp(ptr, "sb") == 0)
		sb(infb);
	else if (ft_strcmp(ptr, "pb") == 0)
		pb(infa, infb);
	else if (ft_strcmp(ptr, "rb") == 0)
		rb(infb);
	else if (ft_strcmp(ptr, "rrb") == 0)
		rrb(infb);
	else if (ft_strcmp(ptr, "rr") == 0)
		rr(infa, infb);
	else if (ft_strcmp(ptr, "ss") == 0)
		ss(infa, infb);
	else if (ft_strcmp(ptr, "rrr") == 0)
		rrr(infa, infb);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	appl_sortint(t_infsa *infa, t_infsb *infb)
{
	char	*ptr;

	while (1)
	{
		ptr = ft_strtrim(get_next_line(0), "\n");
		check_ptr(infa, infb, ptr);
		free(ptr);
	}
}
