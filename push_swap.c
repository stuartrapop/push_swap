/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:57 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/10 17:51:48 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

int	ft_build_list(t_num_list *lista, t_num_list *listb, \
		int num_elements, char *str_array[])
{
	int	index;

	(*lista).elements = malloc(sizeof(int) * num_elements);
	if (!((*lista).elements))
		return (0);
	(*listb).elements = malloc(sizeof(int) * num_elements);
	if (!((*listb).elements))
		return (0);
	(*lista).sort_lst = malloc(sizeof(int) * num_elements);
	if (!((*lista).sort_lst))
		return (0);
	(*lista).identifier = 'a';
	listb->identifier = 'b';
	(*lista).number_elements = num_elements;
	listb->number_elements = 0;
	index = num_elements - 1;
	while (index >= 0)
	{
		(*lista).elements[index] = ft_atoi(str_array[index]);
		lista->sort_lst[index] = lista->elements[index];
		index--;
	}
	return (1);
}

char	**ft_make_arg_list(int argc, char *argv[])
{
	int		index;
	char	**new_array;

	new_array = malloc(sizeof(char *) * (argc - 1 + 1));
	if (!new_array)
		return (NULL);
	index = 0;
	while (index < argc)
	{
		new_array[index - 1] = ft_strdup(argv[index]);
		index++;
	}
	new_array[index] = NULL;
	return (new_array);
}

int	ft_error(void)
{
	ft_printf("Error\n");
	return (0);
}

int	ft_push_swap(char ***str_args, int num_elements)
{
	t_num_list	lista;
	t_num_list	listb;

	if (!valid_arguments(num_elements, *str_args))
	{
		delete_str_args(str_args, num_elements);
		return (ft_error());
	}
	ft_clean_lists(&lista, &listb);
	ft_build_list(&lista, &listb, num_elements, *str_args);
	ft_make_sort_list(&lista);
	ft_make_position_list(&lista, &listb);
	ft_get_list_stats(&lista);
	if (!is_sorted_list(lista.position, lista.number_elements, 'a'))
	{
		if (lista.number_elements <= 6)
			ft_sort_few(&lista, &listb);
		else
			ft_radix_2(&lista, &listb);
	}
	delete_list(&lista);
	delete_list(&listb);
	delete_str_args(str_args, num_elements);
	return (1);
}

int	main(int argc, char *argv[])
{
	char		**str_args;
	int			num_elements;

	if (argc < 2)
		return (0);
	num_elements = 0;
	if (has_space(argv[1]))
	{
		if (argc > 2)
			return (ft_error());
		str_args = ft_split(argv[1], ' ');
		while (str_args[num_elements] != NULL)
			num_elements++;
	}
	else
	{
		str_args = ft_make_arg_list(argc, argv);
		while (str_args[num_elements] != NULL)
			num_elements++;
	}
	ft_push_swap(&str_args, num_elements);
}
