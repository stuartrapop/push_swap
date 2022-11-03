/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 09:02:58 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/03 15:20:05 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include "push_swap.h"
#include <stdlib.h>

void	ft_add_back(t_node **lst, t_node *new)
{
	t_node	*current;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		(*lst) = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

void	ft_add_front(t_node **lst, t_node *new)
{
	t_node	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	temp = (*lst);
	(*lst) = new;
	new->next = temp;
}

void	rotate_list(t_node **lst, char *lst_name)
{
	t_node	*item_to_append;

	ft_printf("r%s\n", lst_name);
	item_to_append = ft_remove_and_return_first(lst);
	if (item_to_append == NULL)
		return ;
	ft_add_back(lst, item_to_append);
}

void	rotate_reverse_list(t_node **lst, char *lst_name)
{
	t_node	*item_to_append;

	ft_printf("rr%s\n", lst_name);
	item_to_append = ft_remove_and_return_last(lst);
	if (item_to_append == NULL)
		return ;
	ft_add_front(lst, item_to_append);
}

void	ft_delete_lst(t_node **lst)
{
	t_node	*node_to_delete;

	if (lst == NULL)
		return ;
	while ((*lst) != NULL)
	{
		node_to_delete = *lst;
		*lst = (*lst)->next;
		free(node_to_delete);
	}
	free(*lst);
}
