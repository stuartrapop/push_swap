/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:57 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/10 14:19:49 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

void	ft_radix_b4_push_0(t_num_list *lista, t_num_list *listb, int column)
{
	int	index;
	int	tot_elements;
	int	bit_shifted;

	index = 0;
	tot_elements = lista->number_elements;
	while (index < tot_elements)
	{
		bit_shifted = lista->position[0];
		bit_shifted = bit_shifted >> (column * 2);
		bit_shifted = (bit_shifted & 1 << 1 || \
									bit_shifted & 1);
		if (!(bit_shifted))
			ft_push(lista, listb);
		else
			ft_rotate_elements(lista, 1);
		index++;
	}
}

void	ft_radix_b4_push_1(t_num_list *lista, t_num_list *listb, int column)
{
	int	index;
	int	tot_elements;
	int	bit_shifted;

	index = 0;
	tot_elements = lista->number_elements;
	while (index < tot_elements)
	{
		bit_shifted = lista->position[0];
		bit_shifted = bit_shifted >> (column * 2);
		bit_shifted = (!(bit_shifted & 1 << 1) && bit_shifted & 1);
		if ((bit_shifted))
			ft_push(lista, listb);
		else
			ft_rotate_elements(lista, 1);
		index++;
	}
}

void	ft_radix_b4_push_2(t_num_list *lista, t_num_list *listb, int column)
{
	int	index;
	int	tot_elements;
	int	bit_shifted;

	index = 0;
	tot_elements = lista->number_elements;
	while (index < tot_elements)
	{
		bit_shifted = lista->position[0];
		bit_shifted = bit_shifted >> (column * 2);
		bit_shifted = ((bit_shifted & 1 << 1) && !(bit_shifted & 1));
		if ((bit_shifted))
			ft_push(lista, listb);
		else
			ft_rotate_elements(lista, 1);
		index++;
	}
}

void	ft_radix_4(t_num_list *lista, t_num_list *listb)
{
	int	column;

	column = 0;
	while (1)
	{
		ft_radix_b4_push_0(lista, listb, column);
		ft_radix_b4_push_1(lista, listb, column);
		ft_radix_b4_push_2(lista, listb, column);
		ft_merge(lista, listb);
		if (is_sorted_list(lista->position, lista->number_elements, 'a'))
			return ;
		column++;
	}
}
