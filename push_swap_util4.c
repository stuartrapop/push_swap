/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 09:02:58 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/04 14:06:49 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include "push_swap.h"
#include <stdlib.h>

void	ft_compare_swap(t_node **lst, char *lst_name, int *modified)
{
	if ((*lst)->content > (*lst)->next->content)
	{
		ft_printf("s%s\n", lst_name);
		swap_first_two(lst);
		*modified = 1;
	}
}

int	ft_compare_swap_rotate(t_node **lst, char *lst_name, char *direction, \
			int num_sorted)
{
	int	index;
	int	modified;

	modified = 0;
	index = num_sorted;
	while (index < (ft_count_elements(*lst) -1 - num_sorted))
	{
		if (ft_strncmp("greater", direction, 5) == 0)
		{
			ft_compare_swap(lst, lst_name, &modified);
			rotate_list(lst, lst_name);	
		}
		else
		{
			rotate_reverse_list(lst, lst_name);
			ft_compare_swap(lst, lst_name, &modified);
		}
		index++;
	}
		ft_printf(" number %d\n", num_sorted +1);
		ft_print_list(*lst);
	return (modified);
}
