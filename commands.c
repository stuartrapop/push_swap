/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:57 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/10 14:53:45 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

void	ft_add_number(t_num_list *list, int new_number)
{
	int	index;

	index = list->number_elements;
	while (index > 0)
	{
		list->position[index] = list->position[index - 1];
		index--;
	}
	list->position[0] = new_number;
	list->number_elements++;
	ft_get_list_stats(list);
}

int	ft_remove_number(t_num_list *list)
{
	int	index;
	int	tmp;

	index = 0;
	tmp = list->position[0];
	while (index < list->number_elements - 1)
	{
		list->position[index] = list->position[index + 1];
		index++;
	}
	list->number_elements--;
	ft_get_list_stats(list);
	return (tmp);
}

void	ft_push(t_num_list *list1, t_num_list *list2)
{
	if (list1 == NULL || list2 == NULL)
		return ;
	if (list1->number_elements < 1)
		return ;
	ft_add_number(list2, ft_remove_number(list1));
	ft_printf("p%c\n", list2->identifier);
}

void	ft_rotate_elements(t_num_list *list, int show_instruction)
{
	int	tmp;
	int	index;

	index = 0;
	if ((*list).number_elements == 0 || (*list).position == NULL)
		return ;
	tmp = (*list).position[0];
	while (index < (*list).number_elements - 1)
	{
		(*list).position[index] = (*list).position[index + 1];
		index++;
	}
	(*list).position[(*list).number_elements - 1] = tmp;
	if (show_instruction)
		ft_printf("r%c\n", (*list).identifier);
}

void	ft_reverse_rotate_elements(t_num_list *list, int show_instruction)
{
	int	tmp;
	int	index;

	if ((*list).number_elements == 0 || (*list).position == NULL)
		return ;
	tmp = (*list).position[(*list).number_elements - 1];
	index = (*list).number_elements - 1;
	while (index > 0)
	{
		(*list).position[index] = (*list).position[index - 1];
		index--;
	}
	(*list).position[0] = tmp;
	if (show_instruction)
		ft_printf("rr%c\n", (*list).identifier);
}
