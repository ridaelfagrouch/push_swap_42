/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:00:49 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/19 16:29:41 by rel-fagr         ###   ########.fr       */
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

static int	len_str(const char *str)
{
	int	len;

	len = 0;
	if (ft_strlen(str) == 1 && (str[0] == '-' || str[0] == '+'))
	{
		write(1, "error: invalid arg!!\n", 21);
		exit (1);
	}
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (*str == '0')
		str++;
	while (str[len])
		len++;
	if (len > 10)
		return (1);
	else
		return (0);
}

static void	error_(int sign, long int k, const char *str)
{
	if ((sign * k) > 2147483647 || (sign * k) < -2147483648)
	{
		write(1, "error: invalid arg!!\n", 21);
		exit (1);
	}
	if (len_str(str))
	{
		write(1, "error: invalid nember!!\n", 24);
		exit (1);
	}
}

int	ft_atoi(const char *str)
{
	char		*src;
	int			sign;
	long int	k;
	long int	i;

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
	error_(sign, k, str);
	return (sign * k);
}
