/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:47:39 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/19 20:20:13 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* ************************************************************************** */

void	check_isdigit(t_data *data, char **av)
{
	int	i;

	i = 0;
	while (av[data->j][i])
	{
		if (av[data->j][i] == '-' || av[data->j][i] == '+')
			i++;
		if (ft_isdigit(av[data->j][i]) && av[data->j][i] != '\0')
			i++;
		if (ft_isdigit(av[data->j][i]) == 0 && \
			av[data->j][i] != '\0')
		{
			write(2, "error!\n", 7);
			exit(1);
		}
	}
}

/* ************************************************************************** */

void	newnode_data(char **av, t_data *data)
{
	data->newnode->data = ft_atoi(av[data->j]);
	data->newnode->next = NULL;
	data->newnode->index = data->i + 1;
	data->newnode->lenght = 1;
	data->newnode->sub_s = -1;
}

/* ************************************************************************** */

static int	av_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* ************************************************************************** */

void	data_sa(char **av, t_infsa *infa)
{
	t_data	data;
	int		len;

	data.j = 1;
	data.i = 0;
	len = av_len(av);
	while (data.j < len)
	{
		data.newnode = (t_node *)malloc(sizeof(t_node));
		if (!data.newnode)
			exit(1);
		check_isdigit(&data, av);
		newnode_data(av, &data);
		if (data.newnode->data < infa->small)
		{
			infa->small = data.newnode->data;
			infa->small_index = data.newnode->index;
		}
		infa->tail->next = data.newnode;
		data.newnode->prev = infa->tail;
		infa->tail = data.newnode;
		data.j++;
		data.i++;
	}
}
