/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:57 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/03 18:50:27 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

void	ft_merge_lists(t_node **lsta, t_node **lstb)
{
	int	position;
	int	lsta_length;
	int	lstb_length;
	int	end_rotate;

	end_rotate = 0;
	position = 0;
	lsta_length = ft_count_elements(*lsta);
	lstb_length = ft_count_elements(*lstb);
	while (*lstb != NULL)
	{
		if ((*lsta)->content < (*lstb)->content && position <= lsta_length + 1)
		{
			rotate_list(lsta, "a");
			position++;
		}
		else
		{
			ft_add_front(lsta, ft_remove_and_return_first(lstb));
			rotate_list(lsta, "a");
			ft_printf("pa\n");
		}
	}
	while (position < lsta_length)
	{
		rotate_list(lsta, "a");
		position++;
	}
}

int	ft_bubble_sort(t_node **lst, char *lst_name)
{
	int		index;
	int		list_length;
	int		sorted;

	if (*lst == NULL || (*lst)->next == NULL)
		return (0);
	list_length = ft_count_elements(*lst);
	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		index = 0;
		while (index < (list_length - 1))
		{
			if (ft_compare_swap_rotate(lst, lst_name))
				sorted = 0;
			index++;
		}
		rotate_list(lst, lst_name);
	}
	return (1);
}

int	valid_argument(char *string, int *ret)
{
	int		index;
	long	number;
	int		sign;

	index = 0;
	number = 0;
	sign = 1;

	if (string[index] == '-' || string[index] == '+')
	{
		if (string[index] == '-')
			sign = -1;
		index++;
	}
	while (string[index] != '\0')
	{
		if (!ft_isdigit(string[index]))
			return (0);
		number = number * 10 + string[index] - '0';
		index++;
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
	index = 0;
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

int	main(int argc, char *argv[])
{
	int		index;
	t_node	**lsta;
	t_node	**lstb;
	t_node	*new_element;
	int		number_elements;

	index = 1;
	lsta = malloc(sizeof(t_node *));
	if (!lsta)
		return (0);
	*lsta = NULL;
	lstb = malloc(sizeof(t_node *));
	if (!lstb)
		return (0);
	*lstb = NULL;
	if (argc < 2)
		return (0);
	if (!valid_arguments(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	while (index < argc)
	{
		new_element = ft_create_node(ft_atoi(argv[index]));
		ft_add_back(lsta, new_element);
		index++;
	}
	number_elements = ft_count_elements(*lsta);

	index = 0;
	while (index < number_elements / 2)
	{
		ft_add_front(lstb, ft_remove_and_return_first(lsta));
		ft_printf("pb\n");
		index++;
	}
	ft_bubble_sort(lsta, "a");
	ft_bubble_sort(lstb, "b");
	ft_merge_lists(lsta, lstb);
	ft_print_list(*lsta);
	ft_delete_lst(lsta);
	ft_delete_lst(lstb);
	return (1);
}
