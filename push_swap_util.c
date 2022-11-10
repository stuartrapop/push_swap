/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 09:02:58 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/10 16:33:59 by srapopor         ###   ########.fr       */
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

int	valid_argument(char *string)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	if (*string == '-' || *string == '+')
	{
		if (ft_strlen(string) == 1)
			return (0);
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

int	valid_arguments(int num, char *str_arr[])
{
	int	index;
	int	index2;

	index = 0;
	while (index < num)
	{
		if (!valid_argument(str_arr[index]))
			return (0);
		index++;
	}
	index = 0;
	while (index < num)
	{
		index2 = index + 1;
		while (index2 < num)
		{
			if (ft_atoi(str_arr[index]) == ft_atoi(str_arr[index2]))
				return (0);
			index2++;
		}
		index++;
	}
	return (1);
}
