/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:57 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/10 16:12:24 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

void	ft_radix_2(t_num_list *lista, t_num_list *listb)
{
	int	index;
	int	tot_elements;
	int	column;
	int	bit_shifted;

	column = 0 ;
	tot_elements = lista->number_elements;
	while (1)
	{
		index = 0;
		while (index < tot_elements)
		{
			bit_shifted = lista->position[0];
			bit_shifted = bit_shifted >> column & 1;
			if (!(bit_shifted))
				ft_push(lista, listb);
			else
				ft_rotate_elements(lista, 1);
			index++;
		}
		ft_merge(lista, listb);
		if (is_sorted_list(lista->position, lista->number_elements, 'a'))
			return ;
		column++;
	}
}

void	ft_sort_few(t_num_list *lista, t_num_list *listb)
{
	int	tot_elements;
	{
		tot_elements = lista->number_elements;
		if (tot_elements <= 3)
		{
			ft_sort_less_3(lista);
			return ;
		}
		while (!ft_none_left(*lista, 0, tot_elements / 2))
		{
			if (lista->position[0] <= tot_elements / 2)
				ft_push(lista, listb);
			else
				ft_rotate_elements(lista, 1);
		}
		ft_sort_less_3(lista);
		ft_sort_less_3(listb);
		ft_merge(lista, listb);
	}
}

void	ft_sort_less_3(t_num_list *list)
{
	if (list->identifier == 'a')
	{
		if (list->position[0] == list->max_value)
			ft_rotate_elements(list, 1);
		if (is_sorted_list(list->position, list->number_elements, 'a'))
			return ;
		if (list->position[1] == list->max_value)
			ft_reverse_rotate_elements(list, 1);
		if (is_sorted_list(list->position, list->number_elements, 'a'))
			return ;
		ft_swap_first_2(list, 1);
		return ;
	}
	if (list->position[0] == list->min_value)
		ft_rotate_elements(list, 1);
	if (is_sorted_list(list->position, list->number_elements, 'd'))
		return ;
	if (list->position[1] == list->min_value)
		ft_reverse_rotate_elements(list, 1);
	if (is_sorted_list(list->position, list->number_elements, 'd'))
		return ;
	ft_swap_first_2(list, 1);
}

void	ft_swap_first_2(t_num_list *list, int show_instruction)
{
	int	tmp;

	if (list == NULL)
		return ;
	if (list->number_elements < 2)
		return ;
	tmp = list->position[0];
	list->position[0] = list->position[1];
	list->position[1] = tmp;
	if (show_instruction)
		ft_printf("s%c\n", list->identifier);
}
