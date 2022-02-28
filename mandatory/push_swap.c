/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:31:14 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/02/28 16:47:07 by rel-fagr         ###   ########.fr       */
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

static void	data_sa(t_node **s_a, int ac, char **av)
{
	int		i;
	int		j;
	t_node	*newnode;
	t_node	*head, *tail;

	i = 2;
	j = 0;
	head = *s_a;
	tail = *s_a;
	while (i < ac)
	{
		newnode = (t_node *)malloc(sizeof(t_node));
		if (!newnode)
			exit(1);
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) && av[i][j] != '\0')
				j++;
			if (ft_isdigit(av[i][j]) == 0 && av[i][j] != '\0')
			{
				write(2, "error!\n", 7);
				exit(1);
			}
		}
		j = 0;
		newnode->data = ft_atoi(av[i]);
		newnode->next = NULL;
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_node	*s_a;
	int		j;

	j = 0;
	if (ac > 1)
	{
		s_a = NULL;
		s_a = (t_node *)malloc(sizeof(t_node));
		if (!s_a)
			exit(1);
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
	}
}
