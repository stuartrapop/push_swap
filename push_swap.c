/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:57 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/06 17:39:00 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

void	ft_get_list_stats(t_num_list *list)
{
	int	min;
	int	max;
	int	index;

	if ((*list).number_elements == 0 || (*list).elements == NULL)
		return ;
	index = 0;
	min = (*list).elements[0];
	max = (*list).elements[0];
	while (index < (*list).number_elements)
	{
		if (min > (*list).elements[index])
			min = (*list).elements[index];
		if (max < (*list).elements[index])
			max = (*list).elements[index];
		index++;
	}
	(*list).max_value = max;
	(*list).min_value = min;
}

void	ft_add_number(t_num_list *list, int new_number)
{
	int	index;

	index = list->number_elements;
	while (index > 0)
	{
		list->elements[index] = list->elements[index - 1];
		index--;
	}
	list->elements[0] = new_number;
	list->number_elements++;
	ft_get_list_stats(list);
}

int	ft_remove_number(t_num_list *list)
{
	int	index;
	int	tmp;

	index = 0;
	tmp = list->elements[0];
	while (index < list->number_elements - 1)
	{
		list->elements[index] = list->elements[index + 1];
		index++;
	}
	list->number_elements--;
	ft_get_list_stats(list);
	ft_printf("remove number %d\n", tmp);
	return (tmp);
}

void	ft_push(t_num_list *list1, t_num_list *list2)
{
	if (list1 == NULL || list2 == NULL)
		return ;
	if (list1->number_elements < 1)
		return ;
	ft_add_number(list2, ft_remove_number(list1));
}

void	ft_rotate_elements(t_num_list *list, int show_instruction)
{
	int	tmp;
	int	index;

	index = 0;
	if ((*list).number_elements == 0 || (*list).elements == NULL)
		return ;
	tmp = (*list).elements[0];
	while (index < (*list).number_elements - 1)
	{
		(*list).elements[index] = (*list).elements[index + 1];
		index++;
	}
	(*list).elements[(*list).number_elements - 1] = tmp;
	if (show_instruction)
		ft_printf("r%c\n", (*list).identifier);
}

void	ft_rotate_both(t_num_list *list1, t_num_list *list2)
{
	ft_rotate_elements(list1, 0);
	ft_rotate_elements(list2, 0);
	ft_printf("rr\n");
}

void	ft_reverse_rotate_elements(t_num_list *list, int show_instruction)
{
	int	tmp;
	int	index;

	if ((*list).number_elements == 0 || (*list).elements == NULL)
		return ;
	tmp = (*list).elements[(*list).number_elements - 1];
	index = (*list).number_elements - 1;
	while (index > 0)
	{
		(*list).elements[index] = (*list).elements[index - 1];
		index--;
	}
	(*list).elements[0] = tmp;
	if (show_instruction)
		ft_printf("rr%c\n", (*list).identifier);
}

void	ft_reverse_rotate_both(t_num_list *list1, t_num_list *list2)
{
	ft_reverse_rotate_elements(list1, 0);
	ft_reverse_rotate_elements(list2, 0);
	ft_printf("rrr\n");
}

void	ft_swap_first_2(t_num_list *list)
{
	int	tmp;

	if (list == NULL)
		return ;
	if (list->number_elements < 2)
		return ;
	tmp = list->elements[0];
	list->elements[0] = list->elements[1];
	list->elements[1] = tmp;
	ft_printf("s%c\n", list->identifier);
}

void	ft_sort_less_3(t_num_list *list)
{
	if (list->elements[0] == list->max_value)
		ft_rotate_elements(list, 1);
	if (is_sorted_list(list->elements, list->number_elements))
		return ;
	if (list->elements[1] == list->max_value)
		ft_reverse_rotate_elements(list, 1);
	if (is_sorted_list(list->elements, list->number_elements))
		return ;
	ft_swap_first_2(list);
}

void ft_merge(t_num_list *lista, t_num_list *listb)
{
	int	rotate_count;
	int	initial_lista_count;

	rotate_count = 0;
	initial_lista_count = lista->number_elements;
	while (listb->number_elements != 0)
	{
		if (lista->elements[0] < listb->elements[0] && rotate_count < initial_lista_count)
		{
			ft_rotate_elements(lista, 1);
			rotate_count++;
		} 
		else 
		{
			ft_push(listb, lista);
			ft_rotate_elements(lista, 1);
		}	
	}
	while (lista->elements[0] != lista->min_value)
		ft_rotate_elements(lista, 1);
}

int	ft_read_elements(t_num_list *lista, t_num_list *listb, \
		int argc, char *argv[])
{
	int	index;

	(*lista).elements = malloc(sizeof(int) * argc);
	if (!((*lista).elements))
		return (0);
	(*listb).elements = malloc(sizeof(int) * argc);
	if (!((*listb).elements))
		return (0);
	(*lista).identifier = 'a';
	listb->identifier = 'b';
	(*lista).number_elements = argc - 1;
	listb->number_elements = 0;
	index = argc;
	while (index > 1)
	{
		(*lista).elements[index - 2] = ft_atoi(argv[index - 1]);
		index--;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_num_list	lista;
	t_num_list	listb;
	int			index;

	if (argc < 2)
		return (0);
	if (!valid_arguments(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	lista.elements = NULL;
	
	ft_read_elements(&lista, &listb, argc, argv);
	ft_get_list_stats(&lista);
	if (is_sorted_list(lista.elements, lista.number_elements))
		return (1);
	index = 0;
	while (index < argc / 2)
	{
		ft_push(&lista, &listb);
		index++;
	}
	ft_sort_less_3(&lista);
	ft_sort_less_3(&listb);
	ft_merge(&lista, &listb);

	ft_printf("after merge\n");
	ft_print_list(lista);
	ft_printf("list b\n");
	ft_print_list(listb);
		return (1);
	
	
	// ft_print_list(lista.elements, lista.number_elements);
	// ft_reverse_rotate_elements(&lista, 1);
	// ft_print_list(lista.elements, lista.number_elements);
}
