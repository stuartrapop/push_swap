/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:57 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/10 14:55:06 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

void	ft_radix_b3_push_0(t_num_list *lista, t_num_list *listb, int column)
{
	int	index;
	int	tot_elements;
	int	value;
	int	power;

	index = 0;
	tot_elements = lista->number_elements;
	while (index < tot_elements)
	{
		value = lista->position[0];
		power = 0;
		while (power < column)
		{
			value = value / 3;
			power++;
		}
		value = value % 3;
		if (value == 0)
			ft_push(lista, listb);
		else
			ft_rotate_elements(lista, 1);
		index++;
	}
}

void	ft_radix_b3_push_1(t_num_list *lista, t_num_list *listb, int column)
{
	int	index;
	int	tot_elements;
	int	value;
	int	power;

	index = 0;
	tot_elements = lista->number_elements;
	while (index < tot_elements)
	{
		value = lista->position[0];
		power = 0;
		while (power < column)
		{
			value = value / 3;
			power++;
		}
		value = value % 3;
		if (value == 1)
			ft_push(lista, listb);
		else
			ft_rotate_elements(lista, 1);
		index++;
	}
}

void	ft_radix_3(t_num_list *lista, t_num_list *listb)
{
	int	column;

	column = 0;
	while (1)
	{
		ft_radix_b3_push_0(lista, listb, column);
		ft_radix_b3_push_1(lista, listb, column);
		ft_merge(lista, listb);
		if (is_sorted_list(lista->position, lista->number_elements, 'a'))
			return ;
		column++;
	}
}
