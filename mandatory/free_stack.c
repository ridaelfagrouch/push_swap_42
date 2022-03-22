/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:49:04 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/22 15:34:21 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	ft_free_a(t_infsa *infa)
{
	t_node	*root;
	t_node	*ptr;

	root = NULL;
	ptr = infa->head;
	if (!infa->head)
		infa->head = NULL;
	while (ptr != NULL)
	{
		root = ptr;
		ptr = ptr->next;
		free(root);
	}
	infa->head = NULL;
}

/* ************************************************************************** */

void	ft_free_b(t_infsb *infb)
{
	t_node	*root;
	t_node	*ptr;

	root = NULL;
	ptr = infb->head;
	if (!infb->head)
		infb->head = NULL;
	while (ptr != NULL)
	{
		root = ptr;
		ptr = ptr->next;
		free(root);
	}
	infb->head = NULL;
}

/* ************************************************************************** */

void	free_split(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
