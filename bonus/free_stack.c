/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:49:04 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/19 19:03:36 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
