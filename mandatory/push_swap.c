/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:31:14 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/02/28 20:11:27 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	display(t_node *s_a)
{
	while (s_a != NULL)
	{
		printf("%d\n", s_a->data);
		s_a = s_a->next;
	}
}

static void	check_isdigit(t_data *data, char **av)
{
	while (av[data->i][data->j])
	{
		while (av[data->i][data->j] == '-')
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

static void	data_sa(t_node **s_a, int ac, char **av)
{
	t_data	data;

	data.i = 2;
	data.j = 0;
	data.head = *s_a;
	data.tail = *s_a;
	while (data.i < ac)
	{
		data.newnode = (t_node *)malloc(sizeof(t_node));
		if (!data.newnode)
			exit(1);
		check_isdigit(&data, av);
		data.j = 0;
		data.newnode->data = ft_atoi(av[data.i]);
		data.newnode->next = NULL;
		data.tail->next = data.newnode;
		data.newnode->prev = data.tail;
		data.tail = data.newnode;
		data.i++;
	}
}

int	main(int ac, char *av[])
{
	t_node	*s_a;
	int		j;
	int len = 0;

	j = 0;
	if (ac > 1)
	{
		s_a = NULL;
		s_a = (t_node *)malloc(sizeof(t_node));
		if (!s_a)
			exit(1);
		while (av[1][j] == '-')
			j++;
		while (ft_isdigit(av[1][j]) && av[1][j] != '\0')
			j++;
		if (ft_isdigit(av[1][j]) == 0 && av[1][j] != '\0')
		{
			write(1, "error!\n", 7);
			exit(1);
		}
		s_a->data = ft_atoi(av[1]);
		s_a->prev = NULL;
		s_a->next = NULL;
		data_sa(&s_a, ac, av);
		display(s_a);
		swap_a(&s_a);
		printf("\n");
		len_stack(&len, s_a);
		printf("-----%d-----\n", len);
		display(s_a);
	}
}
