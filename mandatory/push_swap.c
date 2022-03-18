/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:31:14 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/18 20:14:24 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

static void	initial_data(t_infsa *infa, t_infsb *infb)
{
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

static void	first_node(t_infsa *infa, t_infsb *infb, char **av)
{
	t_node	*s_a;
	t_node	*s_b;
	int		j;

	j = 0;
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
	infa->head = s_a;
	infa->tail = s_a;
	infb->head = s_b;
	infb->tail = s_b;
}

/* ************************************************************************** */

int	main(int ac, char *av[])
{
	t_infsa		infa;
	t_infsb		infb;

	if (ac > 1)
	{
		empty_arg(ac, av);
		first_node(&infa, &infb, av);
		initial_data(&infa, &infb);
		infa.head->data = ft_atoi(av[1]);
		infa.small = infa.head->data;
		data_sa(ac, av, &infa);
		len_stack_a(&infa);
		check_dup(&infa, &infb);
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
