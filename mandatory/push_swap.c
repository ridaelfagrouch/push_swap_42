/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:31:14 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/04 16:56:12 by rel-fagr         ###   ########.fr       */
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

static void	data_sa(t_node **s_a, int ac, char **av, t_inf_sa *infa)
{
	t_data	data;
	int		i;

	data.j = 2;
	i = 0;
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
		data.newnode->index = i + 1;
		if (data.newnode->data < infa->small)
		{
			infa->small = data.newnode->data;
			infa->small_index = data.newnode->index;
		}
		infa->tail->next = data.newnode;
		data.newnode->prev = infa->tail;
		infa->tail = data.newnode;
		data.j++;
		i++;
	}
}

/* ************************************************************************** */

static void	check_dup(t_inf_sa *infa)
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

void	initial_data(t_inf_sa *infa, t_inf_sb *infb, t_node **s_a, t_node **s_b)
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
}

/* ************************************************************************** */

// void	test(t_inf_sa infa, t_inf_sb infb)
// {
// 	display_a(infa);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	ft_printf("----------stack_a-------------\n");
// 	display_a(infa);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	ft_printf("----------a-------------\n");
// 	display_a(infa);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	ft_printf("----------a-------------\n");
// 	display_a(infa);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	ft_printf("----------a-------------\n");
// 	display_a(infa);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	ft_printf("----------a-------------\n");
// 	display_a(infa);
// 	ft_printf("----------a-------------\n");
// 	display_a(infa);
// 	ft_printf("----------a-------------\n");
// 	display_a(infa);
// 	ft_printf("----------a-------------\n");
// 	display_a(infa);
// 	ft_printf("----------a-------------\n");
// 	display_a(infa);
// 	ft_printf("----------a-------------\n");
// 	display_a(infa);
// 	ft_printf("----------a-------------\n");
// 	display_a(infa);
// 	sb(&infb);
// 	ft_printf("----------swap_b-------------\n");
// 	display_b(infb);
// 	ft_printf("----------stack_a-------------\n");
// 	display_a(infa);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	sb(&infb);
// 	ft_printf("----------swap_b-------------\n");
// 	display_b(infb);
// 	ss(&infa, &infb);
// 	ft_printf("----------ss-------------\n");
// 	display_a(infa);
// 	ft_printf("-ss-\n");
// 	display_b(infb);
// 	sa(&infa);
// 	ft_printf("----------swap_a-------------\n");
// 	display_a(infa);
// 	rra(&infa);
// 	ft_printf("----------rra-------------\n");
// 	display_a(infa);
// 	ra(&infa);
// 	ft_printf("----------ra-------------\n");
// 	display_a(infa);
// 	rb(&infb);
// 	ft_printf("----------rb-------------\n");
// 	display_b(infb);
// 	rrb(&infb);
// 	ft_printf("----------rrb-------------\n");
// 	display_b(infb);
// 	rrr(&infa, &infb);
// 	ft_printf("----------rrr-------------\n");
// 	display_a(infa);
// 	ft_printf("-rrr-\n");
// 	display_b(infb);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	pa(&infa, &infb);
// 	ft_printf("----------push_a-------------\n");
// 	display_a(infa);
// 	ft_printf("-b-\n");
// 	display_b(infb);
// 	ft_printf("-b-\n");
// 	display_b(infb);
// 	ft_printf("-b-\n");
// 	display_b(infb);
// 	ft_printf("-b-\n");
// 	display_b(infb);
// 	ft_printf("-b-\n");
// 	display_b(infb);
// 	ft_printf("-b-\n");
// 	display_b(infb);
// 	ft_printf("-b-\n");
// 	display_b(infb);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	rb(&infb);
// 	ft_printf("----------rb-------------\n");
// 	display_b(infb);
// 	rrb(&infb);
// 	ft_printf("----------rrb-------------\n");
// 	display_b(infb);
// 	rrr(&infa, &infb);
// 	ft_printf("----------rrr-------------\n");
// 	display_a(infa);
// 	ft_printf("-rrr-\n");
// 	display_b(infb);
// 	pb(&infa, &infb);
// 	ft_printf("----------push_b-------------\n");
// 	display_b(infb);
// 	rb(&infb);
// 	ft_printf("----------rb-------------\n");
// 	display_b(infb);
// 	rrb(&infb);
// 	ft_printf("----------rrb-------------\n");
// 	display_b(infb);
// 	rrb(&infb);
// 	ft_printf("----------rrb-------------\n");
// 	display_b(infb);
// }

/* ************************************************************************** */

int	main(int ac, char *av[])
{
	t_node		*s_a;
	t_node		*s_b;
	t_inf_sa	infa;
	t_inf_sb	infb;
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
		display_a(infa);
	}
	else
	{
		write(1, "error: bad arg number!\n", 23);
		exit(1);
	}
}
