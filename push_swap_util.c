/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 09:02:58 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/05 20:02:24 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include "push_swap.h"
#include <limits.h>

void	ft_print_list(t_num_list list)
{
	int	index;

	index = 0;
	while (index < list.number_elements)
	{
		ft_printf("number %d\n", list.elements[index]);
		index++;
	}
	ft_printf("max value:  %d\n", list.max_value);
	ft_printf("min value:  %d\n", list.min_value);
	ft_printf("number of elements %d\n", list.number_elements);
}

int	valid_argument(char *string, int *ret)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	if (*string == '-' || *string == '+')
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

int	is_sorted_list(int *list, int number_elements)
{
	int	index;
	int	sorted;

	index = 0;
	sorted = 1;
	while (index < number_elements - 1)
	{
		if (list[index] > list[index + 1])
			sorted = 0;
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

void	ft_simple_sort(int **list, int length)
{
	int	index1;
	int	index2;
	int	tmp;

	index1 = 0;
	while (index1 < length - 1)
	{
		index2 = index1 + 1;
		while (index2 < length)
		{
			if ((*list)[index1] > (*list)[index2])
			{
				tmp = (*list)[index1];
				(*list)[index1] = (*list)[index2];
				(*list)[index2] = tmp;
			}
			index2++;
		}
		index1++;
	}
}
