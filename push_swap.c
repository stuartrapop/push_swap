/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:57 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/02 08:24:01 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include <limits.h>

t_list	*ft_create_element(int number)
{
	t_list	*new_element;
	// int		*new_value;
	printf("%d", number);

	new_element = malloc(sizeof(t_list));
	// new_value = malloc(sizeof(int *));
	// *new_value = number;
	new_element->content = NULL;
	new_element->next = NULL;
	return (new_element);
}

int	ft_compare(int *v1, int *v2)
{
	if (*v1 < *v2)
		return (-1);
	if (*v1 > *v2)
		return (1);
	return (0);
}

void	ft_print_list(t_list *lst)
{
	int	*number;

	while (lst != NULL)
	{
		number = (int *)(lst)->content;
		printf("number %d\n", *number);
		(lst) = (lst)->next;
	}
}

int	ft_bubble_sort(t_list **lst)
{
	int		start_number;
	int		sorted;
	int		*v1;
	int		*v2;
	int		end_loop;

	if (*lst == NULL || (*lst)->next == NULL)
		return (1);
	sorted = 0;
	while (sorted == 0)
	{
		v1 = (int *)(*lst)->content;
		v2 = (int *)(*lst)->next->content;
		printf("v1: %d, v2 %d\n", *v1, *v2);
		sorted = 1;
		if (*v1 > *v2)
		{
			sorted = 0;
			swap_first_two(lst);
		}
		start_number = *(int *)(*lst)->content;
		rotate_list(lst);
		ft_print_list(*lst);
		end_loop = 0;
		while (!end_loop)
		{
			v1 = (int *)(*lst)->content;
			v2 = (int *)(*lst)->next->content;
			printf("v1: %d, v2 %d\n", *v1, *v2);
			if (*(int *)((*lst)->content) == start_number)
			{
				end_loop = 1;
				break ;
				printf("end loop %d\n", start_number);
			}
			if (*v1 > *v2)
			{
				sorted = 0;
				swap_first_two(lst);
			}
			printf("list address before rotate %p\n", *lst);
			printf("first element before rotate %d\n", *(int *)(*lst)->content);
			rotate_list(lst);
			printf("list address after rotate %p\n", *lst);
			printf("first element after rotate %d\n", *(int *)(*lst)->content);
			printf("start nznber %d\n", start_number);
		}
	}	
	return (1);
}



int	main(int argc, char *argv[])
{
	int		index;
	t_list	**lst;
	t_list	*new_element;
	int		*number;

	index = 1;
	lst = malloc(sizeof(t_list *));
	*lst = NULL;
	if (argc < 2)
		return (0);
	while (index < argc)
	{
		number = malloc(sizeof(int));
		(*number) = ft_atoi(argv[index]);
		new_element = ft_lstnew(number);
		ft_lstadd_back(lst, new_element);
		index++;
	}
	ft_bubble_sort(lst);
	// ft_print_list(*lst);
	return (1);
}
