/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 09:02:58 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/03 17:22:19 by srapopor         ###   ########.fr       */
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
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

int	ft_count_elements(t_node *lst)
{
	int	count;

	count = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		count += 1;
	}
	return (count);
}


void	ft_print_list(t_node *lst)
{
	while (lst != NULL)
	{
		ft_printf("number %d\n", (lst)->content);
		(lst) = (lst)->next;
	}
}


int	ft_compare_swap_rotate(t_node **lst, char *lst_name)
{
	if ((*lst)->content > (*lst)->next->content)
	{
		ft_printf("s%s\n", lst_name);
		swap_first_two(lst);
		rotate_list(lst, lst_name);
		return (1);
	}
	rotate_list(lst, lst_name);
	return (0);
}
