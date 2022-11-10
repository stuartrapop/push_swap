/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:57 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/10 17:51:34 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

void	ft_clean_lists(t_num_list *lista, t_num_list *listb)
{
	lista->elements = NULL;
	lista->position = NULL;
	lista->sort_lst = NULL;
	listb->elements = NULL;
	listb->position = NULL;
	listb->sort_lst = NULL;
}

void	delete_list(t_num_list *list)
{
	if (list->elements != NULL)
		free(list->elements);
	if (list->position != NULL)
		free(list->position);
	if (list->sort_lst != NULL)
		free(list->sort_lst);
}

void	delete_str_args(char ***str_args, int num_elements)
{
	int	index;

	index = 0;
	while (index < num_elements)
	{
		free((*str_args)[index]);
		index++;
	}
	free(*str_args);
}

int	ft_none_left(t_num_list list, int start, int end)
{
	int	index;

	index = 0;
	while (index < list.number_elements)
	{
		if (list.position[index] >= start && list.position[index] <= end)
			return (0);
		index++;
	}
	return (1);
}

int	has_space(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == ' ')
			return (1);
		index++;
	}
	return (0);
}
