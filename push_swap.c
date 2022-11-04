/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:57 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/04 18:19:05 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

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
/* check valid integers and non duplicates
*/

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

void	ft_simple_sort(int *list, int length)
{
	int	index1;
	int	index2;
	int	tmp;

	index1 = 0;
	index2 = 0;
	while (index1 < length - 1)
	{
		index2 = index1 + 1;
		while (index2 < length)
		{
			if (list[index1] < list[index2])
			{
				tmp = list[index1];
				list[index1] = list[index2];
				list[index2] = tmp;
			}
			index2++;
		}
		index1++;
	}
}

void	ft_get_list_stats(t_num_list list)
{
	int	min;
	int	max;
	int	index;

	if (list.number_elements == 0 || list.elements == NULL)
		return ;
	index = 0;
	min = list.elements[0];
	max = list.elements[0];
	while (index < list.number_elements)
	{
		if (min > list.elements[index])
			min = list.elements[index];
		if (max < list.elements[index])
			max = list.elements[index];
		index++;
	}
	ft_simple_sort(list.sorted_elements, list.number_elements);
	list.median = (list.sorted_elements[list.number_elements / 2 + 1]);
}

int	ft_read_elements(t_num_list *lista, int argc, char *argv[], char identifier)
{
	int	index;

	(*lista).elements = malloc(sizeof(int) * argc);
	if (!((*lista).elements))
		return (0);
	(*lista).sorted_elements = malloc(sizeof(int) * argc);
	if (!((*lista).sorted_elements))
		return (0);
	(*lista).identifier = identifier;
	(*lista).number_elements = argc -1;
	index = argc ;
	while (index > 1)
	{
		ft_printf("in function%d \n", index);

		(*lista).elements[index - 2] = ft_atoi(argv[index - 1]);
		(*lista).sorted_elements[index - 2] = ft_atoi(argv[index - 1]);
		ft_printf("value %d:\n", (*lista).elements[index - 1]);
		index--;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_num_list	lista;

	if (argc < 2)
		return (0);
	if (!valid_arguments(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	lista.elements = NULL;
	
	ft_read_elements(&lista, argc, argv, 'a');
	ft_print_list(lista.elements, lista.number_elements);
	ft_get_list_stats(lista);
}
