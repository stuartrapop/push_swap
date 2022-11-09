/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:57 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/09 21:18:42 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

void	ft_make_sort_list(t_num_list *lista)
{
	int	index1;
	int	index2;
	int	tmp;

	if ((*lista).number_elements == 0)
		return ;
	index1 = 0;
	while (index1 < lista->number_elements - 1)
	{
		index2 = index1 + 1;
		while (index2 < lista->number_elements)
		{
			if (lista->sort_lst[index1] > lista->sort_lst[index2])
			{
				tmp = lista->sort_lst[index1];
				lista->sort_lst[index1] = lista->sort_lst[index2];
				lista->sort_lst[index2] = tmp;
			}
			index2++;
		}
		index1++;
	}
}

void	ft_make_position_list(t_num_list *lista, t_num_list *listb)
{
	int	index1;
	int	index2;

	if ((*lista).number_elements == 0 || (*lista).sort_lst == NULL)
		return ;
	lista->position = malloc(sizeof(int) * lista->number_elements);
	if (lista->position == NULL)
		return ;
	listb->position = malloc(sizeof(int) * lista->number_elements);
	if (listb->position == NULL)
		return ;
	index1 = 0;
	while (index1 < lista->number_elements)
	{
		index2 = 0;
		while (index2 < lista->number_elements)
		{
			if (lista->elements[index1] == lista->sort_lst[index2])
			{
				lista->position[index1] = index2 + 1;
			}
			index2++;
		}
		index1++;
	}
}

void	ft_get_list_stats(t_num_list *list)
{
	int	min;
	int	max;
	int	index;

	if ((*list).number_elements == 0 || (*list).elements == NULL)
		return ;
	index = 0;
	min = (*list).position[0];
	max = (*list).position[0];
	while (index < (*list).number_elements)
	{
		if (min > (*list).position[index])
			min = (*list).position[index];
		if (max < (*list).position[index])
			max = (*list).position[index];
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

void	ft_reverse_rotate_both(t_num_list *list1, t_num_list *list2)
{
	ft_reverse_rotate_elements(list1, 0);
	ft_reverse_rotate_elements(list2, 0);
	ft_printf("rrr\n");
}

void	ft_swap_first_2(t_num_list *list, int show_instruction)
{
	int	tmp;

	if (list == NULL)
		return ;
	if (list->number_elements < 2)
		return ;
	tmp = list->position[0];
	list->position[0] = list->position[1];
	list->position[1] = tmp;
	if (show_instruction)
		ft_printf("s%c\n", list->identifier);
}

void	ft_sort_less_3(t_num_list *list)
{
	if (list->identifier == 'a')
	{
		if (list->position[0] == list->max_value)
			ft_rotate_elements(list, 1);
		if (is_sorted_list(list->position, list->number_elements, 'a'))
			return ;
		if (list->position[1] == list->max_value)
			ft_reverse_rotate_elements(list, 1);
		if (is_sorted_list(list->position, list->number_elements, 'a'))
			return ;
		ft_swap_first_2(list, 1);
		return ;
	}
	if (list->position[0] == list->min_value)
		ft_rotate_elements(list, 1);
	if (is_sorted_list(list->position, list->number_elements, 'd'))
		return ;
	if (list->position[1] == list->min_value)
		ft_reverse_rotate_elements(list, 1);
	if (is_sorted_list(list->position, list->number_elements, 'd'))
		return ;
	ft_swap_first_2(list, 1);
}



void ft_merge(t_num_list *lista, t_num_list *listb)
{
	while (listb->number_elements != 0)
		ft_push(listb, lista);
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
	(*lista).sort_lst = malloc(sizeof(int) * argc);
	if (!((*lista).sort_lst))
		return (0);
	(*lista).identifier = 'a';
	listb->identifier = 'b';
	(*lista).number_elements = argc - 1;
	listb->number_elements = 0;
	index = argc;
	while (index > 1)
	{
		(*lista).elements[index - 2] = ft_atoi(argv[index - 1]);
		lista->sort_lst[index - 2] = lista->elements[index - 2];
		index--;
	}
	return (1);
}

int ft_none_left(t_num_list list, int start, int end)
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

void	ft_bit_sort(t_num_list *lista, t_num_list *listb)
{
	int	index;
	int	tot_elements;
	int	column;
	int	bit_shifted;

	column = 0 ;
	tot_elements = lista->number_elements;
	while (1)
	{
		index = 0;
		while (index < tot_elements)
		{
			bit_shifted = lista->position[0];
			bit_shifted = bit_shifted >> column & 1;
			if (!(bit_shifted))
				ft_push(lista, listb);
			else
				ft_rotate_elements(lista, 1);
			index++;
		}
		ft_merge(lista, listb);
		if (is_sorted_list(lista->position, lista->number_elements, 'a'))
			return ;
		column++;
	}
}

void ft_sort_few(t_num_list *lista, t_num_list *listb)
{
	int tot_elements;
	{
		tot_elements = lista->number_elements;
		while (!ft_none_left(*lista, 0, tot_elements / 2))
		{
			if (lista->position[0] <= tot_elements / 2)
				ft_push(lista, listb);
			else
				ft_rotate_elements(lista, 1);
		}
		ft_sort_less_3(lista);
		ft_sort_less_3(listb);
		ft_print_list(lista->position, lista->number_elements);
		ft_printf("list b\n");
		ft_print_list(listb->position, listb->number_elements);
		ft_merge(lista, listb);
		ft_printf("after merge b\n");
		ft_print_list(lista->position, lista->number_elements);
		ft_printf("list b\n");
		ft_print_list(listb->position, listb->number_elements);
	}
}

int	main(int argc, char *argv[])
{
	t_num_list	lista;
	t_num_list	listb;

	if (argc < 2)
		return (0);
	if (!valid_arguments(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_read_elements(&lista, &listb, argc, argv);
	ft_make_sort_list(&lista);
	ft_make_position_list(&lista, &listb);
	ft_get_list_stats(&lista);
	if (is_sorted_list(lista.position, lista.number_elements, 'a'))
		return (1);
	if (lista.number_elements <= 6)
	{
		ft_sort_few(&lista, &listb);
		return (1);
	}
	ft_bit_sort(&lista, &listb);
	// ft_print_list(lista.position, lista.number_elements);
	return (1);
}
