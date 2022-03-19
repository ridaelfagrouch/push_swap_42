/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:31:14 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/19 18:58:17 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static void	first_node(t_infsa *infa, t_infsb *infb, char **str)
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
	if (str[1][j] == '-' || str[1][j] == '+')
		j++;
	while (ft_isdigit(str[1][j]) && str[1][j] != '\0')
		j++;
	if (ft_isdigit(str[1][j]) == 0 && str[1][j] != '\0')
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

static char	**join_arg(int ac, char **av)
{
	char	*str;
	char	*ptr;
	char	**split;
	int		i;

	i = 2;
	empty_arg(ac, av);
	str = ft_strdup(av[1]);
	while (i < ac)
	{
		ptr = str;
		str = ft_strjoin(str, " ");
		free(ptr);
		ptr = str;
		str = ft_strjoin(str, av[i]);
		free(ptr);
		i++;
	}
	split = ft_split(str, ' ');
	free(str);
	return (split);
}

/* ************************************************************************** */

int	main(int ac, char *av[])
{
	t_infsa		infa;
	t_infsb		infb;
	char		**str;

	if (ac > 1)
	{
		str = join_arg(ac, av);
		first_node(&infa, &infb, str);
		initial_data(&infa, &infb);
		infa.head->data = ft_atoi(str[0]);
		infa.small = infa.head->data;
		data_sa(str, &infa);
		check_dup(&infa, &infb);
		len_stack_a(&infa);
		//appl_sortint(&infa, &infb);
		// ft_printf("----------stack_a----------\n");
		// display_a(infa);
	}
	else
	{
		write(1, "error: bad arg number!\n", 23);
		exit(1);
	}
	return (0);
}
