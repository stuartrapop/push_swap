/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:57 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/03 16:21:56 by srapopor         ###   ########.fr       */
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
			sorted = ft_compare_swap(lst, lst_name);
			rotate_list(lst, lst_name);
			index++;
		}
		rotate_list(lst, lst_name);
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
	ft_printf("list a \n");
	ft_print_list(*lsta);
	ft_printf("list b before sort \n");
	ft_print_list(*lstb);
	ft_bubble_sort(lstb, "b");
	ft_printf("list b after sort \n");
	ft_print_list(*lstb);
	ft_merge_lists(lsta, lstb);
	ft_print_list(*lsta);
	ft_delete_lst(lsta);
	ft_delete_lst(lstb);
	return (1);
}
