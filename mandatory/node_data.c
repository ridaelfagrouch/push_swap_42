/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:49:04 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/18 19:54:08 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	check_isdigit(t_data *data, char **av)
{
	data->i = 0;
	while (av[data->j][data->i])
	{
		if (av[data->j][data->i] == '-')
			data->i++;
		if (ft_isdigit(av[data->j][data->i]) && av[data->j][data->i] != '\0')
			data->i++;
		if (ft_isdigit(av[data->j][data->i]) == 0 && \
			av[data->j][data->i] != '\0')
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

void	data_sa(int ac, char **av, t_infsa *infa)
{
	t_data	data;

	data.j = 2;
	data.i = 0;
	while (data.j < ac)
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
				write(1, "error: dup number!\n", 19);
				exit(1);
			}
			else
				data.tmp2 = data.tmp2->next;
		}
		data.tmp = data.tmp->next;
	}
}
