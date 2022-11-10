/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:57 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/10 14:53:59 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

void	ft_make_sort_list(t_num_list *lista)
{
	int	index1;
	int	index2;
	int	tmp;

	if ((*lista).number_elements == 0)
		return ;
	index1 = 0;
	while (index1 < lista->number_elements - 1)
	{
		index2 = index1 + 1;
		while (index2 < lista->number_elements)
		{
			if (lista->sort_lst[index1] > lista->sort_lst[index2])
			{
				tmp = lista->sort_lst[index1];
				lista->sort_lst[index1] = lista->sort_lst[index2];
				lista->sort_lst[index2] = tmp;
			}
			index2++;
		}
		index1++;
	}
}

void	ft_make_position_list(t_num_list *lista, t_num_list *listb)
{
	int	index1;
	int	index2;

	if ((*lista).number_elements == 0 || (*lista).sort_lst == NULL)
		return ;
	lista->position = malloc(sizeof(int) * lista->number_elements);
	if (lista->position == NULL)
		return ;
	listb->position = malloc(sizeof(int) * lista->number_elements);
	if (listb->position == NULL)
		return ;
	index1 = 0;
	while (index1 < lista->number_elements)
	{
		index2 = 0;
		while (index2 < lista->number_elements)
		{
			if (lista->elements[index1] == lista->sort_lst[index2])
			{
				lista->position[index1] = index2 + 1;
			}
			index2++;
		}
		index1++;
	}
}

void	ft_get_list_stats(t_num_list *list)
{
	int	min;
	int	max;
	int	index;

	if ((*list).number_elements == 0 || (*list).elements == NULL)
		return ;
	index = 0;
	min = (*list).position[0];
	max = (*list).position[0];
	while (index < (*list).number_elements)
	{
		if (min > (*list).position[index])
			min = (*list).position[index];
		if (max < (*list).position[index])
			max = (*list).position[index];
		index++;
	}
	(*list).max_value = max;
	(*list).min_value = min;
}

void	ft_compare_swap(t_num_list *list, char direction, int show_instruction)
{
	if (direction == 'a')
	{
		if (list->elements[0] > list->elements[1])
			ft_swap_first_2(list, show_instruction);
		return ;
	}
	if (list->elements[0] < list->elements[1])
		ft_swap_first_2(list, show_instruction);
}

void	ft_merge(t_num_list *lista, t_num_list *listb)
{
	while (listb->number_elements != 0)
		ft_push(listb, lista);
}
