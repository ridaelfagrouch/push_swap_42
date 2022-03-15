/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:31:14 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/15 14:56:38 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

static void	check_isdigit(t_data *data, char **av)
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

static void	data_sa(t_node **s_a, int ac, char **av, t_infsa *infa)
{
	t_data	data;

	data.j = 2;
	data.i = 0;
	infa->head = *s_a;
	infa->tail = *s_a;
	while (data.j < ac)
	{
		data.newnode = (t_node *)malloc(sizeof(t_node));
		if (!data.newnode)
			exit(1);
		check_isdigit(&data, av);
		data.newnode->data = ft_atoi(av[data.j]);
		data.newnode->next = NULL;
		data.newnode->index = data.i + 1;
		data.newnode->lenght = 1;
		data.newnode->sub_s = -1;
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

static void	check_dup(t_infsa *infa)
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
				write(1, "error: dup number!\n", 19);
				exit(1);
			}
			else
				data.tmp2 = data.tmp2->next;
		}
		data.tmp = data.tmp->next;
	}
}

/* ************************************************************************** */

static void	initial_data(t_infsa *infa, t_infsb *infb, t_node **s_a, t_node **s_b)
{
	infa->head = *s_a;
	infa->tail = *s_a;
	infb->head = *s_b;
	infb->tail = *s_b;
	infb->head->data = 0;
	infb->head->prev = NULL;
	infb->head->next = NULL;
	infb->len = 0;
	infa->head->prev = NULL;
	infa->head->next = NULL;
	infa->head->index = 0;
	infa->small_index = 0;
	infa->head->lenght = 1;
	infa->head->sub_s = -1;
	infa->head->best_mvb = 0;
}

/* ************************************************************************** */

int	main(int ac, char *av[])
{
	t_node		*s_a;
	t_node		*s_b;
	t_infsa		infa;
	t_infsb		infb;
	int			j;

	j = 0;
	if (ac > 1)
	{
		s_a = NULL;
		s_b = NULL;
		s_a = (t_node *)malloc(sizeof(t_node));
		if (!s_a)
			exit(1);
		s_b = (t_node *)malloc(sizeof(t_node));
		if (!s_b)
			exit(1);
		if (av[1][j] == '-')
			j++;
		while (ft_isdigit(av[1][j]) && av[1][j] != '\0')
			j++;
		if (ft_isdigit(av[1][j]) == 0 && av[1][j] != '\0')
		{
			write(1, "error!\n", 7);
			exit(1);
		}
		initial_data(&infa, &infb, &s_a, &s_b);
		infa.head->data = ft_atoi(av[1]);
		infa.small = infa.head->data;
		data_sa(&s_a, ac, av, &infa);
		len_stack_a(&infa);
		check_dup(&infa);
		sort(&infa, &infb);
		// ft_printf("----------stack_a----------\n");
		// display_a(infa);
		// ft_printf("----------stack_b----------\n");
		// display_b(infb);
	}
	else
	{
		write(1, "error: bad arg number!\n", 23);
		exit(1);
	}
	return (0);
}
