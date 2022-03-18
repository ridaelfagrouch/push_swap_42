/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:00:49 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/18 19:27:28 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	wite_space(const char *str, long int *i)
{
	*i = 0;
	while ((str[*i] == ' ') || (str[*i] == '\r')
		|| (str[*i] == '\n') || (str[*i] == '\t')
		|| (str[*i] == '\v') || (str[*i] == '\f'))
	{
		*i += 1;
	}
}

int	ft_atoi(const char *str)
{
	char			*src;
	long int		i;
	int				sign;
	long int		k;

	sign = 1;
	k = 0;
	src = (char *) str;
	wite_space(str, &i);
	if (src[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (src[i] == '+')
		i++;
	while (src[i] >= 48 && src[i] <= 57)
	{
		k = k * 10 + src[i] - '0';
		i++;
	}
	i = sign * k;
	if (i > 2147483647 || i < -2147483648)
		exit (1);
	return (sign * k);
}
