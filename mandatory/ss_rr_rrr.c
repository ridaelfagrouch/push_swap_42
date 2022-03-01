/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_rr_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:43:43 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/01 12:13:56 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node **s_a, t_inf_sa *info1, t_node **s_b, t_inf_sb *info2)
{
	sa(s_a, info1);
	sb(s_b, info2);
}

void	rr(t_inf_sa *inf_a, t_inf_sb *inf_b)
{
	ra(inf_a);
	rb(inf_b);
}
