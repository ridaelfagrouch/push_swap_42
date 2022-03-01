/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:31:14 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/01 12:12:56 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	display(t_inf_sa info)
{
	while (info.head != NULL)
	{
		printf("%d\n", info.head->data);
		info.head = info.head->next;
	}
}

static void	check_isdigit(t_data *data, char **av)
{
	while (av[data->i][data->j])
	{
		if (av[data->i][data->j] == '-')
			data->j++;
		if (ft_isdigit(av[data->i][data->j]) && av[data->i][data->j] != '\0')
			data->j++;
		if (ft_isdigit(av[data->i][data->j]) == 0 && \
			av[data->i][data->j] != '\0')
		{
			write(2, "error!\n", 7);
			exit(1);
		}
	}
}

static void	data_sa(t_node **s_a, int ac, char **av, t_inf_sa *info)
{
	t_data	data;

	data.i = ac - 2;
	data.j = 0;
	info->head = *s_a;
	info->tail = *s_a;
	while (data.i > 0)
	{
		data.newnode = (t_node *)malloc(sizeof(t_node));
		if (!data.newnode)
			exit(1);
		check_isdigit(&data, av);
		data.j = 0;
		data.newnode->data = ft_atoi(av[data.i]);
		data.newnode->next = NULL;
		info->tail->next = data.newnode;
		data.newnode->prev = info->tail;
		info->tail = data.newnode;
		data.i--;
	}
}

int	main(int ac, char *av[])
{
	t_node		*s_a;
	t_inf_sa	info;
	int			j;

	j = 0;
	if (ac > 1)
	{
		s_a = NULL;
		s_a = (t_node *)malloc(sizeof(t_node));
		if (!s_a)
			exit(1);
		if (av[ac - 1][j] == '-')
			j++;
		while (ft_isdigit(av[ac - 1][j]) && av[ac - 1][j] != '\0')
			j++;
		if (ft_isdigit(av[ac - 1][j]) == 0 && av[ac - 1][j] != '\0')
		{
			write(1, "error!\n", 7);
			exit(1);
		}
		s_a->data = ft_atoi(av[ac - 1]);
		s_a->prev = NULL;
		s_a->next = NULL;
		info.head = s_a;
		data_sa(&s_a, ac, av, &info);
		display(info);
		// printf("-------------------------\n");
		// ra(&info);
		// display(info);
	}
}
