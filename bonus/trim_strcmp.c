/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Trim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:46:25 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/19 18:49:19 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//**********************ft_strtrim******************************

int	ft_setcheck(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	i = 0;
	start = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && ft_setcheck(s1[start], set))
		start++;
	while (end > start && ft_setcheck(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		exit(1);
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

//**********************ft_strcmp******************************

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
