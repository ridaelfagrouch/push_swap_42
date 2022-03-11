/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:43:27 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/03/11 21:03:45 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */

void	max_lenght(t_data *data, int *max_lenght)
{
	while (data->temp)
	{
		if (data->temp->lenght >= *max_lenght)
		{
			*max_lenght = data->temp->lenght;
			data->tmp1 = data->temp;
		}
		data->temp = data->temp->next;
	}
	data->temp = data->tmp1;
}

/* ************************************************************************** */

int	*stor_long_i_s(t_inf_sa infa, t_data *data, int *count)
{
	int	sub;
	int	i;
	int	*tab;

	i = 1;
	tab = (int *)malloc(*count * sizeof(int));
	if (!tab)
		exit(1);
	data->tmp1 = data->temp;
	tab[0] = data->tmp1->data;
	sub = data->tmp1->sub_s;
	while (data->tmp1 != infa.head)
	{
		data->tmp1 = data->tmp1->prev;
		if (data->tmp1->index == sub)
		{
			tab[i] = data->tmp1->data;
			sub = data->tmp1->sub_s;
			i++;
		}
	}
	i = 0;
	while(i < *count)
	{
		ft_printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
	return(tab);
}

/* ************************************************************************** */

void	native_infa(t_data *data, t_inf_sa *original, t_inf_sa *infa)
{
	data->tmp4->next = data->tmp3;
	data->tmp3->prev = data->tmp4;
	data->tmp2->next = NULL;
	data->tmp->prev = NULL;
	original->head = data->tmp;
	original->tail = data->tmp2;
	infa->head = original->head;
	infa->tail = original->tail;
}

/* ************************************************************************** */

void	best_mouv_l_i_s(t_inf_sa *infa, t_inf_sb *infb, int *tab)
{
	t_data	data;
	int		i;

	(void)infb;
	data.tmp = infa->head;
	i = 0;
	while (data.tmp)
	{
		if (data.tmp->index > (infa->len / 2))
			data.tmp->best_mouv_lis = infa->len - data.tmp->index;
		else
			data.tmp->best_mouv_lis = data.tmp->index;
		data.tmp = data.tmp->next;
	}
	while (i <= infa->l_i_sub_len - 1)
	{
		data.tmp1 = infa->head;
		while (data.tmp1)
		{
			if (data.tmp1->data == tab[i])
			{
				data.tmp1->best_mouv_lis = -1;
				break ;
			}
			data.tmp1 = data.tmp1->next;
		}
		i++;
	}
}

/* ************************************************************************** */

void	long_i_s(t_inf_sa *infa, t_inf_sb *infb, t_data *data, t_inf_sa *original)
{
	int		*tab;
	int		max_len;
	int		sub;
	int		count;

	count = 1;
	max_len = 1;
	tab = NULL;
	data->temp = infa->head;
	max_lenght(data, &max_len);
	sub = data->tmp1->sub_s;
	while (data->tmp1 != infa->head)
	{
		data->tmp1 = data->tmp1->prev;
		if (data->tmp1->index == sub)
		{
			count++;
			sub = data->tmp1->sub_s;
		}
	}
	infa->l_i_sub_len = count;
	tab = stor_long_i_s(*infa, data, &count);
	native_infa(data, original, infa);
	index_stack(infa, infb);
	best_mouv_l_i_s(infa, infb, tab);
}

/* ************************************************************************** */

void	long_i_s_index(t_inf_sa *infa)
{
	t_data	data;
	int		nember_befor;
	int		index_befor;

	data.tmp = infa->head;
	data.tmp2 = data.tmp->next;
	data.tmp->sub_s = -1;
	while (data.tmp2)
	{
		data.tmp = infa->head;
		while (data.tmp != data.tmp2 && data.tmp)
		{
			if (data.tmp->data < data.tmp2->data)
			{
				if (data.tmp->lenght + 1 > data.tmp2->lenght)
				{
					data.tmp2->lenght = data.tmp->lenght + 1;
					data.tmp2->sub_s = data.tmp->index;
					nember_befor = data.tmp->data;
					index_befor = data.tmp->index;
				}
				else if (data.tmp->lenght + 1 == data.tmp2->lenght)
				{
					if (data.tmp->data < nember_befor)
						data.tmp2->sub_s = data.tmp->index;
					else
						data.tmp2->sub_s = index_befor;
				}
			}
			data.tmp = data.tmp->next;
		}
		data.tmp2 = data.tmp2->next;
	}
}

/* ************************************************************************** */

void	sort(t_inf_sa *infa, t_inf_sb *infb)
{
	t_data		data;
	t_inf_sa	original;
	int			i;

	i = -1;
	original.head = infa->head;
	original.tail = infa->tail;
	data.tmp = infa->head;
	data.tmp2 = infa->tail;
	data.tmp3 = infa->head;
	while (data.tmp3->data != infa->small)
		data.tmp3 = data.tmp3->next;
	if (data.tmp3 != data.tmp)
	{
		data.tmp4 = data.tmp3->prev;
		data.tmp4->next = NULL;
		infa->head = data.tmp3;
		infa->head->prev = NULL;
		data.tmp2->next = data.tmp;
		data.tmp->prev = data.tmp2;
		infa->tail = data.tmp4;
		index_stack(infa, infb);
	}
	long_i_s_index(infa);
	long_i_s(infa, infb, &data, &original);
}
