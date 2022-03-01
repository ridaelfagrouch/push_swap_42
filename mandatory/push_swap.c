/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:31:14 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/01 17:21:55 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

static void	display_a(t_inf_sa infa)
{
	while (infa.head != NULL)
	{
		ft_printf("%d\n", infa.head->data);
		infa.head = infa.head->next;
	}
}

static void	display_b(t_inf_sb infb)
{
	while (infb.head != NULL)
	{
		ft_printf("%d\n", infb.head->data);
		infb.head = infb.head->next;
	}
}

/* ************************************************************************** */

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

/* ************************************************************************** */

static void	data_sa(t_node **s_a, int ac, char **av, t_inf_sa *infa)
{
	t_data	data;

	data.i = ac - 2;
	data.j = 0;
	infa->head = *s_a;
	infa->tail = *s_a;
	while (data.i > 0)
	{
		data.newnode = (t_node *)malloc(sizeof(t_node));
		if (!data.newnode)
			exit(1);
		check_isdigit(&data, av);
		data.j = 0;
		data.newnode->data = ft_atoi(av[data.i]);
		data.newnode->next = NULL;
		infa->tail->next = data.newnode;
		data.newnode->prev = infa->tail;
		infa->tail = data.newnode;
		data.i--;
	}
}

/* ************************************************************************** */

void	check_dup(t_inf_sa *infa)
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

int	main(int ac, char *av[])
{
	t_node		*s_a;
	t_node		*s_b;
	t_inf_sa	infa;
	t_inf_sb	infb;
	int			j;

	j = 0;
	infb.len = 0;
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
		if (av[ac - 1][j] == '-')
			j++;
		while (ft_isdigit(av[ac - 1][j]) && av[ac - 1][j] != '\0')
			j++;
		if (ft_isdigit(av[ac - 1][j]) == 0 && av[ac - 1][j] != '\0')
		{
			write(1, "error!\n", 7);
			exit(1);
		}
		s_b->data = 0;
		s_b->prev = NULL;
		s_b->next = NULL;
		infb.head = s_b;
		infb.tail = s_b;
		infb.len = -1;
		s_a->data = ft_atoi(av[ac - 1]);
		s_a->prev = NULL;
		s_a->next = NULL;
		infa.head = s_a;
		data_sa(&s_a, ac, av, &infa);
		len_stack_a(&infa);
		check_dup(&infa);
		display_a(infa);
		//**************************************test
		pb(&infa, &infb);
		ft_printf("----------push_b-------------\n");
		display_b(infb);
		ft_printf("----------stack_a-------------\n");
		display_a(infa);
		pb(&infa, &infb);
		ft_printf("----------push_b-------------\n");
		display_b(infb);
		sb(&infb);
		ft_printf("----------swap_b-------------\n");
		display_b(infb);
		ft_printf("----------stack_a-------------\n");
		display_a(infa);
		pa(&infa, &infb);
		ft_printf("----------push_a-------------\n");
		display_a(infa);
		sb(&infb);
		ft_printf("----------swap_b-------------\n");
		display_b(infb);
		ss(&infa, &infb);
		ft_printf("----------ss-------------\n");
		display_a(infa);
		ft_printf("-ss-\n");
		display_b(infb);
		sa(&infa);
		ft_printf("----------swap_a-------------\n");
		display_a(infa);
		rra(&infa);
		ft_printf("----------rra-------------\n");
		display_a(infa);
		ra(&infa);
		ft_printf("----------ra-------------\n");
		display_a(infa);
		rb(&infb);
		ft_printf("----------rb-------------\n");
		display_b(infb);
		rrb(&infb);
		ft_printf("----------rrb-------------\n");
		display_b(infb);
		rrr(&infa, &infb);
		ft_printf("----------rrr-------------\n");
		display_a(infa);
		ft_printf("-rrr-\n");
		display_b(infb);
	}
}
