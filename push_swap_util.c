/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 09:02:58 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/09 20:20:52 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include "push_swap.h"
#include <limits.h>

void	ft_print_list(int *list, int length)
{
	int	index;

	index = 0;
	while (index < length)
	{
		ft_printf("number %d\n", list[index]);
		index++;
	}
}

int	valid_argument(char *string, int *ret)
{
	long	number;
	int		sign;
	int		string_length;

	number = 0;
	sign = 1;
	string_length = ft_strlen(string);

	if ((*string == '-' || *string == '+') && string_length != 1)
	{
		if (*string == '-')
			sign = -1;
		string++;
	}
	while (*string != '\0')
	{
		if (!ft_isdigit(*string))
			return (0);
		number = number * 10 + *string - '0';
		string++;
	}
	number = number * sign;
	if (number < INT_MIN || number > INT_MAX)
		return (0);
	*ret = (int)number;
	return (1);
}

int	is_sorted_list(int *list, int number_elements, char direction)
{
	int	index;
	int	sorted;

	index = 0;
	sorted = 1;
	while (index < number_elements - 1)
	{
		if (direction == 'a')
		{
			if (list[index] > list[index + 1])
				sorted = 0;
		}
		else
		{
			if (list[index] < list[index + 1])
				sorted = 0;
		}
		index++;
	}
	return (sorted);
}

int	valid_arguments(int argc, char *argv[])
{
	int	index;
	int	index2;
	int	number;

	index = 1;
	while (index < argc)
	{
		if (!valid_argument(argv[index], &number))
			return (0);
		index++;
	}
	index = 1;
	while (index < argc - 1)
	{
		index2 = index + 1;
		while (index2 < argc)
		{
			if (ft_atoi(argv[index]) == ft_atoi(argv[index2]))
				return (0);
			index2++;
		}
		index++;
	}
	return (1);
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

void	ft_compare_swap_both (t_num_list *lista, t_num_list *listb)
{
	int	swap_a;
	int	swap_b;

	swap_a = 0;
	swap_b = 0;

	if (lista->position[0] > lista->position[1])
	{
		ft_swap_first_2(lista, 0);
		swap_a = 1;
	}
	if (listb->position[0] < listb->position[1])
	{
		ft_swap_first_2(listb, 0);
		swap_b = 1;
	}
	if (swap_a == 1 && swap_b == 1)
	{
		ft_printf("ss\n");
		return ;
	}
	if (swap_a == 1)
	{
		ft_printf("sa\n");
	}
	if (swap_b == 1)
	{
		ft_printf("sb\n" );
		return ;
	}
}

void	ft_reposition(t_num_list *lista, t_num_list *listb)
{

	while (lista->position[0] != lista->min_value && listb->position[0] \
		!= listb->max_value)
		ft_rotate_both(lista, listb);
	while (lista->position[0] != lista->min_value)
		ft_rotate_elements(lista, 1);
	while (listb->position[0] != listb->max_value)
		ft_rotate_elements(listb, 1);
}
