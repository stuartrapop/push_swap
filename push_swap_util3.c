/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 09:02:58 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/04 13:13:16 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include "push_swap.h"
#include <stdlib.h>

t_node	*ft_create_node(int number)
{
	t_node	*new_element;

	new_element = malloc(sizeof(t_node));
	if (!new_element)
		return (NULL);
	new_element->content = number;
	new_element->first_element = 0;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

int	ft_count_elements(t_node *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count += 1;
	}
	return (count);
}

int	ft_max_value(t_node *lst)
{
	int	max_value;

	if (lst == NULL)
		return (-9999);
	max_value = lst->content;
	while (lst != NULL)
	{
		if (lst->content > max_value)
			max_value = lst->content;
		lst = lst->next;
	}
	return (max_value);
}

void	ft_print_list(t_node *lst)
{
	while (lst != NULL)
	{
		ft_printf("number %d\n", (lst)->content);
		(lst) = (lst)->next;
	}
}
